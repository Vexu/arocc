const std = @import("std");
const assert = std.debug.assert;
const mem = std.mem;
const Allocator = mem.Allocator;
const EpochSeconds = std.time.epoch.EpochSeconds;
const Builtins = @import("Builtins.zig");
const Diagnostics = @import("Diagnostics.zig");
const LangOpts = @import("LangOpts.zig");
const Source = @import("Source.zig");
const Tokenizer = @import("Tokenizer.zig");
const Token = Tokenizer.Token;
const Type = @import("Type.zig");
const Pragma = @import("Pragma.zig");
const StringInterner = @import("StringInterner.zig");

const Compilation = @This();

pub const Error = error{
    /// A fatal error has ocurred and compilation has stopped.
    FatalError,
} || Allocator.Error;

gpa: Allocator,
sources: std.StringArrayHashMap(Source),
diag: Diagnostics,
include_dirs: std.ArrayList([]const u8),
system_include_dirs: std.ArrayList([]const u8),
output_name: ?[]const u8 = null,
target: std.Target = @import("builtin").target,
pragma_handlers: std.StringArrayHashMap(*Pragma),
only_preprocess: bool = false,
only_compile: bool = false,
verbose_ast: bool = false,
langopts: LangOpts = .{},
generated_buf: std.ArrayList(u8),
builtins: Builtins = .{},
types: struct {
    wchar: Type,
    ptrdiff: Type,
    size: Type,
    va_list: Type,
} = undefined,
/// Mapping from Source.Id to byte offset of first non-utf8 byte
invalid_utf8_locs: std.AutoHashMapUnmanaged(Source.Id, u32) = .{},
string_interner: StringInterner = .{},

pub fn init(gpa: Allocator) Compilation {
    return .{
        .gpa = gpa,
        .sources = std.StringArrayHashMap(Source).init(gpa),
        .diag = Diagnostics.init(gpa),
        .include_dirs = std.ArrayList([]const u8).init(gpa),
        .system_include_dirs = std.ArrayList([]const u8).init(gpa),
        .pragma_handlers = std.StringArrayHashMap(*Pragma).init(gpa),
        .generated_buf = std.ArrayList(u8).init(gpa),
    };
}

pub fn deinit(comp: *Compilation) void {
    for (comp.pragma_handlers.values()) |pragma| {
        pragma.deinit(pragma, comp);
    }
    for (comp.sources.values()) |source| {
        comp.gpa.free(source.path);
        comp.gpa.free(source.buf);
        comp.gpa.free(source.splice_locs);
    }
    comp.sources.deinit();
    comp.diag.deinit();
    comp.include_dirs.deinit();
    for (comp.system_include_dirs.items) |path| comp.gpa.free(path);
    comp.system_include_dirs.deinit();
    comp.pragma_handlers.deinit();
    comp.generated_buf.deinit();
    comp.builtins.deinit(comp.gpa);
    comp.invalid_utf8_locs.deinit(comp.gpa);
    comp.string_interner.deinit(comp.gpa);
}

pub fn intern(comp: *Compilation, str: []const u8) !StringInterner.StringId {
    return comp.string_interner.intern(comp.gpa, str);
}

fn generateDateAndTime(w: anytype) !void {
    // TODO take timezone into account here once it is supported in Zig std
    const timestamp = std.math.clamp(std.time.timestamp(), 0, std.math.maxInt(i64));
    const epoch_seconds = EpochSeconds{ .secs = @intCast(u64, timestamp) };
    const epoch_day = epoch_seconds.getEpochDay();
    const day_seconds = epoch_seconds.getDaySeconds();
    const year_day = epoch_day.calculateYearDay();
    const month_day = year_day.calculateMonthDay();

    const month_names = [_][]const u8{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    std.debug.assert(std.time.epoch.Month.jan.numeric() == 1);

    const month_name = month_names[month_day.month.numeric() - 1];
    try w.print("#define __DATE__ \"{s} {d: >2} {d}\"\n", .{
        month_name,
        month_day.day_index + 1,
        year_day.year,
    });
    try w.print("#define __TIME__ \"{d:0>2}:{d:0>2}:{d:0>2}\"\n", .{
        day_seconds.getHoursIntoDay(),
        day_seconds.getMinutesIntoHour(),
        day_seconds.getSecondsIntoMinute(),
    });

    const day_names = [_][]const u8{ "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
    // days since Thu Oct 1 1970
    const day_name = day_names[@truncate(u8, (epoch_day.day + 3) % 7)];
    try w.print("#define __TIMESTAMP__ \"{s} {s} {d: >2} {d:0>2}:{d:0>2}:{d:0>2} {d}\"\n", .{
        day_name,
        month_name,
        month_day.day_index + 1,
        day_seconds.getHoursIntoDay(),
        day_seconds.getMinutesIntoHour(),
        day_seconds.getSecondsIntoMinute(),
        year_day.year,
    });
}

/// Generate builtin macros that will be available to each source file.
pub fn generateBuiltinMacros(comp: *Compilation) !Source {
    try comp.generateBuiltinTypes();
    comp.builtins = try Builtins.create(comp);

    var buf = std.ArrayList(u8).init(comp.gpa);
    defer buf.deinit();
    const w = buf.writer();

    // standard macros
    try w.writeAll(
        \\#define __VERSION__ "Aro 
    ++ @import("lib.zig").version_str ++ "\"\n" ++
        \\#define __Aro__
        \\#define __STDC__ 1
        \\#define __STDC_HOSTED__ 1
        \\#define __STDC_NO_ATOMICS__ 1
        \\#define __STDC_NO_COMPLEX__ 1
        \\#define __STDC_NO_THREADS__ 1
        \\#define __STDC_NO_VLA__ 1
        \\
    );
    if (comp.langopts.standard.StdCVersionMacro()) |stdc_version| {
        try w.print("#define __STDC_VERSION__ {s}\n", .{stdc_version});
    }

    // os macros
    switch (comp.target.os.tag) {
        .linux => try w.writeAll(
            \\#define linux 1
            \\#define __linux 1
            \\#define __linux__ 1
            \\
        ),
        .windows => if (comp.target.cpu.arch.ptrBitWidth() == 32) try w.writeAll(
            \\#define WIN32 1
            \\#define _WIN32 1
            \\#define __WIN32 1
            \\#define __WIN32__ 1
            \\
        ) else try w.writeAll(
            \\#define WIN32 1
            \\#define WIN64 1
            \\#define _WIN32 1
            \\#define _WIN64 1
            \\#define __WIN32 1
            \\#define __WIN64 1
            \\#define __WIN32__ 1
            \\#define __WIN64__ 1
            \\
        ),
        .freebsd => try w.print("#define __FreeBSD__ {d}\n", .{comp.target.os.version_range.semver.min.major}),
        .netbsd => try w.writeAll("#define __NetBSD__ 1\n"),
        .openbsd => try w.writeAll("#define __OpenBSD__ 1\n"),
        .dragonfly => try w.writeAll("#define __DragonFly__ 1\n"),
        .solaris => try w.writeAll(
            \\#define sun 1
            \\#define __sun 1
            \\
        ),
        .macos => try w.writeAll(
            \\#define __APPLE__ 1
            \\#define __MACH__ 1
            \\
        ),
        else => {},
    }

    // unix and other additional os macros
    switch (comp.target.os.tag) {
        .freebsd,
        .netbsd,
        .openbsd,
        .dragonfly,
        .linux,
        => try w.writeAll(
            \\#define unix 1
            \\#define __unix 1
            \\#define __unix__ 1
            \\
        ),
        else => {},
    }
    if (comp.target.abi == .android) {
        try w.writeAll("#define __ANDROID__ 1\n");
    }

    // architecture macros
    switch (comp.target.cpu.arch) {
        .x86_64 => try w.writeAll(
            \\#define __amd64__ 1
            \\#define __amd64 1
            \\#define __x86_64 1
            \\#define __x86_64__ 1
            \\
        ),
        .i386 => try w.writeAll(
            \\#define i386 1
            \\#define __i386 1
            \\#define __i386__ 1
            \\
        ),
        .mips,
        .mipsel,
        .mips64,
        .mips64el,
        => try w.writeAll(
            \\#define __mips__ 1
            \\#define mips 1
            \\
        ),
        .powerpc,
        .powerpcle,
        => try w.writeAll(
            \\#define __powerpc__ 1
            \\#define __POWERPC__ 1
            \\#define __ppc__ 1
            \\#define __PPC__ 1
            \\#define _ARCH_PPC 1
            \\
        ),
        .powerpc64,
        .powerpc64le,
        => try w.writeAll(
            \\#define __powerpc 1
            \\#define __powerpc__ 1
            \\#define __powerpc64__ 1
            \\#define __POWERPC__ 1
            \\#define __ppc__ 1
            \\#define __ppc64__ 1
            \\#define __PPC__ 1
            \\#define __PPC64__ 1
            \\#define _ARCH_PPC 1
            \\#define _ARCH_PPC64 1
            \\
        ),
        .sparc64 => try w.writeAll(
            \\#define __sparc__ 1
            \\#define __sparc 1
            \\#define __sparc_v9__ 1
            \\
        ),
        .sparc, .sparcel => try w.writeAll(
            \\#define __sparc__ 1
            \\#define __sparc 1
            \\
        ),
        .arm, .armeb => try w.writeAll(
            \\#define __arm__ 1
            \\#define __arm 1
            \\
        ),
        .thumb, .thumbeb => try w.writeAll(
            \\#define __arm__ 1
            \\#define __arm 1
            \\#define __thumb__ 1
            \\
        ),
        .aarch64, .aarch64_be => try w.writeAll("#define __aarch64__ 1\n"),
        else => {},
    }

    if (comp.target.os.tag != .windows) switch (comp.target.cpu.arch.ptrBitWidth()) {
        64 => try w.writeAll(
            \\#define _LP64 1
            \\#define __LP64__ 1
            \\
        ),
        32 => try w.writeAll("#define _ILP32 1\n"),
        else => {},
    };

    try w.writeAll(
        \\#define __ORDER_LITTLE_ENDIAN__ 1234
        \\#define __ORDER_BIG_ENDIAN__ 4321
        \\#define __ORDER_PDP_ENDIAN__ 3412
        \\
    );
    if (comp.target.cpu.arch.endian() == .Little) try w.writeAll(
        \\#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
        \\#define __LITTLE_ENDIAN__ 1
        \\
    ) else try w.writeAll(
        \\#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
        \\#define __BIG_ENDIAN__ 1
        \\
    );

    // timestamps
    try generateDateAndTime(w);

    // types
    if (Type.getCharSignedness(comp) == .unsigned) try w.writeAll("#define __CHAR_UNSIGNED__ 1\n");
    try w.writeAll("#define __CHAR_BIT__ 8\n");

    // int maxs
    try comp.generateIntMax(w, "__SCHAR_MAX__", .{ .specifier = .schar });
    try comp.generateIntMax(w, "__SHRT_MAX__", .{ .specifier = .short });
    try comp.generateIntMax(w, "__INT_MAX__", .{ .specifier = .int });
    try comp.generateIntMax(w, "__LONG_MAX__", .{ .specifier = .long });
    try comp.generateIntMax(w, "__LONG_LONG_MAX__", .{ .specifier = .long_long });
    try comp.generateIntMax(w, "__WCHAR_MAX__", comp.types.wchar);
    // try comp.generateIntMax(w, "__WINT_MAX__", comp.types.wchar);
    // try comp.generateIntMax(w, "__INTMAX_MAX__", comp.types.wchar);
    try comp.generateIntMax(w, "__SIZE_MAX__", comp.types.size);
    // try comp.generateIntMax(w, "__UINTMAX_MAX__", comp.types.wchar);
    try comp.generateIntMax(w, "__PTRDIFF_MAX__", comp.types.ptrdiff);
    // try comp.generateIntMax(w, "__INTPTR_MAX__", comp.types.wchar);
    // try comp.generateIntMax(w, "__UINTPTR_MAX__", comp.types.size);

    // sizeof types
    try comp.generateSizeofType(w, "__SIZEOF_FLOAT__", .{ .specifier = .float });
    try comp.generateSizeofType(w, "__SIZEOF_DOUBLE__", .{ .specifier = .double });
    try comp.generateSizeofType(w, "__SIZEOF_LONG_DOUBLE__", .{ .specifier = .long_double });
    try comp.generateSizeofType(w, "__SIZEOF_SHORT__", .{ .specifier = .short });
    try comp.generateSizeofType(w, "__SIZEOF_INT__", .{ .specifier = .int });
    try comp.generateSizeofType(w, "__SIZEOF_LONG__", .{ .specifier = .long });
    try comp.generateSizeofType(w, "__SIZEOF_LONG_LONG__", .{ .specifier = .long_long });
    try comp.generateSizeofType(w, "__SIZEOF_POINTER__", .{ .specifier = .pointer });
    try comp.generateSizeofType(w, "__SIZEOF_PTRDIFF_T__", comp.types.ptrdiff);
    try comp.generateSizeofType(w, "__SIZEOF_SIZE_T__", comp.types.size);
    try comp.generateSizeofType(w, "__SIZEOF_WCHAR_T__", comp.types.wchar);
    // try comp.generateSizeofType(w, "__SIZEOF_WINT_T__", .{ .specifier = .pointer });

    // various int types
    const mapper = comp.string_interner.getSlowTypeMapper();
    try generateTypeMacro(w, mapper, "__PTRDIFF_TYPE__", comp.types.ptrdiff);
    try generateTypeMacro(w, mapper, "__SIZE_TYPE__", comp.types.size);
    try generateTypeMacro(w, mapper, "__WCHAR_TYPE__", comp.types.wchar);

    return comp.addSourceFromBuffer("<builtin>", buf.items);
}

fn generateTypeMacro(w: anytype, mapper: StringInterner.TypeMapper, name: []const u8, ty: Type) !void {
    try w.print("#define {s} ", .{name});
    try ty.print(mapper, w);
    try w.writeByte('\n');
}

fn generateBuiltinTypes(comp: *Compilation) !void {
    const os = comp.target.os.tag;
    const wchar: Type = switch (comp.target.cpu.arch) {
        .xcore => .{ .specifier = .uchar },
        .ve => .{ .specifier = .uint },
        .arm, .armeb, .thumb, .thumbeb => .{
            .specifier = if (os != .windows and os != .netbsd and os != .openbsd) .uint else .int,
        },
        .aarch64, .aarch64_be, .aarch64_32 => .{
            .specifier = if (!os.isDarwin() and os != .netbsd) .uint else .int,
        },
        .x86_64, .i386 => .{ .specifier = if (os == .windows) .ushort else .int },
        else => .{ .specifier = .int },
    };

    const ptrdiff = if (os == .windows and comp.target.cpu.arch.ptrBitWidth() == 64)
        Type{ .specifier = .long_long }
    else switch (comp.target.cpu.arch.ptrBitWidth()) {
        32 => Type{ .specifier = .int },
        64 => Type{ .specifier = .long },
        else => unreachable,
    };

    const size = if (os == .windows and comp.target.cpu.arch.ptrBitWidth() == 64)
        Type{ .specifier = .ulong_long }
    else switch (comp.target.cpu.arch.ptrBitWidth()) {
        32 => Type{ .specifier = .uint },
        64 => Type{ .specifier = .ulong },
        else => unreachable,
    };

    const va_list = try comp.generateVaListType();

    comp.types = .{
        .wchar = wchar,
        .ptrdiff = ptrdiff,
        .size = size,
        .va_list = va_list,
    };
}

fn generateVaListType(comp: *Compilation) !Type {
    const Kind = enum { char_ptr, void_ptr, aarch64_va_list, x86_64_va_list };
    const kind: Kind = switch (comp.target.cpu.arch) {
        .aarch64 => switch (comp.target.os.tag) {
            .windows => @as(Kind, .char_ptr),
            .ios, .macos, .tvos, .watchos => .char_ptr,
            else => .aarch64_va_list,
        },
        .sparc, .wasm32, .wasm64, .bpfel, .bpfeb, .riscv32, .riscv64, .avr, .spirv32, .spirv64 => .void_ptr,
        .powerpc => switch (comp.target.os.tag) {
            .ios, .macos, .tvos, .watchos, .aix => @as(Kind, .char_ptr),
            else => return Type{ .specifier = .void }, // unknown
        },
        .i386 => .char_ptr,
        .x86_64 => switch (comp.target.os.tag) {
            .windows => @as(Kind, .char_ptr),
            else => .x86_64_va_list,
        },
        else => return Type{ .specifier = .void }, // unknown
    };

    // TODO this might be bad?
    const arena = comp.diag.arena.allocator();

    var ty: Type = undefined;
    switch (kind) {
        .char_ptr => ty = .{ .specifier = .char },
        .void_ptr => ty = .{ .specifier = .void },
        .aarch64_va_list => {
            const record_ty = try arena.create(Type.Record);
            record_ty.* = .{
                .name = try comp.intern("__va_list_tag"),
                .fields = try arena.alloc(Type.Record.Field, 5),
                .field_attributes = null,
                .type_layout = Type.TypeLayout.init(32, 8),
            };
            const void_ty = try arena.create(Type);
            void_ty.* = .{ .specifier = .void };
            const void_ptr = Type{ .specifier = .pointer, .data = .{ .sub_type = void_ty } };
            record_ty.fields[0] = .{ .name = try comp.intern("__stack"), .ty = void_ptr };
            record_ty.fields[1] = .{ .name = try comp.intern("__gr_top"), .ty = void_ptr };
            record_ty.fields[2] = .{ .name = try comp.intern("__vr_top"), .ty = void_ptr };
            record_ty.fields[3] = .{ .name = try comp.intern("__gr_offs"), .ty = .{ .specifier = .int } };
            record_ty.fields[4] = .{ .name = try comp.intern("__vr_offs"), .ty = .{ .specifier = .int } };
            ty = .{ .specifier = .@"struct", .data = .{ .record = record_ty } };
        },
        .x86_64_va_list => {
            const record_ty = try arena.create(Type.Record);
            record_ty.* = .{
                .name = try comp.intern("__va_list_tag"),
                .fields = try arena.alloc(Type.Record.Field, 4),
                .field_attributes = null,
                .type_layout = Type.TypeLayout.init(24, 8),
            };
            const void_ty = try arena.create(Type);
            void_ty.* = .{ .specifier = .void };
            const void_ptr = Type{ .specifier = .pointer, .data = .{ .sub_type = void_ty } };
            record_ty.fields[0] = .{ .name = try comp.intern("gp_offset"), .ty = .{ .specifier = .uint } };
            record_ty.fields[1] = .{ .name = try comp.intern("fp_offset"), .ty = .{ .specifier = .uint } };
            record_ty.fields[2] = .{ .name = try comp.intern("overflow_arg_area"), .ty = void_ptr };
            record_ty.fields[3] = .{ .name = try comp.intern("reg_save_area"), .ty = void_ptr };
            ty = .{ .specifier = .@"struct", .data = .{ .record = record_ty } };
        },
    }
    if (kind == .char_ptr or kind == .void_ptr) {
        const elem_ty = try arena.create(Type);
        elem_ty.* = ty;
        ty = Type{ .specifier = .pointer, .data = .{ .sub_type = elem_ty } };
    } else {
        const arr_ty = try arena.create(Type.Array);
        arr_ty.* = .{ .len = 1, .elem = ty };
        ty = Type{ .specifier = .array, .data = .{ .array = arr_ty } };
    }

    return ty;
}

fn generateIntMax(comp: *Compilation, w: anytype, name: []const u8, ty: Type) !void {
    const bit_count = @intCast(u8, ty.sizeof(comp).? * 8);
    const unsigned = ty.isUnsignedInt(comp);
    const max = if (bit_count == 128)
        @as(u128, if (unsigned) std.math.maxInt(u128) else std.math.maxInt(u128))
    else
        (@as(u64, 1) << @truncate(u6, bit_count - @boolToInt(!unsigned))) - 1;
    try w.print("#define {s} {d}\n", .{ name, max });
}

fn generateSizeofType(comp: *Compilation, w: anytype, name: []const u8, ty: Type) !void {
    try w.print("#define {s} {d}\n", .{ name, ty.sizeof(comp).? });
}

pub fn nextLargestIntSameSign(comp: *const Compilation, ty: Type) ?Type {
    assert(ty.isInt());
    const specifiers = if (ty.isUnsignedInt(comp))
        [_]Type.Specifier{ .short, .int, .long, .long_long }
    else
        [_]Type.Specifier{ .ushort, .uint, .ulong, .ulong_long };
    const size = ty.sizeof(comp).?;
    for (specifiers) |specifier| {
        const candidate = Type{ .specifier = specifier };
        if (candidate.sizeof(comp).? > size) return candidate;
    }
    return null;
}

/// If `enum E { ... }` syntax has a fixed underlying integer type regardless of the presence of
/// __attribute__((packed)) or the range of values of the corresponding enumerator constants,
/// specify it here.
/// TODO: likely incomplete
pub fn fixedEnumTagSpecifier(comp: *const Compilation) ?Type.Specifier {
    switch (comp.langopts.emulate) {
        .msvc => return .int,
        .clang => if (comp.target.os.tag == .windows) return .int,
        .gcc => {},
    }
    return null;
}

pub fn defineSystemIncludes(comp: *Compilation) !void {
    var buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    var search_path: []const u8 = std.fs.selfExePath(&buf) catch return error.SelfExeNotFound;
    while (std.fs.path.dirname(search_path)) |dirname| : (search_path = dirname) {
        var base_dir = std.fs.cwd().openDir(dirname, .{}) catch continue;
        defer base_dir.close();

        base_dir.access("include/stddef.h", .{}) catch continue;
        const path = try std.fs.path.join(comp.gpa, &.{ dirname, "include" });
        errdefer comp.gpa.free(path);
        try comp.system_include_dirs.append(path);
        break;
    } else return error.AroIncludeNotFound;

    if (comp.target.os.tag == .linux) {
        var fib = std.heap.FixedBufferAllocator.init(&buf);
        const triple_str = try comp.target.linuxTriple(fib.allocator());
        const multiarch_path = try std.fs.path.join(fib.allocator(), &.{ "/usr/include", triple_str });

        if (!std.meta.isError(std.fs.accessAbsolute(multiarch_path, .{}))) {
            const duped = try comp.gpa.dupe(u8, multiarch_path);
            errdefer comp.gpa.free(duped);
            try comp.system_include_dirs.append(duped);
        }
    }
    const usr_include = try comp.gpa.dupe(u8, "/usr/include");
    errdefer comp.gpa.free(usr_include);
    try comp.system_include_dirs.append(usr_include);
}

pub fn getSource(comp: *const Compilation, id: Source.Id) Source {
    if (id == .generated) return .{
        .path = "<scratch space>",
        .buf = comp.generated_buf.items,
        .id = .generated,
        .splice_locs = &.{},
    };
    return comp.sources.values()[@enumToInt(id) - 2];
}

/// Creates a Source from the contents of `reader` and adds it to the Compilation
/// Performs newline splicing, line-ending normalization to '\n', and UTF-8 validation.
/// caller retains ownership of `path`
/// `expected_size` will be allocated to hold the contents of `reader` and *must* be at least
/// as large as the entire contents of `reader`.
/// To add a pre-existing buffer as a Source, see addSourceFromBuffer
/// To add a file's contents given its path, see addSourceFromPath
pub fn addSourceFromReader(comp: *Compilation, reader: anytype, path: []const u8, expected_size: u32) !Source {
    var contents = try comp.gpa.alloc(u8, expected_size);
    errdefer comp.gpa.free(contents);

    const duped_path = try comp.gpa.dupe(u8, path);
    errdefer comp.gpa.free(duped_path);

    var splice_list = std.ArrayList(u32).init(comp.gpa);
    defer splice_list.deinit();

    const source_id = @intToEnum(Source.Id, comp.sources.count() + 2);

    var i: u32 = 0;
    var backslash_loc: u32 = undefined;
    var state: enum { start, back_slash, cr, back_slash_cr, trailing_ws } = .start;
    var line: u32 = 1;

    while (true) {
        const byte = reader.readByte() catch |err| switch (err) {
            error.EndOfStream => break,
            else => |e| return e,
        };
        contents[i] = byte;

        switch (byte) {
            '\r' => {
                switch (state) {
                    .start, .cr => {
                        line += 1;
                        state = .cr;
                        contents[i] = '\n';
                        i += 1;
                    },
                    .back_slash, .trailing_ws, .back_slash_cr => {
                        i = backslash_loc;
                        try splice_list.append(i);
                        if (state == .trailing_ws) {
                            try comp.diag.add(.{
                                .tag = .backslash_newline_escape,
                                .loc = .{ .id = source_id, .byte_offset = i, .line = line },
                            }, &.{});
                        }
                        state = if (state == .back_slash_cr) .cr else .back_slash_cr;
                    },
                }
            },
            '\n' => {
                switch (state) {
                    .start => {
                        line += 1;
                        i += 1;
                    },
                    .cr, .back_slash_cr => {},
                    .back_slash, .trailing_ws => {
                        i = backslash_loc;
                        if (state == .back_slash or state == .trailing_ws) {
                            try splice_list.append(i);
                        }
                        if (state == .trailing_ws) {
                            try comp.diag.add(.{
                                .tag = .backslash_newline_escape,
                                .loc = .{ .id = source_id, .byte_offset = i, .line = line },
                            }, &.{});
                        }
                    },
                }
                state = .start;
            },
            '\\' => {
                backslash_loc = i;
                state = .back_slash;
                i += 1;
            },
            '\t', '\x0B', '\x0C', ' ' => {
                switch (state) {
                    .start, .trailing_ws => {},
                    .cr, .back_slash_cr => state = .start,
                    .back_slash => state = .trailing_ws,
                }
                i += 1;
            },
            else => {
                i += 1;
                state = .start;
            },
        }
    }

    const splice_locs = splice_list.toOwnedSlice();
    errdefer comp.gpa.free(splice_locs);

    if (i != contents.len) contents = try comp.gpa.realloc(contents, i);

    var source = Source{
        .id = source_id,
        .path = duped_path,
        .buf = contents,
        .splice_locs = splice_locs,
    };

    try comp.sources.put(duped_path, source);
    if (source.offsetOfInvalidUtf8()) |offset| {
        try comp.invalid_utf8_locs.putNoClobber(comp.gpa, source_id, offset);
    }
    return source;
}

/// Caller retains ownership of `path` and `buf`.
pub fn addSourceFromBuffer(comp: *Compilation, path: []const u8, buf: []const u8) !Source {
    if (comp.sources.get(path)) |some| return some;

    const size = std.math.cast(u32, buf.len) orelse return error.StreamTooLong;
    const reader = std.io.fixedBufferStream(buf).reader();

    return comp.addSourceFromReader(reader, path, size);
}

/// Caller retains ownership of `path`
pub fn addSourceFromPath(comp: *Compilation, path: []const u8) !Source {
    if (comp.sources.get(path)) |some| return some;

    if (mem.indexOfScalar(u8, path, 0) != null) {
        return error.FileNotFound;
    }

    const file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    const size = std.math.cast(u32, try file.getEndPos()) orelse return error.StreamTooLong;
    var reader = std.io.bufferedReader(file.reader()).reader();

    return comp.addSourceFromReader(reader, path, size);
}

pub const IncludeDirIterator = struct {
    comp: *const Compilation,
    cwd_source_id: ?Source.Id,
    include_dirs_idx: usize = 0,
    sys_include_dirs_idx: usize = 0,
    /// nextWithFile will use this to hold the full path for its return value
    /// not required if `nextWithFile` is not used
    path_buf: []u8 = undefined,

    fn next(self: *IncludeDirIterator) ?[]const u8 {
        if (self.cwd_source_id) |source_id| {
            self.cwd_source_id = null;
            const path = self.comp.getSource(source_id).path;
            return std.fs.path.dirname(path) orelse ".";
        }
        while (self.include_dirs_idx < self.comp.include_dirs.items.len) {
            defer self.include_dirs_idx += 1;
            return self.comp.include_dirs.items[self.include_dirs_idx];
        }
        while (self.sys_include_dirs_idx < self.comp.system_include_dirs.items.len) {
            defer self.sys_include_dirs_idx += 1;
            return self.comp.system_include_dirs.items[self.sys_include_dirs_idx];
        }
        return null;
    }

    /// Return value is invalidated by subsequent calls to nextWithFile
    fn nextWithFile(self: *IncludeDirIterator, filename: []const u8) ?[]const u8 {
        var fib = std.heap.FixedBufferAllocator.init(self.path_buf);
        while (self.next()) |dir| : (fib.end_index = 0) {
            const path = std.fs.path.join(fib.allocator(), &.{ dir, filename }) catch continue;
            return path;
        }
        return null;
    }

    /// Advance the iterator until it finds an include directory that matches
    /// the directory which contains `source`.
    fn skipUntilDirMatch(self: *IncludeDirIterator, source: Source.Id) void {
        const path = self.comp.getSource(source).path;
        const includer_path = std.fs.path.dirname(path) orelse ".";
        while (self.next()) |dir| {
            if (mem.eql(u8, includer_path, dir)) break;
        }
    }
};

pub fn hasInclude(
    comp: *const Compilation,
    filename: []const u8,
    includer_token_source: Source.Id,
    /// angle bracket vs quotes
    include_type: IncludeType,
    /// __has_include vs __has_include_next
    which: WhichInclude,
) bool {
    const cwd = std.fs.cwd();
    if (std.fs.path.isAbsolute(filename)) {
        if (which == .next) return false;
        return !std.meta.isError(cwd.access(filename, .{}));
    }

    const cwd_source_id = switch (include_type) {
        .quotes => switch (which) {
            .first => includer_token_source,
            .next => null,
        },
        .angle_brackets => null,
    };
    var path_buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    var it = IncludeDirIterator{ .comp = comp, .cwd_source_id = cwd_source_id, .path_buf = &path_buf };
    if (which == .next) {
        it.skipUntilDirMatch(includer_token_source);
    }

    while (it.nextWithFile(filename)) |path| {
        if (!std.meta.isError(cwd.access(path, .{}))) return true;
    }
    return false;
}

pub const WhichInclude = enum {
    first,
    next,
};

pub const IncludeType = enum {
    quotes,
    angle_brackets,
};

pub fn findInclude(
    comp: *Compilation,
    filename: []const u8,
    includer_token_source: Source.Id,
    /// angle bracket vs quotes
    include_type: IncludeType,
    /// include vs include_next
    which: WhichInclude,
) !?Source {
    var path_buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    if (std.fs.path.isAbsolute(filename)) {
        if (which == .next) return null;
        return if (comp.addSourceFromPath(filename)) |some|
            some
        else |err| switch (err) {
            error.OutOfMemory => |e| return e,
            else => null,
        };
    }
    const cwd_source_id = switch (include_type) {
        .quotes => switch (which) {
            .first => includer_token_source,
            .next => null,
        },
        .angle_brackets => null,
    };
    var it = IncludeDirIterator{ .comp = comp, .cwd_source_id = cwd_source_id, .path_buf = &path_buf };

    if (which == .next) {
        it.skipUntilDirMatch(includer_token_source);
    }

    while (it.nextWithFile(filename)) |path| {
        if (comp.addSourceFromPath(path)) |some|
            return some
        else |err| switch (err) {
            error.OutOfMemory => return error.OutOfMemory,
            else => {},
        }
    }
    return null;
}

pub fn addPragmaHandler(comp: *Compilation, name: []const u8, handler: *Pragma) Allocator.Error!void {
    try comp.pragma_handlers.putNoClobber(name, handler);
}

pub fn addDefaultPragmaHandlers(comp: *Compilation) Allocator.Error!void {
    const GCC = @import("pragmas/gcc.zig");
    var gcc = try GCC.init(comp.gpa);
    errdefer gcc.deinit(gcc, comp);

    const Once = @import("pragmas/once.zig");
    var once = try Once.init(comp.gpa);
    errdefer once.deinit(once, comp);

    const Message = @import("pragmas/message.zig");
    var message = try Message.init(comp.gpa);
    errdefer message.deinit(message, comp);

    const Pack = @import("pragmas/pack.zig");
    var pack = try Pack.init(comp.gpa);
    errdefer pack.deinit(pack, comp);

    try comp.addPragmaHandler("GCC", gcc);
    try comp.addPragmaHandler("once", once);
    try comp.addPragmaHandler("message", message);
    try comp.addPragmaHandler("pack", pack);
}

pub fn getPragma(comp: *Compilation, name: []const u8) ?*Pragma {
    return comp.pragma_handlers.get(name);
}

const PragmaEvent = enum {
    before_preprocess,
    before_parse,
    after_parse,
};

pub fn pragmaEvent(comp: *Compilation, event: PragmaEvent) void {
    for (comp.pragma_handlers.values()) |pragma| {
        const maybe_func = switch (event) {
            .before_preprocess => pragma.beforePreprocess,
            .before_parse => pragma.beforeParse,
            .after_parse => pragma.afterParse,
        };
        if (maybe_func) |func| func(pragma, comp);
    }
}

pub const renderErrors = Diagnostics.render;

pub fn isTlsSupported(comp: *Compilation) bool {
    if (comp.target.isDarwin()) {
        var supported = false;
        switch (comp.target.os.tag) {
            .macos => supported = !(comp.target.os.isAtLeast(.macos, .{ .major = 10, .minor = 7 }) orelse false),
            else => {},
        }
        return supported;
    }
    return switch (comp.target.cpu.arch) {
        .tce, .tcele, .bpfel, .bpfeb, .msp430, .nvptx, .nvptx64, .i386, .arm, .armeb, .thumb, .thumbeb => false,
        else => true,
    };
}

pub fn ignoreNonZeroSizedBitfieldTypeAlignment(comp: *const Compilation) bool {
    switch (comp.target.cpu.arch) {
        .avr => return true,
        .arm => {
            if (std.Target.arm.featureSetHas(comp.target.cpu.features, .has_v7)) {
                switch (comp.target.os.tag) {
                    .ios => return true,
                    else => return false,
                }
            }
        },
        else => return false,
    }
    return false;
}

pub fn minZeroWidthBitfieldAlignment(comp: *const Compilation) ?u29 {
    switch (comp.target.cpu.arch) {
        .avr => return 8,
        .arm => {
            if (std.Target.arm.featureSetHas(comp.target.cpu.features, .has_v7)) {
                switch (comp.target.os.tag) {
                    .ios => return 32,
                    else => return null,
                }
            } else return null;
        },
        else => return null,
    }
}

pub fn unnamedFieldAffectsAlignment(comp: *const Compilation) bool {
    switch (comp.target.cpu.arch) {
        .aarch64 => {
            if (comp.target.isDarwin() or comp.target.os.tag == .windows) return false;
            return true;
        },
        .armeb => {
            if (std.Target.arm.featureSetHas(comp.target.cpu.features, .has_v7)) {
                if (std.Target.Abi.default(comp.target.cpu.arch, comp.target.os) == .eabi) return true;
            }
        },
        .arm => return true,
        .avr => return true,
        .thumb => {
            if (comp.target.os.tag == .windows) return false;
            return true;
        },
        else => return false,
    }
    return false;
}

pub fn packAllEnums(comp: *const Compilation) bool {
    return switch (comp.target.cpu.arch) {
        .hexagon => true,
        else => false,
    };
}

/// Default alignment (in bytes) for __attribute__((aligned)) when no alignment is specified
pub fn defaultAlignment(comp: *const Compilation) u29 {
    switch (comp.target.cpu.arch) {
        .avr => return 1,
        .arm,
        .armeb,
        .thumb,
        .thumbeb,
        => switch (comp.target.abi) {
            .gnueabi, .gnueabihf, .eabi, .eabihf, .musleabi, .musleabihf => return 8,
            else => {},
        },
        else => {},
    }
    return 16;
}
pub fn systemCompiler(comp: *const Compilation) LangOpts.Compiler {
    const target = comp.target;
    // andorid is linux but not gcc, so these checks go first
    // the rest for documentation as fn returns .clang
    if (target.isDarwin() or
        target.isAndroid() or
        target.isBSD() or
        target.os.tag == .fuchsia or
        target.os.tag == .solaris)
    {
        return .clang;
    }
    // this is before windows to grab WindowsGnu
    if (target.abi.isGnu() or
        target.os.tag == .linux)
    {
        return .gcc;
    }
    if (target.os.tag == .windows) {
        return .msvc;
    }
    return .clang;
}

test "addSourceFromReader" {
    const Test = struct {
        fn addSourceFromReader(str: []const u8, expected: []const u8, warning_count: u32, splices: []const u32) !void {
            var comp = Compilation.init(std.testing.allocator);
            defer comp.deinit();

            var reader = std.io.fixedBufferStream(str).reader();
            const source = try comp.addSourceFromReader(reader, "path", @intCast(u32, str.len));

            try std.testing.expectEqualStrings(expected, source.buf);
            try std.testing.expectEqual(warning_count, @intCast(u32, comp.diag.list.items.len));
            try std.testing.expectEqualSlices(u32, splices, source.splice_locs);
        }

        fn withAllocationFailures(allocator: std.mem.Allocator) !void {
            var comp = Compilation.init(allocator);
            defer comp.deinit();

            _ = try comp.addSourceFromBuffer("path", "spliced\\\nbuffer\n");
            _ = try comp.addSourceFromBuffer("path", "non-spliced buffer\n");
        }
    };
    try Test.addSourceFromReader("ab\\\nc", "abc", 0, &.{2});
    try Test.addSourceFromReader("ab\\\rc", "abc", 0, &.{2});
    try Test.addSourceFromReader("ab\\\r\nc", "abc", 0, &.{2});
    try Test.addSourceFromReader("ab\\ \nc", "abc", 1, &.{2});
    try Test.addSourceFromReader("ab\\\t\nc", "abc", 1, &.{2});
    try Test.addSourceFromReader("ab\\                     \t\nc", "abc", 1, &.{2});
    try Test.addSourceFromReader("ab\\\r \nc", "ab \nc", 0, &.{2});
    try Test.addSourceFromReader("ab\\\\\nc", "ab\\c", 0, &.{3});
    try Test.addSourceFromReader("ab\\   \r\nc", "abc", 1, &.{2});
    try Test.addSourceFromReader("ab\\ \\\nc", "ab\\ c", 0, &.{4});
    try Test.addSourceFromReader("ab\\\r\\\nc", "abc", 0, &.{ 2, 2 });
    try Test.addSourceFromReader("ab\\  \rc", "abc", 1, &.{2});
    try Test.addSourceFromReader("ab\\", "ab\\", 0, &.{});
    try Test.addSourceFromReader("ab\\\\", "ab\\\\", 0, &.{});
    try Test.addSourceFromReader("ab\\ ", "ab\\ ", 0, &.{});
    try Test.addSourceFromReader("ab\\\n", "ab", 0, &.{2});
    try Test.addSourceFromReader("ab\\\r\n", "ab", 0, &.{2});
    try Test.addSourceFromReader("ab\\\r", "ab", 0, &.{2});

    // carriage return normalization
    try Test.addSourceFromReader("ab\r", "ab\n", 0, &.{});
    try Test.addSourceFromReader("ab\r\r", "ab\n\n", 0, &.{});
    try Test.addSourceFromReader("ab\r\r\n", "ab\n\n", 0, &.{});
    try Test.addSourceFromReader("ab\r\r\n\r", "ab\n\n\n", 0, &.{});
    try Test.addSourceFromReader("\r\\", "\n\\", 0, &.{});
    try Test.addSourceFromReader("\\\r\\", "\\", 0, &.{0});

    try std.testing.checkAllAllocationFailures(std.testing.allocator, Test.withAllocationFailures, .{});
}

test "addSourceFromReader - exhaustive check for carriage return elimination" {
    const alphabet = [_]u8{ '\r', '\n', ' ', '\\', 'a' };
    const alen = alphabet.len;
    var buf: [alphabet.len]u8 = [1]u8{alphabet[0]} ** alen;

    var comp = Compilation.init(std.testing.allocator);
    defer comp.deinit();

    var source_count: u32 = 0;

    while (true) {
        const source = try comp.addSourceFromBuffer(&buf, &buf);
        source_count += 1;
        try std.testing.expect(std.mem.indexOfScalar(u8, source.buf, '\r') == null);

        if (std.mem.allEqual(u8, &buf, alphabet[alen - 1])) break;

        var idx = std.mem.indexOfScalar(u8, &alphabet, buf[buf.len - 1]).?;
        buf[buf.len - 1] = alphabet[(idx + 1) % alen];
        var j = buf.len - 1;
        while (j > 0) : (j -= 1) {
            idx = std.mem.indexOfScalar(u8, &alphabet, buf[j - 1]).?;
            if (buf[j] == alphabet[0]) buf[j - 1] = alphabet[(idx + 1) % alen] else break;
        }
    }
    try std.testing.expect(source_count == std.math.powi(usize, alen, alen) catch unreachable);
}

test "alignment functions - smoke test" {
    var comp = Compilation.init(std.testing.allocator);
    defer comp.deinit();

    const x86 = std.Target.Cpu.Arch.x86_64;
    comp.target.cpu = std.Target.Cpu.baseline(x86);
    comp.target.os = std.Target.Os.Tag.defaultVersionRange(.linux, x86);
    comp.target.abi = std.Target.Abi.default(x86, comp.target.os);

    try std.testing.expect(comp.isTlsSupported());
    try std.testing.expect(!comp.ignoreNonZeroSizedBitfieldTypeAlignment());
    try std.testing.expect(comp.minZeroWidthBitfieldAlignment() == null);
    try std.testing.expect(!comp.unnamedFieldAffectsAlignment());
    try std.testing.expect(comp.defaultAlignment() == 16);
    try std.testing.expect(!comp.packAllEnums());
    try std.testing.expect(comp.systemCompiler() == .gcc);

    const arm = std.Target.Cpu.Arch.arm;
    comp.target.cpu = std.Target.Cpu.baseline(arm);
    comp.target.os = std.Target.Os.Tag.defaultVersionRange(.ios, arm);
    comp.target.abi = std.Target.Abi.default(arm, comp.target.os);

    try std.testing.expect(!comp.isTlsSupported());
    try std.testing.expect(comp.ignoreNonZeroSizedBitfieldTypeAlignment());
    try std.testing.expectEqual(@as(?u29, 32), comp.minZeroWidthBitfieldAlignment());
    try std.testing.expect(comp.unnamedFieldAffectsAlignment());
    try std.testing.expect(comp.defaultAlignment() == 16);
    try std.testing.expect(!comp.packAllEnums());
    try std.testing.expect(comp.systemCompiler() == .clang);
}
