const std = @import("std");
const mem = std.mem;
const Compilation = @import("../Compilation.zig");
const Pragma = @import("../Pragma.zig");
const Diagnostics = @import("../Diagnostics.zig");
const Preprocessor = @import("../Preprocessor.zig");
const Parser = @import("../Parser.zig");
const Tree = @import("../Tree.zig");
const TokenIndex = Tree.TokenIndex;

const Pack = @This();

pragma: Pragma = .{
    .deinit = deinit,
    .parserHandler = parserHandler,
    .preserveTokens = preserveTokens,
},
stack: std.ArrayListUnmanaged(struct { label: []const u8, val: u8 }) = .{},

pub fn init(allocator: mem.Allocator) !*Pragma {
    var pack = try allocator.create(Pack);
    pack.* = .{};
    return &pack.pragma;
}

fn deinit(pragma: *Pragma, comp: *Compilation) void {
    var self = @fieldParentPtr(Pack, "pragma", pragma);
    self.stack.deinit(comp.gpa);
    comp.gpa.destroy(self);
}

fn parserHandler(pragma: *Pragma, p: *Parser, start_idx: TokenIndex) Compilation.Error!void {
    var pack = @fieldParentPtr(Pack, "pragma", pragma);
    var idx = start_idx + 1;
    const l_paren = p.pp.tokens.get(idx);
    if (l_paren.id != .l_paren) {
        return p.pp.comp.diag.add(.{
            .tag = .pragma_pack_lparen,
            .loc = l_paren.loc,
        }, l_paren.expansionSlice());
    }
    idx += 1;

    // TODO -fapple-pragma-pack -fxl-pragma-pack
    const apple_or_xl = false;
    const arg = p.pp.tokens.get(idx);
    switch (arg.id) {
        .identifier => {
            idx += 1;
            const Action = enum {
                show,
                push,
                pop,
            };
            const action = std.meta.stringToEnum(Action, p.pp.expandedSlice(arg)) orelse {
                return p.pp.comp.diag.add(.{
                    .tag = .pragma_pack_unknown_action,
                    .loc = arg.loc,
                }, arg.expansionSlice());
            };
            switch (action) {
                .show => {
                    try p.pp.comp.diag.add(.{
                        .tag = .pragma_pack_show,
                        .loc = arg.loc,
                        // .extra = .{ .unsigned = p.pragma_pack },
                        .extra = .{ .unsigned = p.pragma_pack orelse 8 },
                    }, arg.expansionSlice());
                },
                .push, .pop => {
                    var new_val: ?u8 = null;
                    var label: ?[]const u8 = null;
                    if (p.pp.tokens.get(idx).id == .comma) {
                        idx += 1;
                        const next = p.pp.tokens.get(idx);
                        idx += 1;
                        switch (next.id) {
                            .integer_literal => new_val = (try packInt(p, next)) orelse return,
                            .identifier => {
                                label = p.pp.expandedSlice(next);
                                if (p.pp.tokens.get(idx).id == .comma) {
                                    idx += 1;
                                    const int = p.pp.tokens.get(idx);
                                    idx += 1;
                                    if (int.id != .integer_literal) return p.pp.comp.diag.add(.{
                                        .tag = .pragma_pack_int_ident,
                                        .loc = int.loc,
                                    }, int.expansionSlice());

                                    new_val = (try packInt(p, int)) orelse return;
                                }
                            },
                            else => return p.pp.comp.diag.add(.{
                                .tag = .pragma_pack_int_ident,
                                .loc = next.loc,
                            }, next.expansionSlice()),
                        }
                    }
                    if (action == .push) {
                        try pack.stack.append(p.pp.comp.gpa, .{ .label = label orelse "", .val = p.pragma_pack orelse 8 });
                    } else {
                        pack.pop(p, label);
                        if (new_val != null) {
                            try p.pp.comp.diag.add(.{
                                .tag = .pragma_pack_undefined_pop,
                                .loc = arg.loc,
                            }, arg.expansionSlice());
                        } else if (pack.stack.items.len == 0) {
                            try p.pp.comp.diag.add(.{
                                .tag = .pragma_pack_empty_stack,
                                .loc = arg.loc,
                            }, arg.expansionSlice());
                        }
                    }
                    if (new_val) |some| {
                        p.pragma_pack = some;
                    }
                },
            }
        },
        .r_paren => if (apple_or_xl) {
            pack.pop(p, null);
        } else {
            p.pragma_pack = null;
        },
        .integer_literal => {
            idx += 1;
            const new_val = (try packInt(p, arg)) orelse return;
            if (apple_or_xl) {
                try pack.stack.append(p.pp.comp.gpa, .{ .label = "", .val = p.pragma_pack });
            }
            p.pragma_pack = new_val;
        },
        else => {},
    }

    const r_paren = p.pp.tokens.get(idx);
    if (r_paren.id != .r_paren) {
        return p.pp.comp.diag.add(.{
            .tag = .pragma_pack_rparen,
            .loc = r_paren.loc,
        }, r_paren.expansionSlice());
    }
}

fn packInt(p: *Parser, arg: Tree.Token) Compilation.Error!?u8 {
    const int = std.fmt.parseInt(u8, p.pp.expandedSlice(arg), 10) catch 99;
    switch (int) {
        1, 2, 4, 8, 16 => return int,
        else => {
            try p.pp.comp.diag.add(.{
                .tag = .pragma_pack_int,
                .loc = arg.loc,
            }, arg.expansionSlice());
            return null;
        },
    }
}

fn pop(pack: *Pack, p: *Parser, maybe_label: ?[]const u8) void {
    if (maybe_label) |label| {
        var i = pack.stack.items.len;
        while (i > 0) {
            i -= 1;
            if (std.mem.eql(u8, pack.stack.items[i].label, label)) {
                const prev = pack.stack.orderedRemove(i);
                p.pragma_pack = prev.val;
                return;
            }
        }
    } else {
        const prev = pack.stack.popOrNull() orelse {
            p.pragma_pack = 2;
            return;
        };
        p.pragma_pack = prev.val;
    }
}

fn preserveTokens(_: *Pragma, pp: *Preprocessor, start_idx: TokenIndex) bool {
    _ = pp;
    _ = start_idx;
    return true;
}
