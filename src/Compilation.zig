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
builtin_header_path: ?[]u8 = null,
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
    comp.system_include_dirs.deinit();
    comp.pragma_handlers.deinit();
    if (comp.builtin_header_path) |some| comp.gpa.free(some);
    comp.generated_buf.deinit();
    comp.builtins.deinit(comp.gpa);
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
    const day_name = day_names[(epoch_day.day + 3) % 7];
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
        .sparcv9 => try w.writeAll(
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
        \\#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__;
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
    try generateTypeMacro(w, "__PTRDIFF_TYPE__", comp.types.ptrdiff);
    try generateTypeMacro(w, "__SIZE_TYPE__", comp.types.size);
    try generateTypeMacro(w, "__WCHAR_TYPE__", comp.types.wchar);

    const duped_path = try comp.gpa.dupe(u8, "<builtin>");
    errdefer comp.gpa.free(duped_path);

    const contents = buf.toOwnedSlice();
    errdefer comp.gpa.free(contents);

    const source = Source{
        .id = @intToEnum(Source.Id, comp.sources.count() + 2),
        .path = duped_path,
        .buf = contents,
        .splice_locs = &.{},
    };
    try comp.sources.put(duped_path, source);
    return source;
}

fn generateTypeMacro(w: anytype, name: []const u8, ty: Type) !void {
    try w.print("#define {s} ", .{name});
    try ty.print(w);
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
                .name = "__va_list_tag",
                .fields = try arena.alloc(Type.Record.Field, 5),
                .size = 32,
                .alignment = 8,
            };
            const void_ty = try arena.create(Type);
            void_ty.* = .{ .specifier = .void };
            const void_ptr = Type{ .specifier = .pointer, .data = .{ .sub_type = void_ty } };
            record_ty.fields[0] = .{ .name = "__stack", .ty = void_ptr };
            record_ty.fields[1] = .{ .name = "__gr_top", .ty = void_ptr };
            record_ty.fields[2] = .{ .name = "__vr_top", .ty = void_ptr };
            record_ty.fields[3] = .{ .name = "__gr_offs", .ty = .{ .specifier = .int } };
            record_ty.fields[4] = .{ .name = "__vr_offs", .ty = .{ .specifier = .int } };
            ty = .{ .specifier = .@"struct", .data = .{ .record = record_ty } };
        },
        .x86_64_va_list => {
            const record_ty = try arena.create(Type.Record);
            record_ty.* = .{
                .name = "__va_list_tag",
                .fields = try arena.alloc(Type.Record.Field, 4),
                .size = 24,
                .alignment = 8,
            };
            const void_ty = try arena.create(Type);
            void_ty.* = .{ .specifier = .void };
            const void_ptr = Type{ .specifier = .pointer, .data = .{ .sub_type = void_ty } };
            record_ty.fields[0] = .{ .name = "gp_offset", .ty = .{ .specifier = .uint } };
            record_ty.fields[1] = .{ .name = "fp_offset", .ty = .{ .specifier = .uint } };
            record_ty.fields[2] = .{ .name = "overflow_arg_area", .ty = void_ptr };
            record_ty.fields[3] = .{ .name = "reg_save_area", .ty = void_ptr };
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

pub fn defineSystemIncludes(comp: *Compilation) !void {
    var buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    var search_path: []const u8 = std.fs.selfExePath(&buf) catch return error.SelfExeNotFound;
    while (std.fs.path.dirname(search_path)) |dirname| : (search_path = dirname) {
        var base_dir = std.fs.cwd().openDir(dirname, .{}) catch continue;
        defer base_dir.close();

        base_dir.access("include/stddef.h", .{}) catch continue;
        const path = try std.fs.path.join(comp.gpa, &.{ dirname, "include" });
        comp.builtin_header_path = path;
        try comp.system_include_dirs.append(path);
        break;
    } else return error.AroIncludeNotFound;

    try comp.system_include_dirs.append("/usr/include");
}

pub fn getSource(comp: *Compilation, id: Source.Id) Source {
    if (id == .generated) return .{
        .path = "<scratch space>",
        .buf = comp.generated_buf.items,
        .id = .generated,
        .splice_locs = &.{},
    };
    return comp.sources.values()[@enumToInt(id) - 2];
}

pub fn addSource(comp: *Compilation, path: []const u8) !Source {
    if (comp.sources.get(path)) |some| return some;

    if (mem.indexOfScalar(u8, path, 0) != null) {
        return error.FileNotFound;
    }

    const file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    const duped_path = try comp.gpa.dupe(u8, path);
    errdefer comp.gpa.free(duped_path);

    const size = try file.getEndPos();
    if (size > std.math.maxInt(u32)) return error.StreamTooLong;

    const contents = try comp.gpa.alloc(u8, size);
    errdefer comp.gpa.free(contents);

    var splice_locs = std.ArrayList(u32).init(comp.gpa);
    defer splice_locs.deinit();

    var reader = std.io.bufferedReader(file.reader()).reader();
    var i: u32 = 0;
    while (true) {
        const byte = reader.readByte() catch break;
        if (byte == '\\') {
            const next = reader.readByte() catch {
                contents[i] = '\\';
                i += 1;
                break;
            };
            if (next == '\n') {
                try splice_locs.append(i);
                continue;
            }
            contents[i] = '\\';
            contents[i + 1] = next;
            i += 2;
        } else {
            contents[i] = byte;
            i += 1;
        }
    }
    var source = Source{
        .id = @intToEnum(Source.Id, comp.sources.count() + 2),
        .path = duped_path,
        .buf = if (contents.len == i) contents else try comp.gpa.realloc(contents, i),
        .splice_locs = try comp.gpa.dupe(u32, splice_locs.items),
    };
    source.checkUtf8();

    try comp.sources.put(duped_path, source);

    return source;
}

pub fn findInclude(comp: *Compilation, tok: Token, filename: []const u8, search_cwd: bool) !?Source {
    var path_buf: [std.fs.MAX_PATH_BYTES]u8 = undefined;
    var fib = std.heap.FixedBufferAllocator.init(&path_buf);
    if (search_cwd) blk: {
        const source = comp.getSource(tok.source);
        const path = if (std.fs.path.dirname(source.path)) |some|
            std.fs.path.join(fib.allocator(), &.{ some, filename }) catch break :blk
        else
            std.fs.path.join(fib.allocator(), &.{ ".", filename }) catch break :blk;
        if (comp.addSource(path)) |some|
            return some
        else |err| switch (err) {
            error.OutOfMemory => return error.OutOfMemory,
            else => {},
        }
    }
    for (comp.include_dirs.items) |dir| {
        fib.end_index = 0;
        const path = std.fs.path.join(fib.allocator(), &.{ dir, filename }) catch continue;
        if (comp.addSource(path)) |some|
            return some
        else |err| switch (err) {
            error.OutOfMemory => return error.OutOfMemory,
            else => {},
        }
    }
    for (comp.system_include_dirs.items) |dir| {
        fib.end_index = 0;
        const path = std.fs.path.join(fib.allocator(), &.{ dir, filename }) catch continue;
        if (comp.addSource(path)) |some|
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

    try comp.addPragmaHandler("GCC", gcc);
    try comp.addPragmaHandler("once", once);
    try comp.addPragmaHandler("message", message);
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
