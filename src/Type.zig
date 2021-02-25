const NodeIndex = @import("Tree.zig").NodeIndex;
const Type = @This();

pub const Qualifiers = struct {
    @"const": bool = false,
    atomic: bool = false,
    @"volatile": bool = false,
    restrict: bool = false,
};

pub const Specifier = union(enum) {
    /// Will always be defaulted to int
    none,

    void,
    bool,

    // integers
    char,
    schar,
    uchar,
    short,
    ushort,
    int,
    uint,
    long,
    ulong,
    long_long,
    ulong_long,

    // floating point numbers
    float,
    double,
    long_double,
    complex_float,
    complex_double,
    complex_long_double,

    pointer: struct {
        qual: Qualifiers,
        elem: *Type,
    },
    function: struct {
        return_type: *Type,
        param_types: []Type,
    },

    /// Decays to pointer
    array: struct {
        qual: Qualifiers,
        len: u64,
        static: bool,
        elem: *Type,
    },
    @"struct": NodeIndex,
    @"union": NodeIndex,
    @"enum": NodeIndex,

    pub fn str(spec: Specifier) []const u8 {
        return switch (spec) {
            .none => unreachable,

            .void => "void",
            .bool => "_Bool",
            .char => "char",
            .schar => "signed char",
            .uchar => "unsigned char",
            .short => "short",
            .ushort => "unsigned short",
            .int => "int",
            .uint => "unsigned int",
            .long => "long",
            .ulong => "unsigned long",
            .long_long => "long long",
            .ulong_long => "unsigned long long",
            .float => "float",
            .double => "double",
            .long_double => "long double",
            .complex_float => "_Complex float",
            .complex_double => "_Complex double",
            .complex_long_double => "_Complex long double",

            else => "TODO Specifier.str",
        };
    }
};

qual: Qualifiers = .{},
specifier: Specifier = .none,
alignment: u32 = 0,
