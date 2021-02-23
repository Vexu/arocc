const Type = @This();

pub const Qualifiers = struct {
    @"const": bool = false,
    atomic: bool = false,
    @"volatile": bool = false,
    restrict: bool = false,
};

pub const Specifier = union(enum) {
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
        decl: TagIndex,
    },

    pub const Record = struct {
        decl: TagIndex,
        fields: []Field,

        pub const Field = struct {
            type: QualType,
            name: []const u8,
        };
    };
};

pub const QualType = packed struct {
    type: Type,
    qual: Qualifiers,
};

pub const DeclSpec = struct {
    storage_class: union(enum) {
        auto,
        @"extern",
        register,
        static,
        typedef,
        none,
    } = .None,
    thread_local: bool,
    type_spec: TypeSpec = .{},
    fn_spec: union(enum) {
        @"inline",
        @"noreturn",
        none,
    } = .None,
    alignment: u32,
};

specifier: Specifier,
alignment: u32 = 0,
