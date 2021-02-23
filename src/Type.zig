const Type = @This();

pub const Qualifiers = struct {
    @"const": bool = false,
    atomic: bool = false,
    @"volatile": bool = false,
    restrict: bool = false,
};

pub const Specifier = union(enum) {
    none, // Will always be defaulted to int

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
};

qual: Qualifiers = .{},
specifier: Specifier = .none,
alignment: u32 = 0,
