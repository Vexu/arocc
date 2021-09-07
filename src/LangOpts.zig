const std = @import("std");

const LangOpts = @This();

const Standard = enum {
    /// ISO C 1990
    c89,
    /// ISO C 1990 with GNU extensions
    gnu89,
    /// ISO C 1999
    c99,
    /// ISO C 1999 with GNU extensions
    gnu99,
    /// ISO C 2011
    c11,
    /// ISO C 2011 with GNU extensions
    gnu11,
    /// ISO C 2017
    c17,
    /// ISO C 2017 with GNU extensions
    gnu17,
    /// Working Draft for ISO C2x
    c2x,
    /// Working Draft for ISO C2x with GNU extensions
    gnu2x,
};

standard: Standard = .gnu17,

pub fn hasGNUKeywords(langopts: LangOpts) bool {
    return switch(langopts.standard) {
        .gnu89, .gnu99, .gnu11, .gnu17, .gnu2x => true,
        else => false,
    };
}

pub fn hasC99Keywords(langopts: LangOpts) bool {
    return @enumToInt(langopts.standard) >= @enumToInt(Standard.c99);
}
