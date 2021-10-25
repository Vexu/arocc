const std = @import("std");
const mem = std.mem;
const Compilation = @import("../Compilation.zig");
const Pragma = @import("../Pragma.zig");
const Diagnostics = @import("../Diagnostics.zig");
const Preprocessor = @import("../Preprocessor.zig");
const Parser = @import("../Parser.zig");
const TokenIndex = @import("../Tree.zig").TokenIndex;

const GCC = @This();

pragma: Pragma = .{
    .beforeParse = beforeParse,
    .beforePreprocess = beforePreprocess,
    .afterParse = afterParse,
    .deinit = deinit,
    .preprocessorHandler = preprocessorHandler,
    .parserHandler = parserHandler,
    .preserveTokens = preserveTokens,
},
originalOptions: Diagnostics.Options = .{},

const Directive = enum {
    warning,
    @"error",
    diagnostic,
    poison,
    const Diagnostics = enum {
        ignored,
        warning,
        @"error",
        fatal,
        push,
        pop,
    };
};

fn beforePreprocess(pragma: *Pragma, comp: *Compilation) void {
    var self = @fieldParentPtr(GCC, "pragma", pragma);
    self.originalOptions = comp.diag.options;
}

fn beforeParse(pragma: *Pragma, comp: *Compilation) void {
    var self = @fieldParentPtr(GCC, "pragma", pragma);
    comp.diag.options = self.originalOptions;
}

fn afterParse(pragma: *Pragma, comp: *Compilation) void {
    var self = @fieldParentPtr(GCC, "pragma", pragma);
    comp.diag.options = self.originalOptions;
}

pub fn init(allocator: *mem.Allocator) !*Pragma {
    var gcc = try allocator.create(GCC);
    gcc.* = .{};
    return &gcc.pragma;
}

fn deinit(pragma: *Pragma, comp: *Compilation) void {
    var self = @fieldParentPtr(GCC, "pragma", pragma);
    comp.gpa.destroy(self);
}

fn diagnosticHandler(pp: *Preprocessor, start_idx: TokenIndex, len: u32) !void {
    if (len == 1) return error.UnknownPragma;
    const diagnostic_tok = pp.tokens.get(start_idx);
    if (std.meta.stringToEnum(Directive.Diagnostics, pp.expandedSlice(diagnostic_tok))) |diagnostic| {
        switch (diagnostic) {
            .ignored, .warning, .@"error", .fatal => {
                const str = Pragma.pasteTokens(pp, start_idx + 1, len - 1) catch |err| switch (err) {
                    error.ExpectedStringLiteral => {
                        return pp.comp.addDiagnostic(.{
                            .tag = .pragma_requires_string_literal,
                            .loc = diagnostic_tok.loc,
                            .extra = .{ .str = "pragma diagnostic" },
                        });
                    },
                    else => |e| return e,
                };
                if (!mem.startsWith(u8, str, "-W")) {
                    return pp.comp.addDiagnostic(.{
                        .tag = .malformed_warning_check,
                        .loc = pp.tokens.get(start_idx + 1).loc,
                        .extra = .{ .str = "pragma diagnostic" },
                    });
                }
                const new_kind = switch (diagnostic) {
                    .ignored => Diagnostics.Kind.off,
                    .warning => Diagnostics.Kind.warning,
                    .@"error" => Diagnostics.Kind.@"error",
                    .fatal => Diagnostics.Kind.@"fatal error",
                    else => unreachable,
                };

                return pp.comp.diag.set(str[2..], new_kind);
            },
            .push, .pop => {},
        }
    }
    return error.UnknownPragma;
}

fn preprocessorHandler(_: *Pragma, pp: *Preprocessor, start_idx: TokenIndex, len: u32) Pragma.Error!void {
    if (len == 1) return;
    const directive_tok = pp.tokens.get(start_idx + 1);
    if (std.meta.stringToEnum(Directive, pp.expandedSlice(directive_tok))) |gcc_pragma| {
        switch (gcc_pragma) {
            .warning, .@"error" => {
                const text = Pragma.pasteTokens(pp, start_idx + 2, len - 2) catch |err| switch (err) {
                    error.ExpectedStringLiteral => {
                        return pp.comp.addDiagnostic(.{
                            .tag = .pragma_requires_string_literal,
                            .loc = directive_tok.loc,
                            .extra = .{ .str = @tagName(gcc_pragma) },
                        });
                    },
                    else => |e| return e,
                };
                const extra = Diagnostics.Message.Extra{ .str = try pp.arena.allocator.dupe(u8, text) };
                const diagnostic_tag: Diagnostics.Tag = if (gcc_pragma == .warning) .pragma_warning_message else .pragma_error_message;
                return pp.comp.addDiagnostic(.{ .tag = diagnostic_tag, .loc = directive_tok.loc, .extra = extra });
            },
            .diagnostic => return diagnosticHandler(pp, start_idx + 2, len - 2),
            .poison => {
                var i: usize = 2;
                while (i < len) : (i += 1) {
                    const tok = pp.tokens.get(start_idx + i);
                    if (!tok.id.isMacroIdentifier()) {
                        return pp.comp.addDiagnostic(.{
                            .tag = .pragma_poison_identifier,
                            .loc = tok.loc,
                        });
                    }
                    const str = pp.expandedSlice(tok);
                    if (pp.defines.get(str) != null) {
                        try pp.comp.addDiagnostic(.{
                            .tag = .pragma_poison_macro,
                            .loc = tok.loc,
                        });
                    }
                    try pp.poisoned_identifiers.put(str, {});
                }
                return;
            },
        }
    }
    return error.UnknownPragma;
}

fn parserHandler(_: *Pragma, p: *Parser, start_idx: TokenIndex, len: u32) Compilation.Error!void {
    if (len == 1) return;
    const directive_tok = p.pp.tokens.get(start_idx + 1);
    const name = p.pp.expandedSlice(directive_tok);
    if (mem.eql(u8, name, "diagnostic")) {
        return diagnosticHandler(p.pp, start_idx + 2, len - 2) catch |err| switch (err) {
            error.UnknownPragma => {}, // handled during preprocessing
            else => |e| return e,
        };
    }
}

fn preserveTokens(_: *Pragma, pp: *Preprocessor, start_idx: TokenIndex, len: u32) bool {
    if (len >= 2) {
        const directive = pp.tokens.get(start_idx + 1);
        const name = pp.expandedSlice(directive);
        if (mem.eql(u8, name, "poison")) {
            return false;
        }
    }
    return true;
}
