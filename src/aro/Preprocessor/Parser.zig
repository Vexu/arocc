const std = @import("std");
const assert = std.debug.assert;

const Error = @import("../Compilation.zig").Error;
const Diagnostics = @import("../Diagnostics.zig");
const Preprocessor = @import("../Preprocessor.zig");
const Tokenizer = @import("../Tokenizer.zig");
const number_literal = Tokenizer.number_literal;
const text_literal = Tokenizer.text_literal;
const Tree = @import("../Tree.zig");
const Token = Tree.Token;
const TokenWithExpansionLocs = Tree.TokenWithExpansionLocs;

const Parser = @This();

pp: *const Preprocessor,
intmax_width: u8,
tokens: []const TokenWithExpansionLocs,
index: u32 = 0,
eof: TokenWithExpansionLocs,

pub const Value = union(enum) {
    signed: i64,
    unsigned: u64,

    pub fn toBool(v: Value) bool {
        return switch (v) {
            inline else => |b| b != 0,
        };
    }

    pub fn isZero(v: Value) bool {
        return switch (v) {
            inline else => |b| b == 0,
        };
    }

    pub fn toUnsigned(v: *Value, p: *Parser, op_tok: TokenWithExpansionLocs, side: []const u8) !void {
        switch (v.*) {
            .unsigned => {},
            .signed => |s| {
                if (s >= 0) {
                    v.* = .{ .unsigned = @intCast(s) };
                    return;
                }

                v.* = p.value(@as(u64, @bitCast(s)));
                try p.pp.err(op_tok, .convert_to_positive, .{ side, v.unsigned });
            },
        }
    }
};

fn next(p: *Parser) TokenWithExpansionLocs {
    while (p.index < p.tokens.len) {
        defer p.index += 1;
        switch (p.tokens[p.index].id) {
            .whitespace, .comment, .macro_ws => continue,
            else => return p.tokens[p.index],
        }
    }
    p.eof.id = .eof;
    return p.eof;
}

fn peek(p: *Parser) TokenWithExpansionLocs {
    while (p.index < p.tokens.len) {
        switch (p.tokens[p.index].id) {
            .whitespace, .comment, .macro_ws => p.index += 1,
            else => return p.tokens[p.index],
        }
    }
    p.eof.id = .eof;
    return p.eof;
}

pub fn parse(p: *Parser) Error!?Value {
    const val = (try p.binaryExpr(0, true)) orelse return null;

    const last = p.peek();
    if (last.id != .eof) {
        try p.pp.err(last, .invalid_preproc_operator, .{});
    }
    return val;
}

const precedence = std.enums.directEnumArrayDefault(Tree.Token.Id, i8, -1, 0, .{
    .percent = 12,
    .slash = 12,
    .asterisk = 12,
    .plus = 11,
    .minus = 11,
    .angle_bracket_angle_bracket_left = 10,
    .angle_bracket_angle_bracket_right = 10,
    .angle_bracket_left_equal = 9,
    .angle_bracket_left = 9,
    .angle_bracket_right_equal = 9,
    .angle_bracket_right = 9,
    .bang_equal = 8,
    .equal_equal = 8,
    .ampersand = 7,
    .caret = 6,
    .pipe = 5,
    .ampersand_ampersand = 4,
    .pipe_pipe = 3,
    .question_mark = 2,
    .comma = 1,
});

fn binaryExpr(p: *Parser, min_prec: i8, eval: bool) Error!?Value {
    assert(min_prec >= 0);
    var lhs = try p.primaryExpr(eval) orelse return null;

    while (true) {
        const tok = p.peek();
        const op_prec = precedence[@backingInt(tok.id)];
        if (op_prec < min_prec) {
            break;
        }

        const operator = p.next();
        const eval_rhs = switch (operator.id) {
            .ampersand_ampersand => eval and lhs.toBool(),
            .pipe_pipe => eval and !lhs.toBool(),
            .question_mark => eval and lhs.toBool(),
            else => eval,
        };
        var rhs = try p.binaryExpr(op_prec + 1, eval_rhs) orelse return null;

        // Usual arithmetic conversion
        switch (operator.id) {
            .question_mark,
            .angle_bracket_angle_bracket_left,
            .angle_bracket_angle_bracket_right,
            .comma,
            .pipe_pipe,
            .ampersand_ampersand,
            => {},
            else => if (lhs == .unsigned or rhs == .unsigned) {
                if (eval) {
                    try lhs.toUnsigned(p, operator, "left");
                    try rhs.toUnsigned(p, operator, "right");
                } else {
                    lhs = .{ .unsigned = 0 };
                    rhs = .{ .unsigned = 0 };
                }
            },
        }
        var overflow: u1 = 0;
        switch (operator.id) {
            .percent => if (!rhs.isZero()) switch (lhs) {
                .signed => |s| {
                    if (s == std.math.minInt(i64) and rhs.signed == -1) {
                        lhs = p.value(0);
                    } else {
                        lhs = p.value(@rem(s, rhs.signed));
                    }
                },
                .unsigned => |u| {
                    lhs = p.value(u % rhs.unsigned);
                },
            } else if (eval) {
                try p.pp.err(operator, .division_by_zero, .{"remainder"});
                return null;
            },
            .slash => if (!rhs.isZero()) switch (lhs) {
                .signed => |s| {
                    lhs = p.value(@divTrunc(s, rhs.signed));
                },
                .unsigned => |u| {
                    lhs = p.value(u / rhs.unsigned);
                },
            } else if (eval) {
                try p.pp.err(operator, .division_by_zero, .{"division"});
                return null;
            },
            .asterisk => switch (lhs) {
                .signed => |s| {
                    const prod, overflow = @mulWithOverflow(s, rhs.signed);
                    lhs = p.value(prod);
                },
                .unsigned => |u| {
                    lhs = p.value(u *% rhs.unsigned);
                },
            },
            .plus => switch (lhs) {
                .signed => |s| {
                    const sum, overflow = @addWithOverflow(s, rhs.signed);
                    lhs = p.value(sum);
                },
                .unsigned => |u| {
                    lhs = p.value(u +% rhs.unsigned);
                },
            },
            .minus => switch (lhs) {
                .signed => |s| {
                    const diff, overflow = @subWithOverflow(s, rhs.signed);
                    lhs = p.value(diff);
                },
                .unsigned => |u| {
                    lhs = p.value(u -% rhs.unsigned);
                },
            },
            .angle_bracket_angle_bracket_left => switch (rhs) {
                inline else => |amt| if (amt < 0 or amt >= p.intmax_width) {
                    overflow = 1;
                    switch (lhs) {
                        inline else => |*v| v.* = 0,
                    }
                } else switch (lhs) {
                    inline else => |v| switch (p.intmax_width) {
                        inline 32, 64 => |t| {
                            const T = @TypeOf(v);
                            const ShiftT = @Int(@typeInfo(T).int.signedness, t);
                            const res, overflow = @shlWithOverflow(
                                @as(ShiftT, @intCast(v)),
                                @as(std.math.Log2Int(ShiftT), @intCast(amt)),
                            );
                            lhs = p.value(@as(T, res));
                        },
                        else => unreachable,
                    },
                },
            },
            .angle_bracket_angle_bracket_right => switch (rhs) {
                inline else => |amt| if (amt < 0) {
                    overflow = 1;
                    switch (lhs) {
                        inline else => |*v| v.* = 0,
                    }
                } else switch (lhs) {
                    inline else => |v| {
                        if (amt >= p.intmax_width) {
                            overflow = 1;
                            lhs = p.value(v >> @as(u6, @intCast(p.intmax_width - 1)));
                        } else {
                            lhs = p.value(v >> @as(u6, @intCast(amt)));
                        }
                    },
                },
            },
            .angle_bracket_left_equal => switch (lhs) {
                .signed => |s| {
                    lhs = p.value(s <= rhs.signed);
                },
                .unsigned => |u| {
                    lhs = p.value(u <= rhs.unsigned);
                },
            },
            .angle_bracket_left => switch (lhs) {
                .signed => |s| {
                    lhs = p.value(s < rhs.signed);
                },
                .unsigned => |u| {
                    lhs = p.value(u < rhs.unsigned);
                },
            },
            .angle_bracket_right_equal => switch (lhs) {
                .signed => |s| {
                    lhs = p.value(s >= rhs.signed);
                },
                .unsigned => |u| {
                    lhs = p.value(u >= rhs.unsigned);
                },
            },
            .angle_bracket_right => switch (lhs) {
                .signed => |s| {
                    lhs = p.value(s > rhs.signed);
                },
                .unsigned => |u| {
                    lhs = p.value(u > rhs.unsigned);
                },
            },
            .bang_equal => switch (lhs) {
                .signed => |s| {
                    lhs = p.value(s != rhs.signed);
                },
                .unsigned => |u| {
                    lhs = p.value(u != rhs.unsigned);
                },
            },
            .equal_equal => switch (lhs) {
                .signed => |s| {
                    lhs = p.value(s == rhs.signed);
                },
                .unsigned => |u| {
                    lhs = p.value(u == rhs.unsigned);
                },
            },
            .ampersand => switch (lhs) {
                .signed => |s| {
                    lhs = p.value(s & rhs.signed);
                },
                .unsigned => |u| {
                    lhs = p.value(u & rhs.unsigned);
                },
            },
            .caret => switch (lhs) {
                .signed => |s| {
                    lhs = p.value(s ^ rhs.signed);
                },
                .unsigned => |u| {
                    lhs = p.value(u ^ rhs.unsigned);
                },
            },
            .pipe => switch (lhs) {
                .signed => |s| {
                    lhs = p.value(s | rhs.signed);
                },
                .unsigned => |u| {
                    lhs = p.value(u | rhs.unsigned);
                },
            },
            .ampersand_ampersand => {
                lhs = p.value(lhs.toBool() and rhs.toBool());
            },
            .pipe_pipe => {
                lhs = p.value(lhs.toBool() or rhs.toBool());
            },
            .question_mark => {
                const colon = p.next();
                if (colon.id != .colon) {
                    try p.pp.err(colon, .expected_colon, .{});
                    try p.pp.err(operator, .to_match_question, .{});
                    return null;
                }

                const eval_else = eval and lhs.isZero();
                const else_res = try p.binaryExpr(op_prec, eval_else) orelse return null;

                lhs = if (lhs.toBool()) rhs else else_res;
                if (eval and rhs == .unsigned or else_res == .unsigned) {
                    try lhs.toUnsigned(p, operator, "right");
                }
            },
            .comma => {
                // Comma operator allowed in C99 if not being evaluated
                if (!p.pp.comp.langopts.standard.atLeast(.c99) or eval) {
                    try p.pp.err(operator, .comma_operator, .{});
                    return null;
                }
                lhs = rhs;
            },
            else => unreachable,
        }

        if (overflow != 0 and eval) {
            try p.pp.err(operator, .overflow, .{});
        }
    }

    return lhs;
}

fn primaryExpr(p: *Parser, eval: bool) Error!?Value {
    loop: switch (p.peek().id) {
        .eof, .r_paren => {
            const eof = p.next();
            try p.pp.err(eof, .expected_value_in_expr, .{});
            return null;
        },
        .l_paren => {
            const l_paren = p.next();
            const res = try p.binaryExpr(0, eval) orelse return null;
            const r_paren = p.next();

            if (r_paren.id != .r_paren) {
                try p.pp.err(r_paren, .closing_paren, .{});
                try p.pp.err(l_paren, .to_match_paren, .{});
            }
            return res;
        },
        .keyword_defined => {
            _ = p.next();

            const l_paren = p.peek();
            if (l_paren.id == .l_paren) {
                _ = p.next();
            }

            const identifier = p.next();
            if (identifier.id == .eof) {
                try p.pp.err(identifier, .macro_name_missing, .{});
                return null;
            } else if (!identifier.id.isMacroIdentifier()) {
                try p.pp.err(identifier, .macro_name_must_be_identifier, .{});
                return null;
            }

            if (l_paren.id == .l_paren) {
                const r_paren = p.next();
                if (r_paren.id != .r_paren) {
                    try p.pp.err(r_paren, .closing_paren, .{});
                    try p.pp.err(l_paren, .to_match_paren, .{});
                }
            }

            const defined = p.pp.defines.contains(p.pp.expandedSlice(identifier));
            return .{ .signed = @intFromBool(defined) };
        },
        .pp_num => {
            const num = p.next();
            var number_literal_parser: number_literal.Parser = .{
                .comp = p.pp.comp,
                .literal = p.pp.expandedSlice(num),
                .loc = num.loc,
                .expansion_locs = num.expansionSlice(),
            };
            const parsed = number_literal_parser.parse() catch |err| switch (err) {
                error.ParsingFailed => return null,
                else => |e| return e,
            };
            if (parsed.is_float or parsed.suffix.isImaginary()) {
                try p.pp.err(num, .float_literal_in_expr, .{});
                return null;
            }

            const base = @backingInt(parsed.prefix);
            var val: u64 = 0;
            var overflow = false;
            for (parsed.bytes) |c| {
                const digit: u64 = switch (c) {
                    '0'...'9' => c - '0',
                    'A'...'Z' => c - 'A' + 10,
                    'a'...'z' => c - 'a' + 10,
                    '\'' => continue,
                    else => unreachable,
                };

                if (val != 0) {
                    const product, const overflowed = @mulWithOverflow(val, base);
                    if (overflowed != 0) {
                        overflow = true;
                    }
                    val = product;
                }
                const sum, const overflowed = @addWithOverflow(val, digit);
                if (overflowed != 0) overflow = true;
                val = sum;
            }
            if (overflow) {
                try p.pp.err(num, .int_literal_too_big, .{});
            }
            if (parsed.suffix.isSignedInteger() and base == 10) {
                const max_int = (@as(u64, 1) << @as(u6, @intCast(p.intmax_width - 1))) - 1;
                if (val > max_int) {
                    try p.pp.err(num, .implicitly_unsigned_literal, .{});
                    return .{ .unsigned = val };
                }
            }
            if (parsed.suffix.isSignedInteger()) {
                return .{ .signed = @intCast(val) };
            } else {
                return .{ .unsigned = val };
            }
        },
        .char_literal,
        .char_literal_utf_8,
        .char_literal_utf_16,
        .char_literal_utf_32,
        .char_literal_wide,
        => {
            const literal = p.next();
            const char_kind = text_literal.Kind.classify(literal.id, .char_literal).?;
            const comp = p.pp.comp;

            var char_literal_parser: text_literal.Parser = .{
                .comp = comp,
                .literal = char_kind.contentSlice(p.pp.expandedSlice(literal)),
                .kind = char_kind,
                .max_codepoint = char_kind.maxCodepoint(comp),
                .loc = literal.loc,
                .expansion_locs = literal.expansionSlice(),
            };
            const parsed = try char_literal_parser.parse();
            const unsigned = switch (parsed) {
                .signed => |s| return .{ .signed = s },
                .unsigned => |u| u,
            };

            const char_literal_qt = char_kind.charLiteralType(comp);
            if (char_literal_qt.signedness(comp) == .unsigned or
                (char_kind == .char and comp.getCharSignedness() == .unsigned))
            {
                return .{ .unsigned = unsigned };
            } else {
                return .{ .signed = unsigned };
            }
        },
        .plus => {
            _ = p.next();
            continue :loop p.peek().id;
        },
        .minus => {
            const minus = p.next();
            const val = try p.primaryExpr(eval) orelse return null;
            switch (val) {
                .signed => |s| {
                    const negated, const overflow = @subWithOverflow(0, s);
                    if (eval and overflow != 0) {
                        try p.pp.err(minus, .overflow, .{});
                    }
                    return p.value(negated);
                },
                .unsigned => |u| {
                    return p.value(0 -% u);
                },
            }
        },
        .tilde => {
            _ = p.next();
            const val = try p.primaryExpr(eval) orelse return null;
            switch (val) {
                inline else => |i| return p.value(~i),
            }
        },
        .bang => {
            _ = p.next();
            const val = try p.primaryExpr(eval) orelse return null;
            return p.value(!val.toBool());
        },
        .keyword_true, .keyword_false => {
            const literal = p.next();
            return p.value(literal.id == .keyword_true);
        },
        else => {
            const maybe_ident = p.next();
            if (maybe_ident.id.isMacroIdentifier()) {
                try p.pp.err(maybe_ident, .undefined_macro, .{p.pp.expandedSlice(maybe_ident)});

                if (p.peek().id == .l_paren) {
                    try p.pp.err(maybe_ident, .fn_macro_undefined, .{p.pp.expandedSlice(maybe_ident)});
                    return null;
                }

                return p.value(0);
            }

            try p.pp.err(maybe_ident, .invalid_preproc_expr_start, .{});
            return null;
        },
    }
}

fn value(p: *Parser, val: anytype) Value {
    return switch (@TypeOf(val)) {
        comptime_int => .{ .signed = val },
        bool => .{ .signed = @intFromBool(val) },
        i64 => switch (p.intmax_width) {
            64 => .{ .signed = val },
            32 => .{ .signed = @as(i32, @truncate(val)) },
            else => unreachable,
        },
        u64 => switch (p.intmax_width) {
            64 => .{ .unsigned = val },
            32 => .{ .unsigned = @as(u32, @truncate(val)) },
            else => unreachable,
        },
        else => @compileError("invalid value"),
    };
}
