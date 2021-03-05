test "var args macro functions" {
    expectStr(
        \\#define foo(a,...) #__VA_ARGS__
        \\foo(1,2,3,4,5,6)
        \\
        \\#define bar(a,...) bar __VA_ARGS__
        \\#define baz(a,...) baz bar(__VA_ARGS__)
        \\baz(1,2,3,4)
    , "\"2 , 3 , 4 , 5 , 6\" baz bar 3 , 4\n");
}

test "X macro" {
    expectStr(
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
    expectStr(
        \\#define HE HI
        \\#define LLO _THERE
        \\#define HELLO "HI THERE"
        \\#define CAT(a,b) a##b
        \\#define XCAT(a,b) CAT(a,b)
        \\#define CALL(fn) fn(HE,LLO)
        \\CAT(HE, LLO)
        \\XCAT(HE, LLO)
        \\CALL(CAT)
    , "\"HI THERE\" HI_THERE \"HI THERE\"");
}

test "#if constant expression" {
    expectStr(
        \\#if defined FOO
        \\void
        \\#elif !defined(BAR)
        \\long
        \\#endif
    , "long");
}

test "nested #ifs" {
    expectStr(
        \\#define FOO
        \\#ifdef FOO
        \\#ifdef FOO
        \\#else
        \\#endif
        \\#endif
    , "");
}

test "object macro token pasting" {
    expectStr(
        \\#define x a##1
        \\x
        \\#define a 1
        \\x
    , "a1 a1");
}

test "recursive object macro" {
    expectStr(
        \\#define y x
        \\#define x y
        \\x
    , "x");
    expectStr(
        \\#define x x
        \\x
    , "x");
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
const aro = @import("aro");
const Source = aro.Source;
const Token = aro.Tokenizer.Token;
const Preprocessor = aro.Preprocessor;
const Compilation = aro.Compilation;

fn expectTokens(buf: []const u8, expected_tokens: []const Token.Id) void {
    var comp = Compilation.init(std.testing.allocator);
    defer comp.deinit();

    const source = Source{
        .buf = buf,
        .id = @intToEnum(Source.Id, 2),
        .path = "<test-buf>",
    };
    comp.sources.putNoClobber(source.path, source) catch unreachable;
    defer comp.sources.clearAndFree();

    var pp = Preprocessor.init(&comp);
    defer pp.deinit();

    pp.preprocess(source) catch unreachable;
    comp.renderErrors();
    std.testing.expect(comp.diag.errors == 0);

    for (expected_tokens) |expected_token_id, i| {
        const actual = pp.tokens.items(.id)[i];
        if (!std.meta.eql(actual, expected_token_id)) {
            std.debug.panic("expected {s}, found {s}\n", .{ @tagName(expected_token_id), @tagName(actual) });
        }
    }
}

fn expectStr(buf: []const u8, expected: []const u8) void {
    var comp = Compilation.init(std.testing.allocator);
    defer comp.deinit();

    const source = Source{
        .buf = buf,
        .id = @intToEnum(Source.Id, 2),
        .path = "<test-buf>",
    };
    comp.sources.putNoClobber(source.path, source) catch unreachable;
    defer comp.sources.clearAndFree();

    var pp = Preprocessor.init(&comp);
    defer pp.deinit();

    pp.preprocess(source) catch unreachable;
    pp.tokens.append(comp.gpa, .{ .id = .eof, .loc = undefined }) catch unreachable;
    comp.renderErrors();
    std.testing.expect(comp.diag.errors == 0);

    var actual = std.ArrayList(u8).init(std.testing.allocator);
    defer actual.deinit();

    pp.prettyPrintTokens(actual.writer()) catch unreachable;

    std.testing.expectEqualStrings(expected, actual.items);
}
