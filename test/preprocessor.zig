test "recursive object macro" {
    expectTokens(
        \\#define y x
        \\#define x y
        \\x
    , &.{.identifier});
    expectTokens(
        \\#define x x
        \\x
    , &.{.identifier});
}

test "object macro expansion" {
    expectTokens(
        \\#define x a
        \\x
        \\#define a 1
        \\x
    , &.{ .identifier, .integer_literal });
    expectTokens(
        \\#define x define
        \\x
    , &.{.identifier});
}

test "ifdef" {
    expectTokens(
        \\#define FOO
        \\#ifdef FOO
        \\long
        \\#else
        \\int
        \\#endif
    , &.{.keyword_long});

    expectTokens(
        \\#define BAR
        \\#ifdef FOO
        \\long
        \\#else
        \\int
        \\#endif
    , &.{.keyword_int});
}

test "define undefin" {
    expectTokens(
        \\#define FOO 1
        \\#undef FOO
    , &.{});
}

const std = @import("std");
const sfcc = @import("sfcc");
const Token = sfcc.Tokenizer.Token;
const Preprocessor = sfcc.Preprocessor;
const Compilation = sfcc.Compilation;

fn expectTokens(source: []const u8, expected_tokens: []const Token.Id) void {
    var comp = Compilation.init(std.testing.allocator);
    defer comp.deinit();

    var pp = Preprocessor.init(&comp);
    defer pp.deinit();

    pp.preprocess(.{
        .buf = source,
        .id = 0,
        .path = "<test-buf>",
    }) catch unreachable;

    for (expected_tokens) |expected_token_id, i| {
        const token = pp.tokens.items[i];
        if (!std.meta.eql(token.id, expected_token_id)) {
            std.debug.panic("expected {s}, found {s}\n", .{ @tagName(expected_token_id), @tagName(token.id) });
        }
    }
    const last_token = pp.tokens.items[expected_tokens.len];
    std.testing.expect(last_token.id == .eof);
}
