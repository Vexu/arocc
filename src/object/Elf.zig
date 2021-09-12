const std = @import("std");
const Compilation = @import("../Compilation.zig");
const Object = @import("../Object.zig");

const Elf = @This();

const Section = struct {
    data: std.ArrayListUnmanaged(u8) = .{},
    name_offset: std.elf.Elf64_Word,
    type: std.elf.Elf64_Word,
    flags: std.elf.Elf64_Xword,
};

const additional_sections = 3; // null section, strtab, symtab
const strtab_default = "\x00.strtab\x00.symtab\x00";
const strtab_name = 1;
const symtab_name = "\x00.strtab\x00".len;

obj: Object,
/// The keys are owned by the Codegen.tree
sections: std.StringArrayHashMap(Section),
symtab: std.ArrayList(std.elf.Elf64_Sym),
strtab: std.ArrayList(u8),
first_global: std.elf.Elf64_Word = 0,
unnamed_symbol_mangle: u32 = 0,

pub fn create(comp: *Compilation) !*Object {
    var strtab = std.ArrayList(u8).init(comp.gpa);
    errdefer strtab.deinit();

    try strtab.appendSlice(strtab_default);

    var symtab = std.ArrayList(std.elf.Elf64_Sym).init(comp.gpa);
    errdefer symtab.deinit();

    try symtab.append(std.mem.zeroes(std.elf.Elf64_Sym));

    const elf = try comp.gpa.create(Elf);
    elf.* = .{
        .obj = .{ .format = .elf, .comp = comp },
        .sections = std.StringArrayHashMap(Section).init(comp.gpa),
        .symtab = symtab,
        .strtab = strtab,
    };
    return &elf.obj;
}

pub fn deinit(elf: *Elf) void {
    const gpa = elf.sections.allocator;
    for (elf.sections.values()) |*sect| sect.data.deinit(gpa);
    elf.sections.deinit();
    elf.symtab.deinit();
    elf.strtab.deinit();
    gpa.destroy(elf);
}

fn sectionString(sec: Object.Section) []const u8 {
    return switch (sec) {
        .data => "data",
        .read_only_data => "rodata",
        .func => "text",
        .strings => "rodata.str",
        .custom => |name| name,
    };
}

pub fn getSection(elf: *Elf, section: Object.Section) !*std.ArrayListUnmanaged(u8) {
    const section_name = sectionString(section);
    const section_idx = elf.sections.getIndex(section_name) orelse blk: {
        const idx = elf.sections.count();
        try elf.sections.putNoClobber(section_name, .{
            .name_offset = @truncate(std.elf.Elf64_Word, elf.strtab.items.len),
            .type = std.elf.SHT_PROGBITS,
            .flags = switch (section) {
                .func, .custom => std.elf.SHF_ALLOC + std.elf.SHF_EXECINSTR,
                .strings => std.elf.SHF_ALLOC + std.elf.SHF_MERGE + std.elf.SHF_STRINGS,
                .read_only_data => std.elf.SHF_ALLOC,
                .data => std.elf.SHF_ALLOC + std.elf.SHF_WRITE,
            },
        });
        try elf.strtab.writer().print(".{s}\x00", .{section_name});
        break :blk idx;
    };
    return &elf.sections.values()[section_idx].data;
}

pub fn declareSymbol(
    elf: *Elf,
    section: Object.Section,
    name: ?[]const u8,
    linkage: std.builtin.GlobalLinkage,
    @"type": Object.SymbolType,
    offset: u64,
    size: u64,
) ![]const u8 {
    const section_name = sectionString(section);
    const sect_idx = @truncate(std.elf.Elf64_Half, elf.sections.getIndex(section_name).?);
    const binding: u8 = switch (linkage) {
        .Internal => std.elf.STB_LOCAL,
        .Strong => std.elf.STB_GLOBAL,
        .Weak => std.elf.STB_WEAK,
        .LinkOnce => unreachable,
    };
    const sym_type: u8 = switch (@"type") {
        .func => std.elf.STT_FUNC,
        .variable => std.elf.STT_OBJECT,
    };
    var sym = std.elf.Elf64_Sym{
        .st_name = @truncate(std.elf.Elf64_Word, elf.strtab.items.len),
        .st_info = (binding << 4) + sym_type,
        .st_other = 0,
        .st_shndx = sect_idx + additional_sections,
        .st_value = offset,
        .st_size = size,
    };
    if (elf.first_global == 0 and linkage == .Strong)
        elf.first_global = @truncate(std.elf.Elf64_Word, elf.symtab.items.len);

    if (name) |some| {
        try elf.strtab.writer().print("{s}\x00", .{some});
    } else {
        try elf.strtab.writer().print(".L.{d}\x00", .{elf.unnamed_symbol_mangle});
        elf.unnamed_symbol_mangle += 1;
    }
    try elf.symtab.append(sym);
    return elf.strtab.items[sym.st_name..];
}

pub fn finish(elf: *Elf, file: std.fs.File) !void {
    var buf_writer = std.io.bufferedWriter(file.writer());
    const w = buf_writer.writer();

    const strtab_index = 1;

    const sections_len = blk: {
        var len: std.elf.Elf64_Off = 0;
        for (elf.sections.values()) |sect| len += sect.data.items.len;
        break :blk len;
    };
    const strtab_len = elf.strtab.items.len;
    const symtab_len = elf.symtab.items.len * @sizeOf(std.elf.Elf64_Sym);

    const strtab_offset = @sizeOf(std.elf.Elf64_Ehdr) + sections_len;
    const symtab_offset = strtab_offset + strtab_len;
    const symtab_offset_aligned = std.mem.alignForward(symtab_offset, 8);
    const sh_offset = symtab_offset_aligned + symtab_len;
    const sh_offset_aligned = std.mem.alignForward(sh_offset, 16);

    var elf_header = std.elf.Elf64_Ehdr{
        .e_ident = .{ 0x7F, 'E', 'L', 'F', 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        .e_type = std.elf.ET.REL, // we only produce relocatables
        .e_machine = elf.obj.comp.target.cpu.arch.toElfMachine(),
        .e_version = 1,
        .e_entry = 0, // linker will handle this
        .e_phoff = 0, // no program header
        .e_shoff = sh_offset_aligned, // section headers offset
        .e_flags = 0, // no flags
        .e_ehsize = @sizeOf(std.elf.Elf64_Ehdr),
        .e_phentsize = 0, // no program header
        .e_phnum = 0, // no program header
        .e_shentsize = @sizeOf(std.elf.Elf64_Shdr),
        .e_shnum = @truncate(std.elf.Elf64_Half, elf.sections.count() + additional_sections),
        .e_shstrndx = strtab_index,
    };
    try w.writeStruct(elf_header);

    // write contents of sections
    for (elf.sections.values()) |sect| try w.writeAll(sect.data.items);
    // write strtab
    try w.writeAll(elf.strtab.items);
    // pad to 8 bytes
    try w.writeByteNTimes(0, symtab_offset_aligned - symtab_offset);
    try w.writeAll(std.mem.sliceAsBytes(elf.symtab.items));

    // pad to 16 bytes
    try w.writeByteNTimes(0, sh_offset_aligned - sh_offset);
    // mandatory null header
    try w.writeStruct(std.mem.zeroes(std.elf.Elf64_Shdr));

    // write strtab section header
    {
        var sect_header = std.elf.Elf64_Shdr{
            .sh_name = strtab_name,
            .sh_type = std.elf.SHT_STRTAB,
            .sh_flags = 0,
            .sh_addr = 0,
            .sh_offset = strtab_offset,
            .sh_size = strtab_len,
            .sh_link = 0,
            .sh_info = 0,
            .sh_addralign = 1,
            .sh_entsize = 0,
        };
        try w.writeStruct(sect_header);
    }

    // write symtab section header
    {
        var sect_header = std.elf.Elf64_Shdr{
            .sh_name = symtab_name,
            .sh_type = std.elf.SHT_SYMTAB,
            .sh_flags = 0,
            .sh_addr = 0,
            .sh_offset = symtab_offset_aligned,
            .sh_size = symtab_len,
            .sh_link = strtab_index,
            .sh_info = elf.first_global,
            .sh_addralign = 8,
            .sh_entsize = @sizeOf(std.elf.Elf64_Sym),
        };
        try w.writeStruct(sect_header);
    }

    // remaining section headers
    {
        var sect_offset: std.elf.Elf64_Addr = @sizeOf(std.elf.Elf64_Ehdr);
        for (elf.sections.values()) |sect| {
            var sect_header = std.elf.Elf64_Shdr{
                .sh_name = sect.name_offset,
                .sh_type = sect.type,
                .sh_flags = sect.flags,
                .sh_addr = 0,
                .sh_offset = sect_offset,
                .sh_size = sect.data.items.len,
                .sh_link = 0,
                .sh_info = 0,
                .sh_addralign = 16,
                .sh_entsize = 0,
            };
            try w.writeStruct(sect_header);

            sect_offset += sect.data.items.len;
        }
    }
    try buf_writer.flush();
}
