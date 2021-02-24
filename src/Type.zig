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
    /// Will default to uint
    unsigned,
    /// Will default to int
    signed,
    /// Will default to complex_long_double
    complex_long,
    /// Will default to complex_double
    complex,

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
        len: u64,
        static: bool,
        elem: *Type,
    },
    incomplete_enum,
    incomplete_struct,
    incomplete_union,

    typedef: *Type,
    @"struct": Record,
    @"union": Record,
    @"enum": struct {
        // decl: TagIndex,
    },

    pub const Record = struct {
        // decl: TagIndex,
        fields: []Field,

        pub const Field = struct {
            type: Type,
            name: []const u8,
        };
    };

    pub fn str(spec: Specifier) []const u8 {
        return switch (spec) {
            .none => unreachable,

            .unsigned => "unsigned",
            .signed => "signed",
            .complex_long => "_Complex long",
            .complex => "_Complex",
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
