// Generates a DAFSA and a companion array of builtin properties from the set of .def
// files from Clang found here:
//
// https://github.com/llvm/llvm-project/tree/main/clang/include/clang/Basic
//
// To generate, run the following command from the root of the repository:
//
// zig run scripts/generate_builtins_dafsa.zig --main-mod-path . -- path/to/Builtins*.def
//
// Current limitations:
// - Can not handle macros that span multiple lines
// - Skips TARGET_BUILTIN, CUSTOM_BUILTIN, and UNALIASED_CUSTOM_BUILTIN

const std = @import("std");
const Allocator = std.mem.Allocator;
const Properties = @import("../src/builtins/Properties.zig");
const TypeDescription = @import("../src/builtins/TypeDescription.zig");

const generated_file_path = "src/builtins/BuiltinFunction.zig";

const BuiltinData = struct {
    param_str: []const u8,
    properties: Properties,
};

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer std.debug.assert(gpa.deinit() == .ok);
    const allocator = gpa.allocator();

    var arena_state = std.heap.ArenaAllocator.init(allocator);
    defer arena_state.deinit();
    const arena = arena_state.allocator();

    var args_it = try std.process.argsWithAllocator(allocator);
    defer args_it.deinit();

    _ = args_it.next();

    var set = std.StringHashMap(BuiltinData).init(allocator);
    defer set.deinit();

    var max_params_count: usize = 0;
    while (args_it.next()) |def_path| {
        var def_contents = try std.fs.cwd().readFileAlloc(allocator, def_path, std.math.maxInt(u32));
        defer allocator.free(def_contents);

        const maybe_target = targetFromFilename(def_path) catch |err| switch (err) {
            error.UnknownTarget => {
                std.debug.print("unknown target for file '{s}', skipping\n", .{def_path});
                continue;
            },
            error.UnexpectedFilename => {
                std.debug.print("unexpected filename: '{s}'\n", .{def_path});
                return err;
            },
        };

        var line_it = std.mem.tokenizeAny(u8, def_contents, "\r\n");
        while (line_it.next()) |line| {
            var param_it = MacroIterator.init(line);
            const macro_str = param_it.next() orelse continue;
            const macro = std.meta.stringToEnum(Macro, macro_str) orelse continue;

            switch (macro) {
                .TARGET_BUILTIN, .CUSTOM_BUILTIN, .UNALIASED_CUSTOM_BUILTIN => continue, // TODO
                else => {},
            }

            const name = param_it.next() orelse continue;
            const params = param_it.next() orelse continue;
            const params_without_quotes = params[1 .. params.len - 1];

            // skip anything with & in it since that's 'by reference'
            if (std.mem.indexOfScalar(u8, params_without_quotes, '&') != null) {
                std.debug.print("{s}: '&' in params str '{s}', skipping\n", .{ name, params_without_quotes });
                continue;
            }

            var params_parser = TypeDescription.TypeIterator.init(params_without_quotes);
            var params_count: usize = 0;
            while (params_parser.next()) |_| {
                params_count += 1;
            }
            if (params_count == 0) {
                // pthread_create has an empty string as its params, so skip it
                if (std.mem.eql(u8, name, "pthread_create")) continue;
                std.debug.print("{s}: failed to parse param string: {s}\n", .{ name, params });
                return error.InvalidParamString;
            }
            // return value is not counted
            params_count -= 1;

            max_params_count = @max(params_count, max_params_count);

            const attrs_str = param_it.next() orelse continue;
            const attrs = attributesFromString(attrs_str);

            var builtin_data = BuiltinData{
                .param_str = params_without_quotes,
                .properties = .{
                    .attributes = attrs,
                    .language = .all_languages,
                    .header = .none,
                    .target_set = Properties.TargetSet.initOne(maybe_target orelse .basic),
                },
            };

            switch (macro) {
                .BUILTIN => {}, // no further params
                .LANGBUILTIN => {
                    const lang = param_it.next() orelse continue;
                    builtin_data.properties.language = allowed_languages_map.get(lang) orelse {
                        std.debug.print("{s}: unknown language '{s}', skipping\n", .{ name, lang });
                        continue;
                    };
                },
                .LIBBUILTIN => {
                    const header = param_it.next() orelse continue;
                    builtin_data.properties.header = header_map.get(header) orelse {
                        std.debug.print("{s}: unknown header '{s}', skipping\n", .{ name, header });
                        continue;
                    };
                    const lang = param_it.next() orelse continue;
                    builtin_data.properties.language = allowed_languages_map.get(lang) orelse {
                        std.debug.print("{s}: unknown language '{s}', skipping\n", .{ name, lang });
                        continue;
                    };
                },
                else => @panic("TODO unsupported BUILTIN macro"),
            }

            if (!param_it.isAtEnd()) {
                std.debug.print("{s}: expected end of macro but '{s}' remains, skipping\n", .{ name, param_it.token_it.buffer[param_it.token_it.index..] });
                continue;
            }

            var result = try set.getOrPut(name);
            if (result.found_existing) {
                if (!equivalentPrototypes(result.value_ptr.*, builtin_data)) {
                    result.value_ptr.param_str = "!";
                    std.debug.print("{s}: param_str changed to \"!\"\n", .{name});
                }
                if (maybe_target) |target| {
                    result.value_ptr.properties.target_set.insert(target);
                }
            } else {
                result.key_ptr.* = try arena.dupe(u8, name);
                builtin_data.param_str = try arena.dupe(u8, params_without_quotes);
                result.value_ptr.* = builtin_data;
            }
        }
    }

    std.debug.print("{} builtins, max params: {}\n", .{ set.count(), max_params_count });

    {
        var sorted_list = try allocator.alloc([]const u8, set.count());
        defer allocator.free(sorted_list);
        var i: usize = 0;
        var name_it = set.keyIterator();
        while (name_it.next()) |name_ptr| {
            sorted_list[i] = name_ptr.*;
            i += 1;
        }

        std.mem.sort([]const u8, sorted_list, {}, struct {
            pub fn lessThan(_: void, a: []const u8, b: []const u8) bool {
                return std.mem.lessThan(u8, a, b);
            }
        }.lessThan);

        var longest_name: usize = 0;
        var shortest_name: usize = std.math.maxInt(usize);

        var builder = try DafsaBuilder.init(allocator);
        defer builder.deinit();
        for (sorted_list) |name| {
            try builder.insert(name);
            longest_name = @max(name.len, longest_name);
            shortest_name = @min(name.len, shortest_name);
        }
        try builder.finish();
        builder.calcNumbers();

        // As a sanity check, confirm that the minimal perfect hashing doesn't
        // have any collisions
        {
            var index_set = std.AutoHashMap(usize, void).init(allocator);
            defer index_set.deinit();

            var name_it_again = set.keyIterator();
            while (name_it_again.next()) |name_ptr| {
                const name = name_ptr.*;
                const index = builder.getUniqueIndex(name).?;
                const result = try index_set.getOrPut(index);
                if (result.found_existing) {
                    std.debug.print("clobbered {}, name={s}\n", .{ index, name });
                    return error.MinimalPerfectHashCollision;
                }
            }
        }

        var data_array = try allocator.alloc(*BuiltinData, set.count());
        defer allocator.free(data_array);
        var names_array = try allocator.alloc([]const u8, set.count());
        defer allocator.free(names_array);

        var it = set.iterator();
        while (it.next()) |entry| {
            const unique_index = builder.getUniqueIndex(entry.key_ptr.*).?;
            const data_index = unique_index - 1;
            data_array[data_index] = entry.value_ptr;
            names_array[data_index] = entry.key_ptr.*;
        }

        var dafsa_file = try std.fs.cwd().createFile(generated_file_path, .{});
        defer dafsa_file.close();

        var file_writer = dafsa_file.writer();
        var buffered_writer = std.io.bufferedWriter(file_writer);
        const writer = buffered_writer.writer();

        std.debug.assert(set.contains("__builtin_canonicalize")); // used for the generated test case

        try writer.print("//! Autogenerated by {s}, do not edit\n\n", .{@src().file});
        try writer.writeAll(
            \\const std = @import("std");
            \\const Properties = @import("Properties.zig");
            \\const TargetSet = Properties.TargetSet;
            \\
            \\tag: Tag,
            \\param_str: []const u8,
            \\properties: Properties,
            \\
            \\/// Integer starting at 0 derived from the unique index,
            \\/// corresponds with the builtin_data array index.
            \\pub const Tag = enum(u16) { _ };
            \\
            \\const Self = @This();
            \\
            \\pub fn fromName(name: []const u8) ?@This() {
            \\    const data_index = tagFromName(name) orelse return null;
            \\    return builtin_data[@intFromEnum(data_index)];
            \\}
            \\
            \\pub fn tagFromName(name: []const u8) ?Tag {
            \\    const unique_index = uniqueIndex(name) orelse return null;
            \\    return @enumFromInt(unique_index - 1);
            \\}
            \\
            \\pub fn fromTag(tag: Tag) @This() {
            \\    return builtin_data[@intFromEnum(tag)];
            \\}
            \\
            \\pub fn nameFromTagIntoBuf(tag: Tag, name_buf: []u8) []u8 {
            \\    std.debug.assert(name_buf.len >= longest_builtin_name);
            \\    const unique_index = @intFromEnum(tag) + 1;
            \\    return nameFromUniqueIndex(unique_index, name_buf);
            \\}
            \\
            \\pub fn nameFromTag(tag: Tag) NameBuf {
            \\    var name_buf: NameBuf = undefined;
            \\    const unique_index = @intFromEnum(tag) + 1;
            \\    const name = nameFromUniqueIndex(unique_index, &name_buf.buf);
            \\    name_buf.len = @intCast(name.len);
            \\    return name_buf;
            \\}
            \\
            \\pub const NameBuf = struct {
            \\    buf: [longest_builtin_name]u8 = undefined,
            \\    len: std.math.IntFittingRange(0, longest_builtin_name),
            \\
            \\    pub fn span(self: *const NameBuf) []const u8 {
            \\        return self.buf[0..self.len];
            \\    }
            \\};
            \\
            \\pub fn exists(name: []const u8) bool {
            \\    if (name.len < shortest_builtin_name or name.len > longest_builtin_name) return false;
            \\
            \\    var index: u16 = 0;
            \\    for (name) |c| {
            \\        index = findInList(dafsa[index].child_index, c) orelse return false;
            \\    }
            \\    return dafsa[index].end_of_word;
            \\}
            \\
            \\test exists {
            \\    try std.testing.expect(exists("__builtin_canonicalize"));
            \\    try std.testing.expect(!exists("__builtin_canonicaliz"));
            \\    try std.testing.expect(!exists("__builtin_canonicalize."));
            \\}
            \\
            \\pub fn isVarArgs(self: @This()) bool {
            \\    return self.param_str[self.param_str.len - 1] == '.';
            \\}
            \\
            \\
        );
        try writer.print("pub const shortest_builtin_name = {};\n", .{shortest_name});
        try writer.print("pub const longest_builtin_name = {};\n\n", .{longest_name});
        try writer.writeAll(
            \\pub const BuiltinsIterator = struct {
            \\    index: u16 = 1,
            \\    name_buf: [longest_builtin_name]u8 = undefined,
            \\
            \\    pub const Entry = struct {
            \\        /// Memory of this slice is overwritten on every call to `next`
            \\        name: []const u8,
            \\        builtin: Self,
            \\    };
            \\
            \\    pub fn next(self: *BuiltinsIterator) ?Entry {
            \\        if (self.index > builtin_data.len) return null;
            \\        const index = self.index;
            \\        const data_index = index - 1;
            \\        self.index += 1;
            \\        return .{
            \\            .name = nameFromUniqueIndex(index, &self.name_buf),
            \\            .builtin = builtin_data[data_index],
            \\        };
            \\    }
            \\};
            \\
            \\test BuiltinsIterator {
            \\    var it = BuiltinsIterator{};
            \\
            \\    var seen = std.StringHashMap(Self).init(std.testing.allocator);
            \\    defer seen.deinit();
            \\
            \\    var arena_state = std.heap.ArenaAllocator.init(std.testing.allocator);
            \\    defer arena_state.deinit();
            \\    const arena = arena_state.allocator();
            \\
            \\    while (it.next()) |entry| {
            \\        const index = uniqueIndex(entry.name).?;
            \\        var buf: [longest_builtin_name]u8 = undefined;
            \\        const name_from_index = nameFromUniqueIndex(index, &buf);
            \\        try std.testing.expectEqualStrings(entry.name, name_from_index);
            \\
            \\        if (seen.contains(entry.name)) {
            \\            std.debug.print("iterated over {s} twice\n", .{entry.name});
            \\            std.debug.print("current data: {}\n", .{entry.builtin});
            \\            std.debug.print("previous data: {}\n", .{seen.get(entry.name).?});
            \\            return error.TestExpectedUniqueEntries;
            \\        }
            \\        try seen.put(try arena.dupe(u8, entry.name), entry.builtin);
            \\    }
            \\    try std.testing.expectEqual(@as(usize, builtin_data.len), seen.count());
            \\}
            \\
            \\/// Search siblings of `first_child_index` for the `char`
            \\/// If found, returns the index of the node within the `dafsa` array.
            \\/// Otherwise, returns `null`.
            \\fn findInList(first_child_index: u16, char: u8) ?u16 {
            \\    var index = first_child_index;
            \\    while (true) {
            \\        if (dafsa[index].char == char) return index;
            \\        if (dafsa[index].end_of_list) return null;
            \\        index += 1;
            \\    }
            \\    unreachable;
            \\}
            \\
            \\/// Returns a unique (minimal perfect hash) index (starting at 1) for the `name`,
            \\/// or null if the name was not found.
            \\fn uniqueIndex(name: []const u8) ?u16 {
            \\    if (name.len < shortest_builtin_name or name.len > longest_builtin_name) return null;
            \\
            \\    var index: u16 = 0;
            \\    var node_index: u16 = 0;
            \\
            \\    for (name) |c| {
            \\        const child_index = findInList(dafsa[node_index].child_index, c) orelse return null;
            \\        var sibling_index = dafsa[node_index].child_index;
            \\        while (true) {
            \\            const sibling_c = dafsa[sibling_index].char;
            \\            std.debug.assert(sibling_c != 0);
            \\            if (sibling_c < c) {
            \\                index += dafsa[sibling_index].number;
            \\            }
            \\            if (dafsa[sibling_index].end_of_list) break;
            \\            sibling_index += 1;
            \\        }
            \\        node_index = child_index;
            \\        if (dafsa[node_index].end_of_word) index += 1;
            \\    }
            \\
            \\    if (!dafsa[node_index].end_of_word) return null;
            \\
            \\    return index;
            \\}
            \\
            \\/// Returns a slice of `buf` with the name associated with the given `index`.
            \\/// This function should only be called with an `index` that
            \\/// is already known to exist within the `dafsa`, e.g. an index
            \\/// returned from `uniqueIndex`.
            \\fn nameFromUniqueIndex(index: u16, buf: []u8) []u8 {
            \\    std.debug.assert(index >= 1 and index <= builtin_data.len);
            \\
            \\    var node_index: u16 = 0;
            \\    var count: u16 = index;
            \\    var fbs = std.io.fixedBufferStream(buf);
            \\    const w = fbs.writer();
            \\
            \\    while (true) {
            \\        var sibling_index = dafsa[node_index].child_index;
            \\        while (true) {
            \\            if (dafsa[sibling_index].number > 0 and dafsa[sibling_index].number < count) {
            \\                count -= dafsa[sibling_index].number;
            \\            } else {
            \\                w.writeByte(dafsa[sibling_index].char) catch unreachable;
            \\                node_index = sibling_index;
            \\                if (dafsa[node_index].end_of_word) {
            \\                    count -= 1;
            \\                }
            \\                break;
            \\            }
            \\
            \\            if (dafsa[sibling_index].end_of_list) break;
            \\            sibling_index += 1;
            \\        }
            \\        if (count == 0) break;
            \\    }
            \\
            \\    return fbs.getWritten();
            \\}
            \\
            \\
        );
        try writer.print("pub const MaxParamCount = {};\n\n", .{max_params_count});
        try writer.writeAll(
            \\/// We're 1 bit shy of being able to fit this in a u32:
            \\/// - char only contains 0-9, a-z, A-Z, and _, so it could use a enum(u6) with a way to convert <-> u8
            \\///   (note: this would have a performance cost that may make the u32 not worth it)
            \\/// - number has a max value of > 2047 and < 4095 (the first _ node has the largest number),
            \\///   so it could fit into a u12
            \\/// - child_index currently has a max of > 4095 and < 8191, so it could fit into a u13
            \\///
            \\/// with the end_of_word/end_of_list 2 bools, that makes 33 bits total
            \\const Node = packed struct(u64) {
            \\    char: u8,
            \\    /// Nodes are numbered with "an integer which gives the number of words that
            \\    /// would be accepted by the automaton starting from that state." This numbering
            \\    /// allows calculating "a one-to-one correspondence between the integers 1 to L
            \\    /// (L is the number of words accepted by the automaton) and the words themselves."
            \\    ///
            \\    /// Essentially, this allows us to have a minimal perfect hashing scheme such that
            \\    /// it's possible to store & lookup the properties of each builtin using a separate array.
            \\    number: u16,
            \\    /// If true, this node is the end of a valid builtin.
            \\    /// Note: This does not necessarily mean that this node does not have child nodes.
            \\    end_of_word: bool,
            \\    /// If true, this node is the end of a sibling list.
            \\    /// If false, then (index + 1) will contain the next sibling.
            \\    end_of_list: bool,
            \\    /// Padding bits to get to u64, unsure if there's some way to use these to improve something.
            \\    _extra: u22 = 0,
            \\    /// Index of the first child of this node.
            \\    child_index: u16,
            \\};
            \\
            \\
        );
        try builder.writeDafsa(writer);
        try writeData(writer, data_array, names_array);

        try buffered_writer.flush();
    }
}

fn writeData(writer: anytype, data_array: []const *BuiltinData, names_array: []const []const u8) !void {
    try writer.writeAll("const builtin_data = blk: {\n");
    try writer.print("    @setEvalBranchQuota({});\n", .{data_array.len});
    try writer.writeAll("    break :blk [_]@This(){\n");
    for (data_array, names_array, 0..) |data, name, i| {
        try writer.writeAll("        // ");
        try writer.writeAll(name);
        try writer.writeAll("\n");
        try writer.writeAll("        .{ .tag = ");
        try writer.print("@enumFromInt({})", .{i});
        try writer.writeAll(", .param_str = \"");
        try writer.writeAll(data.param_str);
        try writer.writeAll("\", .properties = .{");
        var has_properties = false;
        if (data.properties.header != .none) {
            try writer.writeAll(" .header = .");
            try writer.writeAll(@tagName(data.properties.header));
            has_properties = true;
        }
        if (data.properties.language != .all_languages) {
            if (has_properties) try writer.writeAll(",");
            try writer.writeAll(" .language = .");
            try writer.writeAll(@tagName(data.properties.language));
            has_properties = true;
        }
        if (!data.properties.target_set.eql(Properties.TargetSet.initOne(.basic))) {
            if (has_properties) try writer.writeAll(",");
            var set_it = data.properties.target_set.iterator();
            if (data.properties.target_set.count() == 1) {
                const target = set_it.next().?;
                try writer.writeAll(" .target_set = TargetSet.initOne(.");
                try writer.writeAll(@tagName(target));
                try writer.writeAll(")");
            } else {
                try writer.writeAll(" .target_set = TargetSet.initMany(&.{ ");
                var first = true;
                while (set_it.next()) |target| {
                    if (!first) try writer.writeAll(", ");
                    try writer.writeAll(".");
                    try writer.writeAll(@tagName(target));
                    first = false;
                }
                try writer.writeAll(" })");
            }
            has_properties = true;
        }
        if (!allDefaultAttributes(data.properties.attributes)) {
            if (has_properties) try writer.writeAll(",");
            try writer.writeAll(" .attributes = .{ ");

            var first = true;
            inline for (@typeInfo(@TypeOf(data.properties.attributes)).Struct.fields) |field| {
                const default = @as(*align(1) const field.type, @ptrCast(field.default_value.?)).*;
                if (@field(data.properties.attributes, field.name) != default) {
                    if (!first) try writer.writeAll(", ");
                    try writer.print(".{s} = ", .{std.zig.fmtId(field.name)});
                    switch (@typeInfo(field.type)) {
                        .Enum => {
                            try writer.print(".{s}", .{std.zig.fmtId(@tagName(@field(data.properties.attributes, field.name)))});
                        },
                        .Bool, .Int => {
                            try writer.print("{}", .{@field(data.properties.attributes, field.name)});
                        },
                        else => @compileError("unsupported field type in attributes"),
                    }
                    first = false;
                }
            }

            try writer.writeAll(" }");
            has_properties = true;
        }
        if (has_properties) try writer.writeAll(" ");
        try writer.writeAll("}");
        try writer.writeAll(" },\n");
    }
    try writer.writeAll("    };\n");
    try writer.writeAll("};\n");
}

fn allDefaultAttributes(attributes: Properties.Attributes) bool {
    inline for (@typeInfo(@TypeOf(attributes)).Struct.fields) |field| {
        if (field.default_value) |default_ptr| {
            const default = @as(*align(1) const field.type, @ptrCast(default_ptr)).*;
            if (@field(attributes, field.name) != default) return false;
        } else {
            @panic("field with no default in Attributes");
        }
    }
    return true;
}

const header_map = std.ComptimeStringMap(Properties.Header, .{
    .{ "NO_HEADER", .none },
    .{ "STDIO_H", .stdio },
    .{ "STDLIB_H", .stdlib },
    .{ "SETJMPEX_H", .setjmpex },
    .{ "STDARG_H", .stdarg },
    .{ "STRING_H", .string },
    .{ "CTYPE_H", .ctype },
    .{ "WCHAR_H", .wchar },
    .{ "SETJMP_H", .setjmp },
    .{ "MALLOC_H", .malloc },
    .{ "STRINGS_H", .strings },
    .{ "UNISTD_H", .unistd },
    .{ "PTHREAD_H", .pthread },
    // .{ "OBJC_MESSAGE_H", .objc_message },
    // .{ "OBJC_RUNTIME_H", .objc_runtime },
    // .{ "OBJC_OBJC_AUTO_H", .objc_objc_auto },
    // .{ "OBJC_OBJC_EXCEPTION_H", .objc_objc_exception },
    // .{ "OBJC_OBJC_SYNC_H", .objc_objc_sync },
    // .{ "FOUNDATION_NSOBJCRUNTIME_H", .Foundation_NSObjCRuntime },
    .{ "MATH_H", .math },
    .{ "COMPLEX_H", .complex },
    .{ "BLOCKS_H", .blocks },
    // .{ "MEMORY", .memory },
    // .{ "UTILITY", .utility },
});

const allowed_languages_map = std.ComptimeStringMap(Properties.Language, .{
    .{ "ALL_LANGUAGES", .all_languages },
    .{ "ALL_MS_LANGUAGES", .all_ms_languages },
    .{ "ALL_GNU_LANGUAGES", .all_gnu_languages },
    .{ "GNU_LANG", .gnu_lang },
});

fn attributesFromString(str: []const u8) Properties.Attributes {
    var attrs = Properties.Attributes{};
    attrs.noreturn = std.mem.indexOfScalar(u8, str, 'r') != null;
    attrs.pure = std.mem.indexOfScalar(u8, str, 'U') != null;
    attrs.@"const" = std.mem.indexOfScalar(u8, str, 'c') != null;
    attrs.custom_typecheck = std.mem.indexOfScalar(u8, str, 't') != null;
    attrs.allow_type_mismatch = std.mem.indexOfScalar(u8, str, 'T') != null;
    attrs.lib_function_with_builtin_prefix = std.mem.indexOfScalar(u8, str, 'F') != null;
    attrs.lib_function_without_prefix = std.mem.indexOfScalar(u8, str, 'f') != null;
    attrs.returns_twice = std.mem.indexOfScalar(u8, str, 'j') != null;
    attrs.eval_args = std.mem.indexOfScalar(u8, str, 'u') == null; // flipped
    attrs.const_without_errno_and_fp_exceptions = std.mem.indexOfScalar(u8, str, 'e') != null;
    attrs.const_without_fp_exceptions = std.mem.indexOfScalar(u8, str, 'g') != null;
    attrs.const_evaluable = std.mem.indexOfScalar(u8, str, 'E') != null;
    if (std.mem.indexOfAny(u8, str, "sSpP")) |pos| {
        attrs.format_kind = switch (str[pos]) {
            'p' => .printf,
            'P' => .vprintf,
            's' => .scanf,
            'S' => .vscanf,
            else => unreachable,
        };
        std.debug.assert(str[pos + 1] == ':');
        std.debug.assert(std.ascii.isDigit(str[pos + 2]));
        std.debug.assert(str[pos + 3] == ':');
        const num = str[pos + 2] - '0';
        attrs.format_string_position = @intCast(num);
    }
    return attrs;
}

fn targetFromFilename(filename: []const u8) !?Properties.Target {
    const stem = std.fs.path.stem(filename);
    if (std.ascii.startsWithIgnoreCase(stem, "builtins")) {
        const suffix = stem["builtins".len..];
        if (suffix.len == 0) return null;
        return targets_map.get(suffix) orelse return error.UnknownTarget;
    }
    return error.UnexpectedFilename;
}

const targets_map = std.ComptimeStringMapWithEql(Properties.Target, .{
    .{ "aarch64", .aarch64 },
    .{ "aarch64neonsvebridge", .aarch64_neon_sve_bridge },
    .{ "aarch64neonsvebridge_cg", .aarch64_neon_sve_bridge_cg },
    .{ "amdgpu", .amdgpu },
    .{ "arm", .arm },
    .{ "bpf", .bpf },
    .{ "hexagon", .hexagon },
    .{ "hexagondep", .hexagon_dep },
    .{ "hexagonmapcustomdep", .hexagon_map_custom_dep },
    .{ "loongarch", .loong_arch },
    .{ "mips", .mips },
    .{ "neon", .neon },
    .{ "nvptx", .nvptx },
    .{ "ppc", .ppc },
    .{ "riscv", .riscv },
    .{ "riscvvector", .riscv_vector },
    .{ "sve", .sve },
    .{ "systemz", .systemz },
    .{ "ve", .ve },
    .{ "vevl.gen", .vevl_gen },
    .{ "webassembly", .webassembly },
    .{ "x86", .x86 },
    .{ "x86_64", .x86_64 },
    .{ "xcore", .xcore },
}, std.comptime_string_map.eqlAsciiIgnoreCase);

fn equivalentPrototypes(a: BuiltinData, b: BuiltinData) bool {
    return std.mem.eql(u8, a.param_str, b.param_str) and std.meta.eql(a.properties.attributes, b.properties.attributes);
}

const Macro = enum {
    BUILTIN,
    LANGBUILTIN,
    LIBBUILTIN,
    TARGET_BUILTIN, // TODO
    CUSTOM_BUILTIN, // TODO
    UNALIASED_CUSTOM_BUILTIN, // TODO
};

const MacroIterator = struct {
    token_it: std.mem.TokenIterator(u8, .any),

    pub fn init(line: []const u8) MacroIterator {
        return .{
            .token_it = std.mem.tokenizeAny(u8, line, "(, )"),
        };
    }

    pub fn next(self: *MacroIterator) ?[]const u8 {
        var value = self.token_it.next() orelse return null;
        // value.len is always > 0 since we're using TokenIterator
        if (value[0] == '"') {
            // If the value starts with a quote, we don't want delimiters to break the quoted string,
            // so keep appending values to the len until we find the end of the quoted string
            const start_ptr = value.ptr;
            var len: usize = 0;
            while (true) {
                len += value.len;
                if (value[value.len - 1] == '"') break;
                value = self.token_it.next() orelse break;
            }
            return start_ptr[0..len];
        }
        return value;
    }

    pub fn isAtEnd(self: *MacroIterator) bool {
        return self.token_it.buffer[self.token_it.index] == ')';
    }
};

const DafsaBuilder = struct {
    root: *Node,
    arena: std.heap.ArenaAllocator.State,
    allocator: Allocator,
    unchecked_nodes: std.ArrayListUnmanaged(UncheckedNode),
    minimized_nodes: std.HashMapUnmanaged(*Node, *Node, Node.DuplicateContext, std.hash_map.default_max_load_percentage),
    previous_word_buf: [64]u8 = undefined,
    previous_word: []u8 = &[_]u8{},

    const UncheckedNode = struct {
        parent: *Node,
        char: u8,
        child: *Node,
    };

    pub fn init(allocator: Allocator) !DafsaBuilder {
        var arena = std.heap.ArenaAllocator.init(allocator);
        errdefer arena.deinit();

        var root = try arena.allocator().create(Node);
        root.* = .{};
        return DafsaBuilder{
            .root = root,
            .allocator = allocator,
            .arena = arena.state,
            .unchecked_nodes = .{},
            .minimized_nodes = .{},
        };
    }

    pub fn deinit(self: *DafsaBuilder) void {
        self.arena.promote(self.allocator).deinit();
        self.unchecked_nodes.deinit(self.allocator);
        self.minimized_nodes.deinit(self.allocator);
        self.* = undefined;
    }

    const Node = struct {
        children: [256]?*Node = [_]?*Node{null} ** 256,
        is_terminal: bool = false,
        number: usize = 0,

        const DuplicateContext = struct {
            pub fn hash(ctx: @This(), key: *Node) u64 {
                _ = ctx;
                var hasher = std.hash.Wyhash.init(0);
                std.hash.autoHash(&hasher, key.children);
                std.hash.autoHash(&hasher, key.is_terminal);
                return hasher.final();
            }

            pub fn eql(ctx: @This(), a: *Node, b: *Node) bool {
                _ = ctx;
                return a.is_terminal == b.is_terminal and std.mem.eql(?*Node, &a.children, &b.children);
            }
        };

        pub fn calcNumbers(self: *Node) void {
            self.number = @intFromBool(self.is_terminal);
            for (self.children) |maybe_child| {
                const child = maybe_child orelse continue;
                // A node's number is the sum of the
                // numbers of its immediate child nodes.
                child.calcNumbers();
                self.number += child.number;
            }
        }

        pub fn numDirectChildren(self: *const Node) u8 {
            var num: u8 = 0;
            for (self.children) |child| {
                if (child != null) num += 1;
            }
            return num;
        }
    };

    pub fn insert(self: *DafsaBuilder, str: []const u8) !void {
        if (std.mem.order(u8, str, self.previous_word) == .lt) {
            @panic("insertion order must be sorted");
        }

        var common_prefix_len: usize = 0;
        for (0..@min(str.len, self.previous_word.len)) |i| {
            if (str[i] != self.previous_word[i]) break;
            common_prefix_len += 1;
        }

        try self.minimize(common_prefix_len);

        var node = if (self.unchecked_nodes.items.len == 0)
            self.root
        else
            self.unchecked_nodes.getLast().child;

        for (str[common_prefix_len..]) |c| {
            std.debug.assert(node.children[c] == null);

            var arena = self.arena.promote(self.allocator);
            var child = try arena.allocator().create(Node);
            self.arena = arena.state;

            child.* = .{};
            node.children[c] = child;
            try self.unchecked_nodes.append(self.allocator, .{
                .parent = node,
                .char = c,
                .child = child,
            });
            node = node.children[c].?;
        }
        node.is_terminal = true;

        self.previous_word = self.previous_word_buf[0..str.len];
        @memcpy(self.previous_word, str);
    }

    pub fn minimize(self: *DafsaBuilder, down_to: usize) !void {
        if (self.unchecked_nodes.items.len == 0) return;
        while (self.unchecked_nodes.items.len > down_to) {
            const unchecked_node = self.unchecked_nodes.pop();
            if (self.minimized_nodes.getPtr(unchecked_node.child)) |child| {
                unchecked_node.parent.children[unchecked_node.char] = child.*;
            } else {
                try self.minimized_nodes.put(self.allocator, unchecked_node.child, unchecked_node.child);
            }
        }
    }

    pub fn finish(self: *DafsaBuilder) !void {
        try self.minimize(0);
    }

    fn nodeCount(self: *const DafsaBuilder) usize {
        return self.minimized_nodes.count();
    }

    fn edgeCount(self: *const DafsaBuilder) usize {
        var count: usize = 0;
        var it = self.minimized_nodes.iterator();
        while (it.next()) |entry| {
            for (entry.key_ptr.*.children) |child| {
                if (child != null) count += 1;
            }
        }
        return count;
    }

    fn contains(self: *const DafsaBuilder, str: []const u8) bool {
        var node = self.root;
        for (str) |c| {
            node = node.children[c] orelse return false;
        }
        return node.is_terminal;
    }

    fn calcNumbers(self: *const DafsaBuilder) void {
        self.root.calcNumbers();
    }

    fn getUniqueIndex(self: *const DafsaBuilder, str: []const u8) ?usize {
        var index: usize = 0;
        var node = self.root;

        for (str) |c| {
            const child = node.children[c] orelse return null;
            for (node.children, 0..) |sibling, sibling_c| {
                if (sibling == null) continue;
                if (sibling_c < c) {
                    index += sibling.?.number;
                }
            }
            node = child;
            if (node.is_terminal) index += 1;
        }

        return index;
    }

    fn writeDafsa(self: *const DafsaBuilder, writer: anytype) !void {
        try writer.writeAll("const dafsa = [_]Node{\n");

        // write root
        try writer.writeAll("    .{ .char = 0, .end_of_word = false, .end_of_list = true, .number = 0, .child_index = 1 },\n");

        var queue = std.ArrayList(*Node).init(self.allocator);
        defer queue.deinit();

        var child_indexes = std.AutoHashMap(*Node, usize).init(self.allocator);
        defer child_indexes.deinit();

        try child_indexes.ensureTotalCapacity(@intCast(self.edgeCount()));

        var first_available_index: usize = self.root.numDirectChildren() + 1;
        first_available_index = try writeDafsaChildren(self.root, writer, &queue, &child_indexes, first_available_index);

        while (queue.items.len > 0) {
            // TODO: something with better time complexity
            const node = queue.orderedRemove(0);

            first_available_index = try writeDafsaChildren(node, writer, &queue, &child_indexes, first_available_index);
        }

        try writer.writeAll("};\n");
    }

    fn writeDafsaChildren(
        node: *Node,
        writer: anytype,
        queue: *std.ArrayList(*Node),
        child_indexes: *std.AutoHashMap(*Node, usize),
        first_available_index: usize,
    ) !usize {
        var cur_available_index = first_available_index;
        const num_children = node.numDirectChildren();
        var child_i: usize = 0;
        for (node.children, 0..) |maybe_child, c_usize| {
            const child = maybe_child orelse continue;
            const c: u8 = @intCast(c_usize);
            const is_last_child = child_i == num_children - 1;

            if (!child_indexes.contains(child)) {
                const child_num_children = child.numDirectChildren();
                if (child_num_children > 0) {
                    child_indexes.putAssumeCapacityNoClobber(child, cur_available_index);
                    cur_available_index += child_num_children;
                }
                try queue.append(child);
            }

            try writer.print(
                "    .{{ .char = '{c}', .end_of_word = {}, .end_of_list = {}, .number = {}, .child_index = {} }},\n",
                .{ c, child.is_terminal, is_last_child, child.number, child_indexes.get(child) orelse 0 },
            );

            child_i += 1;
        }
        return cur_available_index;
    }
};
