const std = @import("std");
const assert = std.debug.assert;
const EpochSeconds = std.time.epoch.EpochSeconds;
const mem = std.mem;
const Allocator = mem.Allocator;

const backend = @import("backend");
const Interner = backend.Interner;
const CodeGenOptions = backend.CodeGenOptions;

const Builtins = @import("Builtins.zig");
const Builtin = Builtins.Builtin;
const Diagnostics = @import("Diagnostics.zig");
const LangOpts = @import("LangOpts.zig");
const Pragma = @import("Pragma.zig");
const SourceManager = @import("SourceManager.zig");
const StringInterner = @import("StringInterner.zig");
const target_util = @import("target.zig");
const Tokenizer = @import("Tokenizer.zig");
const Token = Tokenizer.Token;
const TypeStore = @import("TypeStore.zig");
const Type = TypeStore.Type;
const QualType = TypeStore.QualType;

pub const Error = error{
    /// A fatal error has ocurred and compilation has stopped.
    FatalError,
} || Allocator.Error;

pub const bit_int_max_bits = std.math.maxInt(u16);

/// Environment variables used during compilation / linking.
pub const Environment = struct {
    /// Directory to use for temporary files
    /// TODO: not implemented yet
    tmpdir: ?[]const u8 = null,

    /// PATH environment variable used to search for programs
    path: ?[]const u8 = null,

    /// Directories to try when searching for subprograms.
    /// TODO: not implemented yet
    compiler_path: ?[]const u8 = null,

    /// Directories to try when searching for special linker files, if compiling for the native target
    /// TODO: not implemented yet
    library_path: ?[]const u8 = null,

    /// List of directories to be searched as if specified with -I, but after any paths given with -I options on the command line
    /// Used regardless of the language being compiled
    /// TODO: not implemented yet
    cpath: ?[]const u8 = null,

    /// List of directories to be searched as if specified with -I, but after any paths given with -I options on the command line
    /// Used if the language being compiled is C
    /// TODO: not implemented yet
    c_include_path: ?[]const u8 = null,

    /// UNIX timestamp to be used instead of the current date and time in the __DATE__ and __TIME__ macros
    source_date_epoch: ?[]const u8 = null,

    /// Load all of the environment variables using the std.process API. Do not use if using Aro as a shared library on Linux without libc
    /// See https://github.com/ziglang/zig/issues/4524
    pub fn loadAll(allocator: std.mem.Allocator) !Environment {
        var env: Environment = .{};
        errdefer env.deinit(allocator);

        inline for (@typeInfo(@TypeOf(env)).@"struct".fields) |field| {
            std.debug.assert(@field(env, field.name) == null);

            var env_var_buf: [field.name.len]u8 = undefined;
            const env_var_name = std.ascii.upperString(&env_var_buf, field.name);
            const val: ?[]const u8 = std.process.getEnvVarOwned(allocator, env_var_name) catch |err| switch (err) {
                error.OutOfMemory => |e| return e,
                error.EnvironmentVariableNotFound => null,
                error.InvalidWtf8 => null,
            };
            @field(env, field.name) = val;
        }
        return env;
    }

    /// Use this only if environment slices were allocated with `allocator` (such as via `loadAll`)
    pub fn deinit(self: *Environment, allocator: std.mem.Allocator) void {
        inline for (@typeInfo(@TypeOf(self.*)).@"struct".fields) |field| {
            if (@field(self, field.name)) |slice| {
                allocator.free(slice);
            }
        }
        self.* = undefined;
    }
};

const Compilation = @This();

gpa: Allocator,
diagnostics: Diagnostics,

code_gen_options: CodeGenOptions = .default,
environment: Environment = .{},
target: std.Target = @import("builtin").target,
pragma_handlers: std.StringArrayHashMapUnmanaged(*Pragma) = .{},
langopts: LangOpts = .{},
builtins: Builtins = .{},
string_interner: StringInterner = .{},
interner: Interner = .{},
type_store: TypeStore = .{},

pub fn init(gpa: Allocator) Compilation {
    return .{
        .gpa = gpa,
        .diagnostics = Diagnostics.init(gpa),
    };
}

/// Initialize Compilation with default environment,
/// pragma handlers and emulation mode set to target.
pub fn initDefault(gpa: Allocator) !Compilation {
    var comp: Compilation = .{
        .gpa = gpa,
        .environment = try Environment.loadAll(gpa),
        .diagnostics = Diagnostics.init(gpa),
    };
    errdefer comp.deinit();
    try comp.addDefaultPragmaHandlers();
    comp.langopts.setEmulatedCompiler(target_util.systemCompiler(comp.target));
    return comp;
}

pub fn deinit(comp: *Compilation) void {
    for (comp.pragma_handlers.values()) |pragma| {
        pragma.deinit(pragma, comp);
    }
    comp.diagnostics.deinit();
    comp.pragma_handlers.deinit(comp.gpa);
    comp.builtins.deinit(comp.gpa);
    comp.string_interner.deinit(comp.gpa);
    comp.interner.deinit(comp.gpa);
    comp.environment.deinit(comp.gpa);
    comp.type_store.deinit(comp.gpa);
    comp.* = undefined;
}

pub fn internString(comp: *Compilation, str: []const u8) !StringInterner.StringId {
    return comp.string_interner.intern(comp.gpa, str);
}

pub fn getSourceEpoch(self: *const Compilation, max: i64) !?u47 {
    const provided = self.environment.source_date_epoch orelse return null;
    const parsed = std.fmt.parseInt(i64, provided, 10) catch return error.InvalidEpoch;
    if (parsed < 0 or parsed > max) return error.InvalidEpoch;
    return @intCast(std.math.clamp(parsed, 0, max_timestamp));
}

/// Dec 31 9999 23:59:59
const max_timestamp = 253402300799;

fn generateDateAndTime(w: anytype, opt_timestamp: ?u47) !void {
    const timestamp = opt_timestamp orelse {
        try w.print("#define __DATE__ \"??? ?? ????\"\n", .{});
        try w.print("#define __TIME__ \"??:??:??\"\n", .{});
        try w.print("#define __TIMESTAMP__ \"??? ??? ?? ??:??:?? ????\"\n", .{});
        return;
    };
    const epoch_seconds = EpochSeconds{ .secs = timestamp };
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
    const day_name = day_names[@intCast((epoch_day.day + 3) % 7)];
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

/// Which set of system defines to generate via generateBuiltinMacros
pub const SystemDefinesMode = enum {
    /// Only define macros required by the C standard (date/time macros and those beginning with `__STDC`)
    no_system_defines,
    /// Define the standard set of system macros
    include_system_defines,
};

fn generateSystemDefines(comp: *Compilation, w: anytype) !void {
    const ptr_width = comp.target.ptrBitWidth();

    if (comp.langopts.gnuc_version > 0) {
        try w.print("#define __GNUC__ {d}\n", .{comp.langopts.gnuc_version / 10_000});
        try w.print("#define __GNUC_MINOR__ {d}\n", .{comp.langopts.gnuc_version / 100 % 100});
        try w.print("#define __GNUC_PATCHLEVEL__ {d}\n", .{comp.langopts.gnuc_version % 100});
    }

    // os macros
    switch (comp.target.os.tag) {
        .linux => try w.writeAll(
            \\#define linux 1
            \\#define __linux 1
            \\#define __linux__ 1
            \\
        ),
        .windows => if (ptr_width == 32) try w.writeAll(
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
    if (comp.target.isAndroid()) {
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
        .x86 => try w.writeAll(
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
        .sparc => try w.writeAll(
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
        .msp430 => try w.writeAll(
            \\#define MSP430 1
            \\#define __MSP430__ 1
            \\
        ),
        else => {},
    }

    if (comp.target.os.tag != .windows) switch (ptr_width) {
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
    if (comp.target.cpu.arch.endian() == .little) try w.writeAll(
        \\#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
        \\#define __LITTLE_ENDIAN__ 1
        \\
    ) else try w.writeAll(
        \\#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
        \\#define __BIG_ENDIAN__ 1
        \\
    );

    // atomics
    try w.writeAll(
        \\#define __ATOMIC_RELAXED 0
        \\#define __ATOMIC_CONSUME 1
        \\#define __ATOMIC_ACQUIRE 2
        \\#define __ATOMIC_RELEASE 3
        \\#define __ATOMIC_ACQ_REL 4
        \\#define __ATOMIC_SEQ_CST 5
        \\
    );

    // TODO: Set these to target-specific constants depending on backend capabilities
    // For now they are just set to the "may be lock-free" value
    try w.writeAll(
        \\#define __ATOMIC_BOOL_LOCK_FREE 1
        \\#define __ATOMIC_CHAR_LOCK_FREE 1
        \\#define __ATOMIC_CHAR16_T_LOCK_FREE 1
        \\#define __ATOMIC_CHAR32_T_LOCK_FREE 1
        \\#define __ATOMIC_WCHAR_T_LOCK_FREE 1
        \\#define __ATOMIC_SHORT_LOCK_FREE 1
        \\#define __ATOMIC_INT_LOCK_FREE 1
        \\#define __ATOMIC_LONG_LOCK_FREE 1
        \\#define __ATOMIC_LLONG_LOCK_FREE 1
        \\#define __ATOMIC_POINTER_LOCK_FREE 1
        \\
    );
    if (comp.langopts.hasChar8_T()) {
        try w.writeAll("#define __ATOMIC_CHAR8_T_LOCK_FREE 1\n");
    }

    // types
    if (comp.getCharSignedness() == .unsigned) try w.writeAll("#define __CHAR_UNSIGNED__ 1\n");
    try w.writeAll("#define __CHAR_BIT__ 8\n");

    // int maxs
    try comp.generateIntWidth(w, "BOOL", .bool);
    try comp.generateIntMaxAndWidth(w, "SCHAR", .schar);
    try comp.generateIntMaxAndWidth(w, "SHRT", .short);
    try comp.generateIntMaxAndWidth(w, "INT", .int);
    try comp.generateIntMaxAndWidth(w, "LONG", .long);
    try comp.generateIntMaxAndWidth(w, "LONG_LONG", .long_long);
    try comp.generateIntMaxAndWidth(w, "WCHAR", comp.type_store.wchar);
    // try comp.generateIntMax(w, "WINT", comp.type_store.wchar);
    try comp.generateIntMaxAndWidth(w, "INTMAX", comp.type_store.intmax);
    try comp.generateIntMaxAndWidth(w, "SIZE", comp.type_store.size);
    try comp.generateIntMaxAndWidth(w, "UINTMAX", try comp.type_store.intmax.makeIntUnsigned(comp));
    try comp.generateIntMaxAndWidth(w, "PTRDIFF", comp.type_store.ptrdiff);
    try comp.generateIntMaxAndWidth(w, "INTPTR", comp.type_store.intptr);
    try comp.generateIntMaxAndWidth(w, "UINTPTR", try comp.type_store.intptr.makeIntUnsigned(comp));
    try comp.generateIntMaxAndWidth(w, "SIG_ATOMIC", target_util.sigAtomicType(comp.target));

    // int widths
    try w.print("#define __BITINT_MAXWIDTH__ {d}\n", .{bit_int_max_bits});

    // sizeof types
    try comp.generateSizeofType(w, "__SIZEOF_FLOAT__", .float);
    try comp.generateSizeofType(w, "__SIZEOF_DOUBLE__", .double);
    try comp.generateSizeofType(w, "__SIZEOF_LONG_DOUBLE__", .long_double);
    try comp.generateSizeofType(w, "__SIZEOF_SHORT__", .short);
    try comp.generateSizeofType(w, "__SIZEOF_INT__", .int);
    try comp.generateSizeofType(w, "__SIZEOF_LONG__", .long);
    try comp.generateSizeofType(w, "__SIZEOF_LONG_LONG__", .long_long);
    try comp.generateSizeofType(w, "__SIZEOF_POINTER__", .void_pointer);
    try comp.generateSizeofType(w, "__SIZEOF_PTRDIFF_T__", comp.type_store.ptrdiff);
    try comp.generateSizeofType(w, "__SIZEOF_SIZE_T__", comp.type_store.size);
    try comp.generateSizeofType(w, "__SIZEOF_WCHAR_T__", comp.type_store.wchar);
    // try comp.generateSizeofType(w, "__SIZEOF_WINT_T__", .void_pointer);

    if (target_util.hasInt128(comp.target)) {
        try comp.generateSizeofType(w, "__SIZEOF_INT128__", .int128);
    }

    // various int types
    try comp.generateTypeMacro(w, "__INTPTR_TYPE__", comp.type_store.intptr);
    try comp.generateTypeMacro(w, "__UINTPTR_TYPE__", try comp.type_store.intptr.makeIntUnsigned(comp));

    try comp.generateTypeMacro(w, "__INTMAX_TYPE__", comp.type_store.intmax);
    try comp.generateSuffixMacro("__INTMAX", w, comp.type_store.intptr);

    try comp.generateTypeMacro(w, "__UINTMAX_TYPE__", try comp.type_store.intmax.makeIntUnsigned(comp));
    try comp.generateSuffixMacro("__UINTMAX", w, try comp.type_store.intptr.makeIntUnsigned(comp));

    try comp.generateTypeMacro(w, "__PTRDIFF_TYPE__", comp.type_store.ptrdiff);
    try comp.generateTypeMacro(w, "__SIZE_TYPE__", comp.type_store.size);
    try comp.generateTypeMacro(w, "__WCHAR_TYPE__", comp.type_store.wchar);
    try comp.generateTypeMacro(w, "__CHAR16_TYPE__", comp.type_store.uint_least16_t);
    try comp.generateTypeMacro(w, "__CHAR32_TYPE__", comp.type_store.uint_least32_t);

    try comp.generateExactWidthTypes(w);
    try comp.generateFastAndLeastWidthTypes(w);

    if (target_util.FPSemantics.halfPrecisionType(comp.target)) |half| {
        try generateFloatMacros(w, "FLT16", half, "F16");
    }
    try generateFloatMacros(w, "FLT", target_util.FPSemantics.forType(.float, comp.target), "F");
    try generateFloatMacros(w, "DBL", target_util.FPSemantics.forType(.double, comp.target), "");
    try generateFloatMacros(w, "LDBL", target_util.FPSemantics.forType(.longdouble, comp.target), "L");

    // TODO: clang treats __FLT_EVAL_METHOD__ as a special-cased macro because evaluating it within a scope
    // where `#pragma clang fp eval_method(X)` has been called produces an error diagnostic.
    const flt_eval_method = comp.langopts.fp_eval_method orelse target_util.defaultFpEvalMethod(comp.target);
    try w.print("#define __FLT_EVAL_METHOD__ {d}\n", .{@intFromEnum(flt_eval_method)});

    try w.writeAll(
        \\#define __FLT_RADIX__ 2
        \\#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
        \\
    );

    switch (comp.code_gen_options.pic_level) {
        .none => {},
        .one, .two => {
            try w.print(
                \\#define __pic__ {0d}
                \\#define __PIC__ {0d}
                \\
            , .{@intFromEnum(comp.code_gen_options.pic_level)});
            if (comp.code_gen_options.is_pie) {
                try w.print(
                    \\#define __pie__ {0d}
                    \\#define __PIE__ {0d}
                    \\
                , .{@intFromEnum(comp.code_gen_options.pic_level)});
            }
        },
    }
}

/// Generate builtin macros trying to use mtime as timestamp
pub fn generateBuiltinMacrosFromPath(
    comp: *Compilation,
    sm: *SourceManager,
    system_defines_mode: SystemDefinesMode,
    path: []const u8,
) !SourceManager.Source {
    const stat = sm.cwd.statFile(path) catch return try comp.generateBuiltinMacros(sm, system_defines_mode, null);
    const timestamp: i64 = @intCast(@divTrunc(stat.mtime, std.time.ns_per_s));
    return try comp.generateBuiltinMacros(sm, system_defines_mode, @intCast(std.math.clamp(timestamp, 0, max_timestamp)));
}

/// Generate builtin macros that will be available to each source file.
pub fn generateBuiltinMacros(
    comp: *Compilation,
    sm: *SourceManager,
    system_defines_mode: SystemDefinesMode,
    timestamp: ?u47,
) !SourceManager.Source {
    try comp.type_store.initNamedTypes(comp);

    var buf = std.ArrayList(u8).init(comp.gpa);
    defer buf.deinit();

    if (system_defines_mode == .include_system_defines) {
        try buf.appendSlice(
            \\#define __VERSION__ "Aro
        ++ " " ++ @import("backend").version_str ++ "\"\n" ++
            \\#define __Aro__
            \\
        );
    }

    try buf.appendSlice("#define __STDC__ 1\n");
    try buf.writer().print("#define __STDC_HOSTED__ {d}\n", .{@intFromBool(comp.target.os.tag != .freestanding)});

    // standard macros
    try buf.appendSlice(
        \\#define __STDC_NO_COMPLEX__ 1
        \\#define __STDC_NO_THREADS__ 1
        \\#define __STDC_NO_VLA__ 1
        \\#define __STDC_UTF_16__ 1
        \\#define __STDC_UTF_32__ 1
        \\#define __STDC_EMBED_NOT_FOUND__ 0
        \\#define __STDC_EMBED_FOUND__ 1
        \\#define __STDC_EMBED_EMPTY__ 2
        \\
    );
    if (comp.langopts.standard.StdCVersionMacro()) |stdc_version| {
        try buf.appendSlice("#define __STDC_VERSION__ ");
        try buf.appendSlice(stdc_version);
        try buf.append('\n');
    }

    const provided: ?u47 = comp.getSourceEpoch(max_timestamp) catch blk: {
        try comp.addDiagnostic(.{
            .tag = .invalid_source_epoch,
            .loc = .{ .id = .unused, .byte_offset = 0, .line = 0 },
        }, &.{});
        break :blk null;
    };
    if (provided) |epoch| {
        try generateDateAndTime(buf.writer(), epoch);
    } else {
        try generateDateAndTime(buf.writer(), timestamp);
    }

    if (system_defines_mode == .include_system_defines) {
        try comp.generateSystemDefines(buf.writer());
    }

    return sm.addSourceFromBuffer(comp.gpa, &comp.diagnostics, "<builtin>", buf.items);
}

fn generateFloatMacros(w: anytype, prefix: []const u8, semantics: target_util.FPSemantics, ext: []const u8) !void {
    const denormMin = semantics.chooseValue(
        []const u8,
        .{
            "5.9604644775390625e-8",
            "1.40129846e-45",
            "4.9406564584124654e-324",
            "3.64519953188247460253e-4951",
            "4.94065645841246544176568792868221e-324",
            "6.47517511943802511092443895822764655e-4966",
        },
    );
    const digits = semantics.chooseValue(i32, .{ 3, 6, 15, 18, 31, 33 });
    const decimalDigits = semantics.chooseValue(i32, .{ 5, 9, 17, 21, 33, 36 });
    const epsilon = semantics.chooseValue(
        []const u8,
        .{
            "9.765625e-4",
            "1.19209290e-7",
            "2.2204460492503131e-16",
            "1.08420217248550443401e-19",
            "4.94065645841246544176568792868221e-324",
            "1.92592994438723585305597794258492732e-34",
        },
    );
    const mantissaDigits = semantics.chooseValue(i32, .{ 11, 24, 53, 64, 106, 113 });

    const min10Exp = semantics.chooseValue(i32, .{ -4, -37, -307, -4931, -291, -4931 });
    const max10Exp = semantics.chooseValue(i32, .{ 4, 38, 308, 4932, 308, 4932 });

    const minExp = semantics.chooseValue(i32, .{ -13, -125, -1021, -16381, -968, -16381 });
    const maxExp = semantics.chooseValue(i32, .{ 16, 128, 1024, 16384, 1024, 16384 });

    const min = semantics.chooseValue(
        []const u8,
        .{
            "6.103515625e-5",
            "1.17549435e-38",
            "2.2250738585072014e-308",
            "3.36210314311209350626e-4932",
            "2.00416836000897277799610805135016e-292",
            "3.36210314311209350626267781732175260e-4932",
        },
    );
    const max = semantics.chooseValue(
        []const u8,
        .{
            "6.5504e+4",
            "3.40282347e+38",
            "1.7976931348623157e+308",
            "1.18973149535723176502e+4932",
            "1.79769313486231580793728971405301e+308",
            "1.18973149535723176508575932662800702e+4932",
        },
    );

    try w.print("#define __{s}_DENORM_MIN__ {s}{s}\n", .{ prefix, denormMin, ext });
    try w.print("#define __{s}_HAS_DENORM__\n", .{prefix});
    try w.print("#define __{s}_DIG__ {d}\n", .{ prefix, digits });
    try w.print("#define __{s}_DECIMAL_DIG__ {d}\n", .{ prefix, decimalDigits });

    try w.print("#define __{s}_EPSILON__ {s}{s}\n", .{ prefix, epsilon, ext });
    try w.print("#define __{s}_HAS_INFINITY__\n", .{prefix});
    try w.print("#define __{s}_HAS_QUIET_NAN__\n", .{prefix});
    try w.print("#define __{s}_MANT_DIG__ {d}\n", .{ prefix, mantissaDigits });

    try w.print("#define __{s}_MAX_10_EXP__ {d}\n", .{ prefix, max10Exp });
    try w.print("#define __{s}_MAX_EXP__ {d}\n", .{ prefix, maxExp });
    try w.print("#define __{s}_MAX__ {s}{s}\n", .{ prefix, max, ext });

    try w.print("#define __{s}_MIN_10_EXP__ ({d})\n", .{ prefix, min10Exp });
    try w.print("#define __{s}_MIN_EXP__ ({d})\n", .{ prefix, minExp });
    try w.print("#define __{s}_MIN__ {s}{s}\n", .{ prefix, min, ext });
}

fn generateTypeMacro(comp: *const Compilation, w: anytype, name: []const u8, qt: QualType) !void {
    try w.print("#define {s} ", .{name});
    try qt.print(comp, w);
    try w.writeByte('\n');
}

pub fn float80Type(comp: *const Compilation) ?QualType {
    if (comp.langopts.emulate != .gcc) return null;
    return target_util.float80Type(comp.target);
}

/// Smallest integer type with at least N bits
pub fn intLeastN(comp: *const Compilation, bits: usize, signedness: std.builtin.Signedness) QualType {
    if (bits == 64 and (comp.target.isDarwin() or comp.target.isWasm())) {
        // WebAssembly and Darwin use `long long` for `int_least64_t` and `int_fast64_t`.
        return if (signedness == .signed) .long_long else .ulong_long;
    }
    if (bits == 16 and comp.target.cpu.arch == .avr) {
        // AVR uses int for int_least16_t and int_fast16_t.
        return if (signedness == .signed) .int else .uint;
    }
    const candidates: [5]QualType = switch (signedness) {
        .signed => .{ .schar, .short, .int, .long, .long_long },
        .unsigned => .{ .uchar, .ushort, .uint, .ulong, .ulong_long },
    };
    for (candidates) |qt| {
        if (qt.bitSizeof(comp) >= bits) return qt;
    } else unreachable;
}

fn generateFastOrLeastType(
    comp: *Compilation,
    bits: usize,
    kind: enum { least, fast },
    signedness: std.builtin.Signedness,
    w: anytype,
) !void {
    const ty = comp.intLeastN(bits, signedness); // defining the fast types as the least types is permitted

    var buf: [32]u8 = undefined;
    const suffix = "_TYPE__";
    const base_name = switch (signedness) {
        .signed => "__INT_",
        .unsigned => "__UINT_",
    };
    const kind_str = switch (kind) {
        .fast => "FAST",
        .least => "LEAST",
    };

    const full = std.fmt.bufPrint(&buf, "{s}{s}{d}{s}", .{
        base_name, kind_str, bits, suffix,
    }) catch return error.OutOfMemory;

    try comp.generateTypeMacro(w, full, ty);

    const prefix = full[2 .. full.len - suffix.len]; // remove "__" and "_TYPE__"

    switch (signedness) {
        .signed => try comp.generateIntMaxAndWidth(w, prefix, ty),
        .unsigned => try comp.generateIntMax(w, prefix, ty),
    }
    try comp.generateFmt(prefix, w, ty);
}

fn generateFastAndLeastWidthTypes(comp: *Compilation, w: anytype) !void {
    const sizes = [_]usize{ 8, 16, 32, 64 };
    for (sizes) |size| {
        try comp.generateFastOrLeastType(size, .least, .signed, w);
        try comp.generateFastOrLeastType(size, .least, .unsigned, w);
        try comp.generateFastOrLeastType(size, .fast, .signed, w);
        try comp.generateFastOrLeastType(size, .fast, .unsigned, w);
    }
}

fn generateExactWidthTypes(comp: *Compilation, w: anytype) !void {
    try comp.generateExactWidthType(w, .schar);

    if (QualType.short.sizeof(comp) > QualType.char.sizeof(comp)) {
        try comp.generateExactWidthType(w, .short);
    }

    if (QualType.int.sizeof(comp) > QualType.short.sizeof(comp)) {
        try comp.generateExactWidthType(w, .int);
    }

    if (QualType.long.sizeof(comp) > QualType.int.sizeof(comp)) {
        try comp.generateExactWidthType(w, .long);
    }

    if (QualType.long_long.sizeof(comp) > QualType.long.sizeof(comp)) {
        try comp.generateExactWidthType(w, .long_long);
    }

    try comp.generateExactWidthType(w, .uchar);
    try comp.generateExactWidthIntMax(w, .uchar);
    try comp.generateExactWidthIntMax(w, .schar);

    if (QualType.short.sizeof(comp) > QualType.char.sizeof(comp)) {
        try comp.generateExactWidthType(w, .ushort);
        try comp.generateExactWidthIntMax(w, .ushort);
        try comp.generateExactWidthIntMax(w, .short);
    }

    if (QualType.int.sizeof(comp) > QualType.short.sizeof(comp)) {
        try comp.generateExactWidthType(w, .uint);
        try comp.generateExactWidthIntMax(w, .uint);
        try comp.generateExactWidthIntMax(w, .int);
    }

    if (QualType.long.sizeof(comp) > QualType.int.sizeof(comp)) {
        try comp.generateExactWidthType(w, .ulong);
        try comp.generateExactWidthIntMax(w, .ulong);
        try comp.generateExactWidthIntMax(w, .long);
    }

    if (QualType.long_long.sizeof(comp) > QualType.long.sizeof(comp)) {
        try comp.generateExactWidthType(w, .ulong_long);
        try comp.generateExactWidthIntMax(w, .ulong_long);
        try comp.generateExactWidthIntMax(w, .long_long);
    }
}

fn generateFmt(comp: *const Compilation, prefix: []const u8, w: anytype, qt: QualType) !void {
    const unsigned = qt.signedness(comp) == .unsigned;
    const modifier = qt.formatModifier(comp);
    const formats = if (unsigned) "ouxX" else "di";
    for (formats) |c| {
        try w.print("#define {s}_FMT{c}__ \"{s}{c}\"\n", .{ prefix, c, modifier, c });
    }
}

fn generateSuffixMacro(comp: *const Compilation, prefix: []const u8, w: anytype, qt: QualType) !void {
    return w.print("#define {s}_C_SUFFIX__ {s}\n", .{ prefix, qt.intValueSuffix(comp) });
}

/// Generate the following for a type:
///     Name macro (e.g. #define __UINT32_TYPE__ unsigned int)
///     Format strings (e.g. #define __UINT32_FMTu__ "u")
///     Suffix macro (e.g. #define __UINT32_C_SUFFIX__ U)
fn generateExactWidthType(comp: *Compilation, w: anytype, original_qt: QualType) !void {
    var qt = original_qt;
    const width = qt.sizeof(comp) * 8;
    const unsigned = qt.signedness(comp) == .unsigned;

    if (width == 16) {
        qt = if (unsigned) try comp.type_store.int16.makeIntUnsigned(comp) else comp.type_store.int16;
    } else if (width == 64) {
        qt = if (unsigned) try comp.type_store.int64.makeIntUnsigned(comp) else comp.type_store.int64;
    }

    var buffer: [16]u8 = undefined;
    const suffix = "_TYPE__";
    const full = std.fmt.bufPrint(&buffer, "{s}{d}{s}", .{
        if (unsigned) "__UINT" else "__INT", width, suffix,
    }) catch return error.OutOfMemory;

    try comp.generateTypeMacro(w, full, qt);

    const prefix = full[0 .. full.len - suffix.len]; // remove "_TYPE__"

    try comp.generateFmt(prefix, w, qt);
    try comp.generateSuffixMacro(prefix, w, qt);
}

pub fn hasFloat128(comp: *const Compilation) bool {
    return target_util.hasFloat128(comp.target);
}

pub fn hasHalfPrecisionFloatABI(comp: *const Compilation) bool {
    return comp.langopts.allow_half_args_and_returns or target_util.hasHalfPrecisionFloatABI(comp.target);
}

fn generateIntMax(comp: *const Compilation, w: anytype, name: []const u8, qt: QualType) !void {
    const unsigned = qt.signedness(comp) == .unsigned;
    const max: u128 = switch (qt.bitSizeof(comp)) {
        8 => if (unsigned) std.math.maxInt(u8) else std.math.maxInt(i8),
        16 => if (unsigned) std.math.maxInt(u16) else std.math.maxInt(i16),
        32 => if (unsigned) std.math.maxInt(u32) else std.math.maxInt(i32),
        64 => if (unsigned) std.math.maxInt(u64) else std.math.maxInt(i64),
        128 => if (unsigned) std.math.maxInt(u128) else std.math.maxInt(i128),
        else => unreachable,
    };
    try w.print("#define __{s}_MAX__ {d}{s}\n", .{ name, max, qt.intValueSuffix(comp) });
}

/// Largest value that can be stored in wchar_t
pub fn wcharMax(comp: *const Compilation) u32 {
    const unsigned = comp.type_store.wchar.signedness(comp) == .unsigned;
    return switch (comp.type_store.wchar.bitSizeof(comp)) {
        8 => if (unsigned) std.math.maxInt(u8) else std.math.maxInt(i8),
        16 => if (unsigned) std.math.maxInt(u16) else std.math.maxInt(i16),
        32 => if (unsigned) std.math.maxInt(u32) else std.math.maxInt(i32),
        else => unreachable,
    };
}

fn generateExactWidthIntMax(comp: *Compilation, w: anytype, original_qt: QualType) !void {
    var qt = original_qt;
    const bit_count: u8 = @intCast(qt.sizeof(comp) * 8);
    const unsigned = qt.signedness(comp) == .unsigned;

    if (bit_count == 64) {
        qt = if (unsigned) try comp.type_store.int64.makeIntUnsigned(comp) else comp.type_store.int64;
    }

    var name_buffer: [6]u8 = undefined;
    const name = std.fmt.bufPrint(&name_buffer, "{s}{d}", .{
        if (unsigned) "UINT" else "INT", bit_count,
    }) catch return error.OutOfMemory;

    return comp.generateIntMax(w, name, qt);
}

fn generateIntWidth(comp: *Compilation, w: anytype, name: []const u8, qt: QualType) !void {
    try w.print("#define __{s}_WIDTH__ {d}\n", .{ name, qt.sizeof(comp) * 8 });
}

fn generateIntMaxAndWidth(comp: *Compilation, w: anytype, name: []const u8, qt: QualType) !void {
    try comp.generateIntMax(w, name, qt);
    try comp.generateIntWidth(w, name, qt);
}

fn generateSizeofType(comp: *Compilation, w: anytype, name: []const u8, qt: QualType) !void {
    try w.print("#define {s} {d}\n", .{ name, qt.sizeof(comp) });
}

pub fn nextLargestIntSameSign(comp: *const Compilation, qt: QualType) ?QualType {
    assert(qt.isInt(comp));
    const candidates: [4]QualType = if (qt.signedness(comp) == .signed)
        .{ .short, .int, .long, .long_long }
    else
        .{ .ushort, .uint, .ulong, .ulong_long };

    const size = qt.sizeof(comp);
    for (candidates) |candidate| {
        if (candidate.sizeof(comp) > size) return candidate;
    }
    return null;
}

/// Maximum size of an array, in bytes
pub fn maxArrayBytes(comp: *const Compilation) u64 {
    const max_bits = @min(61, comp.target.ptrBitWidth());
    return (@as(u64, 1) << @truncate(max_bits)) - 1;
}

/// If `enum E { ... }` syntax has a fixed underlying integer type regardless of the presence of
/// __attribute__((packed)) or the range of values of the corresponding enumerator constants,
/// specify it here.
/// TODO: likely incomplete
pub fn fixedEnumTagType(comp: *const Compilation) ?QualType {
    switch (comp.langopts.emulate) {
        .msvc => return .int,
        .clang => if (comp.target.os.tag == .windows) return .int,
        .gcc => {},
    }
    return null;
}

pub fn getCharSignedness(comp: *const Compilation) std.builtin.Signedness {
    return comp.langopts.char_signedness_override orelse comp.target.charSignedness();
}
pub fn addPragmaHandler(comp: *Compilation, name: []const u8, handler: *Pragma) Allocator.Error!void {
    try comp.pragma_handlers.putNoClobber(comp.gpa, name, handler);
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

pub fn hasBuiltin(comp: *const Compilation, name: []const u8) bool {
    if (std.mem.eql(u8, name, "__builtin_va_arg") or
        std.mem.eql(u8, name, "__builtin_choose_expr") or
        std.mem.eql(u8, name, "__builtin_bitoffsetof") or
        std.mem.eql(u8, name, "__builtin_offsetof") or
        std.mem.eql(u8, name, "__builtin_types_compatible_p")) return true;

    const builtin = Builtin.fromName(name) orelse return false;
    return comp.hasBuiltinFunction(builtin);
}

pub fn hasBuiltinFunction(comp: *const Compilation, builtin: Builtin) bool {
    if (!target_util.builtinEnabled(comp.target, builtin.properties.target_set)) return false;

    switch (builtin.properties.language) {
        .all_languages => return true,
        .all_ms_languages => return comp.langopts.emulate == .msvc,
        .gnu_lang, .all_gnu_languages => return comp.langopts.standard.isGNU(),
    }
}

pub const CharUnitSize = enum(u32) {
    @"1" = 1,
    @"2" = 2,
    @"4" = 4,

    pub fn Type(comptime self: CharUnitSize) type {
        return switch (self) {
            .@"1" => u8,
            .@"2" => u16,
            .@"4" => u32,
        };
    }
};

pub const addDiagnostic = Diagnostics.add;
