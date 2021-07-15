test "var args macro functions" {
    try expectStr(
        \\#define foo(a,...) #__VA_ARGS__
        \\foo(1,2,3,4,5,6)
        \\
        \\#define bar(a,...) bar __VA_ARGS__
        \\#define baz(a,...) baz bar(__VA_ARGS__)
        \\baz(1,2,3,4)
    , "\"2 , 3 , 4 , 5 , 6\" baz bar 3 , 4\n");
}

test "X macro" {
    try expectStr(
        \\#define X(a) Foo_ ## a = a,
        \\enum Foo {
        \\X(1)
        \\X(2)
        \\X(3)
        \\X(4)
        \\X(5)
        \\};
    , "enum Foo { Foo_1 = 1 , Foo_2 = 2 , Foo_3 = 3 , Foo_4 = 4 , Foo_5 = 5 , } ;\n");
}

test "function macro expansion" {
    try expectStr(
        \\#define HE HI
        \\#define LLO _THERE
        \\#define HELLO "HI THERE"
        \\#define CAT(a,b) a##b
        \\#define XCAT(a,b) CAT(a,b)
        \\#define CALL(fn) fn(HE,LLO)
        \\CAT(HE, LLO)
        \\XCAT(HE, LLO)
        \\CALL(CAT)
    , "\"HI THERE\" HI_THERE \"HI THERE\"\n");
}

test "#if constant expression" {
    try expectStr(
        \\#if defined FOO
        \\void
        \\#elif !defined(BAR)
        \\long
        \\#endif
    , "long\n");
}

test "nested #ifs" {
    try expectStr(
        \\#define FOO
        \\#ifdef FOO
        \\#ifdef FOO
        \\#else
        \\#endif
        \\#endif
    , "");
}

test "object macro token pasting" {
    try expectStr(
        \\#define x a##1
        \\x
        \\#define a 1
        \\x
    , "a1 a1\n");
}

test "recursive object macro" {
    try expectStr(
        \\#define y x
        \\#define x y
        \\x
    , "x\n");
    try expectStr(
        \\#define x x
        \\x
    , "x\n");
}

test "object macro expansion" {
    try expectTokens(
        \\#define x a
        \\x
        \\#define a 1
        \\x
    , &.{ .identifier, .integer_literal });
    try expectTokens(
        \\#define x define
        \\x
    , &.{.identifier});
}

test "ifdef" {
    try expectTokens(
        \\#define FOO
        \\#ifdef FOO
        \\long
        \\#else
        \\int
        \\#endif
    , &.{.keyword_long});

    try expectTokens(
        \\#define BAR
        \\#ifdef FOO
        \\long
        \\#else
        \\int
        \\#endif
    , &.{.keyword_int});
}

test "define undefin" {
    try expectTokens(
        \\#define FOO 1
        \\#undef FOO
    , &.{});
}

const std = @import("std");
const aro = @import("aro");
const Source = aro.Source;
const Token = aro.Tokenizer.Token;
const Preprocessor = aro.Preprocessor;
const Compilation = aro.Compilation;

fn expectTokens(buf: []const u8, expected_tokens: []const Token.Id) !void {
    var comp = Compilation.init(std.testing.allocator);
    defer comp.deinit();

    const source = Source{
        .buf = buf,
        .id = @intToEnum(Source.Id, 2),
        .path = "<test-buf>",
    };
    try comp.sources.putNoClobber(source.path, source);
    defer comp.sources.clearAndFree();

    var pp = Preprocessor.init(&comp);
    defer pp.deinit();

    try pp.preprocess(source);
    comp.renderErrors();
    try std.testing.expect(comp.diag.errors == 0);

    for (expected_tokens) |expected_token_id, i| {
        const actual = pp.tokens.items(.id)[i];
        if (!std.meta.eql(actual, expected_token_id)) {
            std.debug.print("expected {s}, found {s}\n", .{ @tagName(expected_token_id), @tagName(actual) });
            return error.TokensDoNotEqual;
        }
    }
}

fn expectStr(buf: []const u8, expected: []const u8) !void {
    var comp = Compilation.init(std.testing.allocator);
    defer comp.deinit();

    const source = Source{
        .buf = buf,
        .id = @intToEnum(Source.Id, 2),
        .path = "<test-buf>",
    };
    try comp.sources.putNoClobber(source.path, source);
    defer comp.sources.clearAndFree();

    var pp = Preprocessor.init(&comp);
    defer pp.deinit();

    try pp.preprocess(source);
    try pp.tokens.append(comp.gpa, .{ .id = .eof, .loc = undefined });
    comp.renderErrors();
    try std.testing.expect(comp.diag.errors == 0);

    var actual = std.ArrayList(u8).init(std.testing.allocator);
    defer actual.deinit();

    try pp.prettyPrintTokens(actual.writer());

    try std.testing.expectEqualStrings(expected, actual.items);
}
