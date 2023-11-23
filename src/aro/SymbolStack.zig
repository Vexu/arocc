const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;
const Tree = @import("Tree.zig");
const Token = Tree.Token;
const TokenIndex = Tree.TokenIndex;
const NodeIndex = Tree.NodeIndex;
const Type = @import("Type.zig");
const Parser = @import("Parser.zig");
const Value = @import("Value.zig");
const StringId = @import("StringInterner.zig").StringId;

const SymbolStack = @This();

pub const Symbol = struct {
    name: StringId,
    ty: Type,
    tok: TokenIndex,
    node: NodeIndex = .none,
    kind: Kind,
    val: Value,
};

pub const Kind = enum {
    typedef,
    @"struct",
    @"union",
    @"enum",
    decl,
    def,
    enumeration,
    constexpr,
};

scopes: std.ArrayListUnmanaged(Scope) = .{},
innermost: usize = 0,

const Scope = struct {
    vars: std.AutoHashMapUnmanaged(StringId, Symbol) = .{},
    tags: std.AutoHashMapUnmanaged(StringId, Symbol) = .{},

    fn deinit(self: *Scope, allocator: Allocator) void {
        self.vars.deinit(allocator);
        self.tags.deinit(allocator);
    }

    fn clearRetainingCapacity(self: *Scope) void {
        self.vars.clearRetainingCapacity();
        self.tags.clearRetainingCapacity();
    }
};

pub fn deinit(s: *SymbolStack, gpa: Allocator) void {
    std.debug.assert(s.innermost == std.math.maxInt(@TypeOf(s.innermost)));
    for (s.scopes.items) |*scope| {
        scope.deinit(gpa);
    }
    s.scopes.deinit(gpa);
    s.* = undefined;
}

pub fn pushScope(s: *SymbolStack, p: *Parser) !void {
    if (s.innermost + 1 >= s.scopes.items.len) {
        s.innermost = s.scopes.items.len;
        try s.scopes.append(p.gpa, .{});
    } else {
        s.innermost += 1;
        s.scopes.items[s.innermost].clearRetainingCapacity();
    }
}

pub fn popScope(s: *SymbolStack) void {
    s.innermost -%= 1;
}

pub fn findTypedef(s: *SymbolStack, p: *Parser, name: StringId, name_tok: TokenIndex, no_type_yet: bool) !?Symbol {
    const prev = s.lookup(name, .vars) orelse s.lookup(name, .tags) orelse return null;
    switch (prev.kind) {
        .typedef => return prev,
        .@"struct" => {
            if (no_type_yet) return null;
            try p.errStr(.must_use_struct, name_tok, p.tokSlice(name_tok));
            return prev;
        },
        .@"union" => {
            if (no_type_yet) return null;
            try p.errStr(.must_use_union, name_tok, p.tokSlice(name_tok));
            return prev;
        },
        .@"enum" => {
            if (no_type_yet) return null;
            try p.errStr(.must_use_enum, name_tok, p.tokSlice(name_tok));
            return prev;
        },
        else => return null,
    }
}

pub fn findSymbol(s: *SymbolStack, name: StringId) ?Symbol {
    return s.lookup(name, .vars);
}

pub fn findTag(
    s: *SymbolStack,
    p: *Parser,
    name: StringId,
    kind: Token.Id,
    name_tok: TokenIndex,
    next_tok_id: Token.Id,
) !?Symbol {
    // `tag Name;` should always result in a new type if in a new scope.
    const prev = (if (next_tok_id == .semicolon) s.get(name, .tags) else s.lookup(name, .tags)) orelse return null;
    switch (prev.kind) {
        .@"enum" => if (kind == .keyword_enum) return prev,
        .@"struct" => if (kind == .keyword_struct) return prev,
        .@"union" => if (kind == .keyword_union) return prev,
        else => unreachable,
    }
    if (s.get(name, .tags) == null) return null;
    try p.errStr(.wrong_tag, name_tok, p.tokSlice(name_tok));
    try p.errTok(.previous_definition, prev.tok);
    return null;
}

const ScopeKind = enum {
    vars,
    tags,
};

pub fn get(s: *SymbolStack, name: StringId, kind: ScopeKind) ?Symbol {
    return switch (kind) {
        .vars => s.scopes.items[s.innermost].vars.get(name),
        .tags => s.scopes.items[s.innermost].tags.get(name),
    };
}

fn lookup(s: *SymbolStack, name: StringId, kind: ScopeKind) ?Symbol {
    var i = s.innermost + 1;
    while (i > 0) {
        i -= 1;
        switch (kind) {
            .vars => if (s.scopes.items[i].vars.get(name)) |sym| return sym,
            .tags => if (s.scopes.items[i].tags.get(name)) |sym| return sym,
        }
    }
    return null;
}

pub fn define(s: *SymbolStack, allocator: Allocator, symbol: Symbol) !void {
    switch (symbol.kind) {
        .constexpr, .def, .decl, .enumeration, .typedef => {
            try s.scopes.items[s.innermost].vars.put(allocator, symbol.name, symbol);
        },
        .@"struct", .@"union", .@"enum" => {
            try s.scopes.items[s.innermost].tags.put(allocator, symbol.name, symbol);
        },
    }
}

pub fn defineTypedef(
    s: *SymbolStack,
    p: *Parser,
    name: StringId,
    ty: Type,
    tok: TokenIndex,
    node: NodeIndex,
) !void {
    if (s.get(name, .vars)) |prev| {
        if (!ty.eql(prev.ty, p.comp, true)) {
            try p.errStr(.redefinition_of_typedef, tok, try p.typePairStrExtra(ty, " vs ", prev.ty));
            if (prev.tok != 0) try p.errTok(.previous_definition, prev.tok);
        }
    }
    try s.define(p.gpa, .{
        .kind = .typedef,
        .name = name,
        .tok = tok,
        .ty = ty,
        .node = node,
        .val = .{},
    });
}

pub fn defineSymbol(
    s: *SymbolStack,
    p: *Parser,
    name: StringId,
    ty: Type,
    tok: TokenIndex,
    node: NodeIndex,
    val: Value,
    constexpr: bool,
) !void {
    if (s.get(name, .vars)) |prev| {
        switch (prev.kind) {
            .enumeration => {
                try p.errStr(.redefinition_different_sym, tok, p.tokSlice(tok));
                try p.errTok(.previous_definition, prev.tok);
            },
            .decl => {
                if (!ty.eql(prev.ty, p.comp, true)) {
                    try p.errStr(.redefinition_incompatible, tok, p.tokSlice(tok));
                    try p.errTok(.previous_definition, prev.tok);
                }
            },
            .def, .constexpr => {
                try p.errStr(.redefinition, tok, p.tokSlice(tok));
                try p.errTok(.previous_definition, prev.tok);
            },
            .typedef => {}, // TODO typedef
            else => unreachable,
        }
    }

    try s.define(p.gpa, .{
        .kind = if (constexpr) .constexpr else .def,
        .name = name,
        .tok = tok,
        .ty = ty,
        .node = node,
        .val = val,
    });
}

pub fn getPtr(s: *SymbolStack, name: StringId, kind: ScopeKind) *Symbol {
    return switch (kind) {
        .tags => s.scopes.items[s.innermost].tags.getPtr(name).?,
        .vars => s.scopes.items[s.innermost].vars.getPtr(name).?,
    };
}

pub fn declareSymbol(
    s: *SymbolStack,
    p: *Parser,
    name: StringId,
    ty: Type,
    tok: TokenIndex,
    node: NodeIndex,
) !void {
    if (s.get(name, .vars)) |prev| {
        switch (prev.kind) {
            .enumeration => {
                try p.errStr(.redefinition_different_sym, tok, p.tokSlice(tok));
                try p.errTok(.previous_definition, prev.tok);
            },
            .decl => {
                if (!ty.eql(prev.ty, p.comp, true)) {
                    try p.errStr(.redefinition_incompatible, tok, p.tokSlice(tok));
                    try p.errTok(.previous_definition, prev.tok);
                }
            },
            .def, .constexpr => {
                if (!ty.eql(prev.ty, p.comp, true)) {
                    try p.errStr(.redefinition_incompatible, tok, p.tokSlice(tok));
                    try p.errTok(.previous_definition, prev.tok);
                } else {
                    return;
                }
            },
            .typedef => {}, //todo typedef
            else => unreachable,
        }
    }
    try s.define(p.gpa, .{
        .kind = .decl,
        .name = name,
        .tok = tok,
        .ty = ty,
        .node = node,
        .val = .{},
    });
}

pub fn defineParam(s: *SymbolStack, p: *Parser, name: StringId, ty: Type, tok: TokenIndex) !void {
    if (s.get(name, .vars)) |prev| {
        switch (prev.kind) {
            .enumeration, .decl, .def, .constexpr => {
                try p.errStr(.redefinition_of_parameter, tok, p.tokSlice(tok));
                try p.errTok(.previous_definition, prev.tok);
            },
            .typedef => {}, //todo typedef
            else => unreachable,
        }
    }
    if (ty.is(.fp16) and !p.comp.hasHalfPrecisionFloatABI()) {
        try p.errStr(.suggest_pointer_for_invalid_fp16, tok, "parameters");
    }
    try s.define(p.gpa, .{
        .kind = .def,
        .name = name,
        .tok = tok,
        .ty = ty,
        .val = .{},
    });
}

pub fn defineTag(
    s: *SymbolStack,
    p: *Parser,
    name: StringId,
    kind: Token.Id,
    tok: TokenIndex,
) !?Symbol {
    const prev = s.get(name, .tags) orelse return null;
    switch (prev.kind) {
        .@"enum" => {
            if (kind == .keyword_enum) return prev;
            try p.errStr(.wrong_tag, tok, p.tokSlice(tok));
            try p.errTok(.previous_definition, prev.tok);
            return null;
        },
        .@"struct" => {
            if (kind == .keyword_struct) return prev;
            try p.errStr(.wrong_tag, tok, p.tokSlice(tok));
            try p.errTok(.previous_definition, prev.tok);
            return null;
        },
        .@"union" => {
            if (kind == .keyword_union) return prev;
            try p.errStr(.wrong_tag, tok, p.tokSlice(tok));
            try p.errTok(.previous_definition, prev.tok);
            return null;
        },
        else => unreachable,
    }
}

pub fn defineEnumeration(
    s: *SymbolStack,
    p: *Parser,
    name: StringId,
    ty: Type,
    tok: TokenIndex,
    val: Value,
) !void {
    if (s.get(name, .vars)) |prev| {
        switch (prev.kind) {
            .enumeration => {
                try p.errStr(.redefinition, tok, p.tokSlice(tok));
                try p.errTok(.previous_definition, prev.tok);
                return;
            },
            .decl, .def, .constexpr => {
                try p.errStr(.redefinition_different_sym, tok, p.tokSlice(tok));
                try p.errTok(.previous_definition, prev.tok);
                return;
            },
            .typedef => {}, //todo typedef
            else => unreachable,
        }
    }
    try s.define(p.gpa, .{
        .kind = .enumeration,
        .name = name,
        .tok = tok,
        .ty = ty,
        .val = val,
    });
}
