const std = @import("std");
const Allocator = std.mem.Allocator;
const Target = std.Target;
const Object = @import("../Object.zig");

const Section = struct {
    data: std.ArrayList(u8) = .empty,
    relocations: std.ArrayList(Relocation) = .empty,
    flags: u64,
    type: u32,
    index: u16 = undefined,
};

const Symbol = struct {
    section: ?*Section,
    size: u64,
    offset: u64,
    index: u16 = undefined,
    info: u8,
};

const Relocation = struct {
    symbol: *Symbol,
    addend: i64,
    offset: u48,
    type: u8,
};

const additional_sections = 3; // null section, strtab, symtab
const strtab_index = 1;
const symtab_index = 2;
const strtab_default = "\x00.strtab\x00.symtab\x00";
const strtab_name = 1;
const symtab_name = "\x00.strtab\x00".len;

const Elf = @This();

obj: Object,
/// The keys are owned by the Codegen.tree
sections: std.StringHashMapUnmanaged(*Section) = .empty,
local_symbols: std.StringHashMapUnmanaged(*Symbol) = .empty,
global_symbols: std.StringHashMapUnmanaged(*Symbol) = .empty,
unnamed_symbol_mangle: u32 = 0,
strtab_len: u64 = strtab_default.len,
arena: std.heap.ArenaAllocator,

pub fn create(gpa: Allocator, target: Target) !*Object {
    const elf = try gpa.create(Elf);
    elf.* = .{
        .obj = .{ .format = .elf, .target = target },
        .arena = std.heap.ArenaAllocator.init(gpa),
    };
    return &elf.obj;
}

pub fn deinit(elf: *Elf) void {
    const gpa = elf.arena.child_allocator;
    {
        var it = elf.sections.valueIterator();
        while (it.next()) |sect| {
            sect.*.data.deinit(gpa);
            sect.*.relocations.deinit(gpa);
        }
    }
    elf.sections.deinit(gpa);
    elf.local_symbols.deinit(gpa);
    elf.global_symbols.deinit(gpa);
    elf.arena.deinit();
    gpa.destroy(elf);
}

fn sectionString(sec: Object.Section) []const u8 {
    return switch (sec) {
        .undefined => unreachable,
        .data => "data",
        .read_only_data => "rodata",
        .func => "text",
        .strings => "rodata.str",
        .custom => |name| name,
    };
}

pub fn getSection(elf: *Elf, section_kind: Object.Section) !*std.ArrayList(u8) {
    const section_name = sectionString(section_kind);
    const section = elf.sections.get(section_name) orelse blk: {
        const section = try elf.arena.allocator().create(Section);
        section.* = .{
            .data = std.ArrayList(u8).init(elf.arena.child_allocator),
            .type = std.elf.SHT_PROGBITS,
            .flags = switch (section_kind) {
                .func, .custom => std.elf.SHF_ALLOC + std.elf.SHF_EXECINSTR,
                .strings => std.elf.SHF_ALLOC + std.elf.SHF_MERGE + std.elf.SHF_STRINGS,
                .read_only_data => std.elf.SHF_ALLOC,
                .data => std.elf.SHF_ALLOC + std.elf.SHF_WRITE,
                .undefined => unreachable,
            },
        };
        try elf.sections.putNoClobber(elf.arena.child_allocator, section_name, section);
        elf.strtab_len += section_name.len + ".\x00".len;
        break :blk section;
    };
    return &section.data;
}

pub fn declareSymbol(
    elf: *Elf,
    section_kind: Object.Section,
    maybe_name: ?[]const u8,
    linkage: std.builtin.GlobalLinkage,
    @"type": Object.SymbolType,
    offset: u64,
    size: u64,
) ![]const u8 {
    const section = blk: {
        if (section_kind == .undefined) break :blk null;
        const section_name = sectionString(section_kind);
        break :blk elf.sections.get(section_name);
    };
    const binding: u8 = switch (linkage) {
        .Internal => std.elf.STB_LOCAL,
        .Strong => std.elf.STB_GLOBAL,
        .Weak => std.elf.STB_WEAK,
        .LinkOnce => unreachable,
    };
    const sym_type: u8 = switch (@"type") {
        .func => std.elf.STT_FUNC,
        .variable => std.elf.STT_OBJECT,
        .external => std.elf.STT_NOTYPE,
    };
    const name = if (maybe_name) |some| some else blk: {
        defer elf.unnamed_symbol_mangle += 1;
        break :blk try std.fmt.allocPrint(elf.arena.allocator(), ".L.{d}", .{elf.unnamed_symbol_mangle});
    };

    const gop = if (linkage == .Internal)
        try elf.local_symbols.getOrPut(elf.arena.child_allocator, name)
    else
        try elf.global_symbols.getOrPut(elf.arena.child_allocator, name);

    if (!gop.found_existing) {
        gop.value_ptr.* = try elf.arena.allocator().create(Symbol);
        elf.strtab_len += name.len + 1; // +1 for null byte
    }
    gop.value_ptr.*.* = .{
        .section = section,
        .size = size,
        .offset = offset,
        .info = (binding << 4) + sym_type,
    };
    return name;
}

pub fn addRelocation(elf: *Elf, name: []const u8, section_kind: Object.Section, address: u64, addend: i64) !void {
    const section_name = sectionString(section_kind);
    const symbol = elf.local_symbols.get(name) orelse elf.global_symbols.get(name).?; // reference to undeclared symbol
    const section = elf.sections.get(section_name).?;
    if (section.relocations.items.len == 0) elf.strtab_len += ".rela".len;

    try section.relocations.append(elf.arena.child_allocator, .{
        .symbol = symbol,
        .offset = @intCast(address),
        .addend = addend,
        .type = if (symbol.section == null) 4 else 2, // TODO
    });
}

/// elf header
/// sections contents
/// symbols
/// relocations
/// strtab
/// section headers
pub fn finish(elf: *Elf, w: *std.Io.Writer) !void {
    var num_sections: std.elf.Half = additional_sections;
    var relocations_len: std.elf.Elf64.Off = 0;
    var sections_len: std.elf.Elf64.Off = 0;
    {
        var it = elf.sections.valueIterator();
        while (it.next()) |sect| {
            sections_len += sect.*.data.items.len;
            relocations_len += sect.*.relocations.items.len * @sizeOf(std.elf.Elf64.Rela);
            sect.*.index = num_sections;
            num_sections += 1;
            num_sections += @intFromBool(sect.*.relocations.items.len != 0);
        }
    }
    const symtab_len = (elf.local_symbols.count() + elf.global_symbols.count() + 1) * @sizeOf(std.elf.Elf64.Sym);

    const symtab_offset = @sizeOf(std.elf.Elf64.Ehdr) + sections_len;
    const symtab_offset_aligned = std.mem.alignForward(u64, symtab_offset, 8);
    const rela_offset = symtab_offset_aligned + symtab_len;
    const strtab_offset = rela_offset + relocations_len;
    const sh_offset = strtab_offset + elf.strtab_len;
    const sh_offset_aligned = std.mem.alignForward(u64, sh_offset, 16);
    const endian = elf.obj.target.cpu.arch.endian();

    const elf_header: std.elf.Elf64.Ehdr = .{
        .ident = .{
            .magic = .{ 0x7F, 'E', 'L', 'F' },
            .class = .@"64",
            .data = .@"2LSB",
            .version = 1,
            .osabi = .NONE,
            .abiversion = 0,
        },
        .type = .REL, // we only produce relocatables
        .machine = elf.obj.target.toElfMachine(),
        .version = 1,
        .entry = 0, // linker will handle this
        .phoff = 0, // no program header
        .shoff = sh_offset_aligned, // section headers offset
        .flags = 0, // no flags
        .ehsize = @sizeOf(std.elf.Elf64.Ehdr),
        .phentsize = 0, // no program header
        .phnum = 0, // no program header
        .shentsize = @sizeOf(std.elf.Elf64.Shdr),
        .shnum = num_sections,
        .shstrndx = strtab_index,
    };
    try w.writeStruct(elf_header, endian);

    // write contents of sections
    {
        var it = elf.sections.valueIterator();
        while (it.next()) |sect| try w.writeAll(sect.*.data.items);
    }

    // pad to 8 bytes
    try w.splatByteAll(0, @intCast(symtab_offset_aligned - symtab_offset));

    var name_offset: u32 = strtab_default.len;
    // write symbols
    {
        // first symbol must be null
        try w.writeStruct(std.mem.zeroes(std.elf.Elf64.Sym), endian);

        var sym_index: u16 = 1;
        var it = elf.local_symbols.iterator();
        while (it.next()) |entry| {
            const sym = entry.value_ptr.*;
            try w.writeStruct(std.elf.Elf64.Sym{
                .name = name_offset,
                .info = @bitCast(sym.info),
                .other = .{ .visibility = .DEFAULT },
                .shndx = if (sym.section) |some| some.index else 0,
                .value = sym.offset,
                .size = sym.size,
            }, endian);
            sym.index = sym_index;
            sym_index += 1;
            name_offset += @intCast(entry.key_ptr.len + 1); // +1 for null byte
        }
        it = elf.global_symbols.iterator();
        while (it.next()) |entry| {
            const sym = entry.value_ptr.*;
            try w.writeStruct(std.elf.Elf64.Sym{
                .name = name_offset,
                .info = @bitCast(sym.info),
                .other = .{ .visibility = .DEFAULT },
                .shndx = if (sym.section) |some| some.index else 0,
                .value = sym.offset,
                .size = sym.size,
            }, endian);
            sym.index = sym_index;
            sym_index += 1;
            name_offset += @intCast(entry.key_ptr.len + 1); // +1 for null byte
        }
    }

    // write relocations
    {
        var it = elf.sections.valueIterator();
        while (it.next()) |sect| {
            for (sect.*.relocations.items) |rela| {
                try w.writeStruct(std.elf.Elf64.Rela{
                    .offset = rela.offset,
                    .addend = rela.addend,
                    .info = .{
                        .type = rela.type,
                        .sym = rela.symbol.index,
                    },
                }, endian);
            }
        }
    }

    // write strtab
    try w.writeAll(strtab_default);
    {
        var it = elf.local_symbols.keyIterator();
        while (it.next()) |key| try w.print("{s}\x00", .{key.*});
        it = elf.global_symbols.keyIterator();
        while (it.next()) |key| try w.print("{s}\x00", .{key.*});
    }
    {
        var it = elf.sections.iterator();
        while (it.next()) |entry| {
            if (entry.value_ptr.*.relocations.items.len != 0) try w.writeAll(".rela");
            try w.print(".{s}\x00", .{entry.key_ptr.*});
        }
    }

    // pad to 16 bytes
    try w.splatByteAll(0, @intCast(sh_offset_aligned - sh_offset));
    // mandatory null header
    try w.writeStruct(std.mem.zeroes(std.elf.Elf64.Shdr), endian);

    // write strtab section header
    {
        const sect_header: std.elf.Elf64.Shdr = .{
            .name = strtab_name,
            .type = .STRTAB,
            .flags = .{ .shf = .{} },
            .addr = 0,
            .offset = strtab_offset,
            .size = elf.strtab_len,
            .link = 0,
            .info = 0,
            .addralign = 1,
            .entsize = 0,
        };
        try w.writeStruct(sect_header, endian);
    }

    // write symtab section header
    {
        const sect_header: std.elf.Elf64.Shdr = .{
            .name = symtab_name,
            .type = .SYMTAB,
            .flags = .{ .shf = .{} },
            .addr = 0,
            .offset = symtab_offset_aligned,
            .size = symtab_len,
            .link = strtab_index,
            .info = elf.local_symbols.size + 1,
            .addralign = 8,
            .entsize = @sizeOf(std.elf.Elf64.Sym),
        };
        try w.writeStruct(sect_header, endian);
    }

    // remaining section headers
    {
        var sect_offset: u64 = @sizeOf(std.elf.Elf64.Ehdr);
        var rela_sect_offset: u64 = rela_offset;
        var it = elf.sections.iterator();
        while (it.next()) |entry| {
            const sect = entry.value_ptr.*;
            const rela_count = sect.relocations.items.len;
            const rela_name_offset: u32 = if (rela_count != 0) @truncate(".rela".len) else 0;
            try w.writeStruct(std.elf.Elf64.Shdr{
                .name = rela_name_offset + name_offset,
                .type = @enumFromInt(sect.type),
                .flags = @bitCast(sect.flags),
                .addr = 0,
                .offset = sect_offset,
                .size = sect.data.items.len,
                .link = 0,
                .info = 0,
                .addralign = if (sect.flags & std.elf.SHF_EXECINSTR != 0) 16 else 1,
                .entsize = 0,
            }, endian);

            if (rela_count != 0) {
                const size = rela_count * @sizeOf(std.elf.Elf64.Rela);
                try w.writeStruct(std.elf.Elf64.Shdr{
                    .name = name_offset,
                    .type = .RELA,
                    .flags = .{ .shf = .{} },
                    .addr = 0,
                    .offset = rela_sect_offset,
                    .size = rela_count * @sizeOf(std.elf.Elf64.Rela),
                    .link = symtab_index,
                    .info = sect.index,
                    .addralign = 8,
                    .entsize = @sizeOf(std.elf.Elf64.Rela),
                }, endian);
                rela_sect_offset += size;
            }

            sect_offset += sect.data.items.len;
            name_offset += @as(u32, @intCast(entry.key_ptr.len + ".\x00".len)) + rela_name_offset;
        }
    }
    try w.flush();
}
