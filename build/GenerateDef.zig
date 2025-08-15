const std = @import("std");
const Step = std.Build.Step;
const Allocator = std.mem.Allocator;
const GeneratedFile = std.Build.GeneratedFile;

const GenerateDef = @This();

step: Step,
path: []const u8,
name: []const u8,
kind: Options.Kind,
needs_large_dafsa_node: bool,
generated_file: GeneratedFile,

pub const base_id: Step.Id = .custom;

pub const Options = struct {
    name: []const u8,
    src_prefix: []const u8 = "src/aro",
    kind: Kind = .dafsa,
    needs_large_dafsa_node: bool = false,

    pub const Kind = enum { dafsa, named };
};

pub fn create(owner: *std.Build, options: Options) std.Build.Module.Import {
    const self = owner.allocator.create(GenerateDef) catch @panic("OOM");
    const path = owner.pathJoin(&.{ options.src_prefix, options.name });

    const name = owner.fmt("GenerateDef {s}", .{options.name});
    self.* = .{
        .step = Step.init(.{
            .id = base_id,
            .name = name,
            .owner = owner,
            .makeFn = make,
        }),
        .path = path,
        .name = options.name,
        .kind = options.kind,
        .needs_large_dafsa_node = options.needs_large_dafsa_node,
        .generated_file = .{ .step = &self.step },
    };
    const module = self.step.owner.createModule(.{
        .root_source_file = .{ .generated = .{ .file = &self.generated_file } },
    });
    return .{
        .module = module,
        .name = self.name,
    };
}

fn make(step: *Step, options: std.Build.Step.MakeOptions) !void {
    _ = options;
    const b = step.owner;
    const self: *GenerateDef = @fieldParentPtr("step", step);
    const arena = b.allocator;

    var man = b.graph.cache.obtain();
    defer man.deinit();

    // Random bytes to make GenerateDef unique. Refresh this with new
    // random bytes when GenerateDef implementation is modified in a
    // non-backwards-compatible way.
    man.hash.add(@as(u32, 0xDCC14144));

    const contents = try b.build_root.handle.readFileAlloc(arena, self.path, std.math.maxInt(u32));
    man.hash.addBytes(contents);

    const out_name = b.fmt("{s}.zig", .{std.fs.path.stem(self.path)});
    if (try step.cacheHit(&man)) {
        const digest = man.final();
        self.generated_file.path = try b.cache_root.join(arena, &.{
            "o", &digest, out_name,
        });
        return;
    }

    const digest = man.final();

    const sub_path = try std.fs.path.join(arena, &.{ "o", &digest, out_name });
    const sub_path_dirname = std.fs.path.dirname(sub_path).?;

    b.cache_root.handle.makePath(sub_path_dirname) catch |err| {
        return step.fail("unable to make path '{f}{s}': {s}", .{
            b.cache_root, sub_path_dirname, @errorName(err),
        });
    };

    const output = try self.generate(contents);
    b.cache_root.handle.writeFile(.{ .sub_path = sub_path, .data = output }) catch |err| {
        return step.fail("unable to write file '{f}{s}': {s}", .{
            b.cache_root, sub_path, @errorName(err),
        });
    };

    self.generated_file.path = try b.cache_root.join(arena, &.{sub_path});
    try man.writeManifest();
}

const Value = struct {
    name: []const u8,
    properties: []const []const u8,
};

fn generate(self: *GenerateDef, input: []const u8) ![]const u8 {
    const arena = self.step.owner.allocator;

    var values: std.StringArrayHashMapUnmanaged([]const []const u8) = .empty;
    var properties: std.ArrayList([]const u8) = .empty;
    var headers: std.ArrayList([]const u8) = .empty;

    var value_name: ?[]const u8 = null;
    var it = std.mem.tokenizeAny(u8, input, "\r\n");
    while (it.next()) |line_untrimmed| {
        const line = std.mem.trim(u8, line_untrimmed, " \t");
        if (line.len == 0 or line[0] == '#') continue;
        if (std.mem.startsWith(u8, line, "const ") or std.mem.startsWith(u8, line, "pub const ")) {
            try headers.append(arena, line);
            continue;
        }
        if (line[0] == '.') {
            if (value_name == null) {
                return self.step.fail("property not attached to a value:\n\"{s}\"", .{line});
            }
            try properties.append(arena, line);
            continue;
        }

        if (value_name) |name| {
            const old = try values.fetchPut(arena, name, try properties.toOwnedSlice(arena));
            if (old != null) return self.step.fail("duplicate value \"{s}\"", .{name});
        }
        value_name = line;
    }

    if (value_name) |name| {
        const old = try values.fetchPut(arena, name, try properties.toOwnedSlice(arena));
        if (old != null) return self.step.fail("duplicate value \"{s}\"", .{name});
    }

    {
        const sorted_list = try arena.dupe([]const u8, values.keys());
        defer arena.free(sorted_list);
        std.mem.sort([]const u8, sorted_list, {}, struct {
            pub fn lessThan(_: void, a: []const u8, b: []const u8) bool {
                return std.mem.lessThan(u8, a, b);
            }
        }.lessThan);

        var longest_name: usize = 0;
        var shortest_name: usize = std.math.maxInt(usize);

        var builder = try DafsaBuilder.init(arena);
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
            var index_set = std.AutoHashMap(usize, void).init(arena);
            defer index_set.deinit();

            for (values.keys()) |name| {
                const index = builder.getUniqueIndex(name).?;
                const result = try index_set.getOrPut(index);
                if (result.found_existing) {
                    return self.step.fail("clobbered {}, name={s}\n", .{ index, name });
                }
            }
        }

        var allocating: std.Io.Writer.Allocating = .init(arena);
        const writer = &allocating.writer;

        try writer.print(
            \\//! Autogenerated by GenerateDef from {s}, do not edit
            \\
            \\const std = @import("std");
            \\
            \\pub fn with(comptime Properties: type) type {{
            \\return struct {{
            \\
        , .{self.path});
        for (headers.items) |line| {
            try writer.print("{s}\n", .{line});
        }
        if (self.kind == .named) {
            try writer.writeAll("pub const Tag = enum {\n");
            for (values.keys()) |property| {
                try writer.print("    {f},\n", .{std.zig.fmtIdFlags(property, .{ .allow_primitive = true })});
            }
            try writer.writeAll(
                \\
                \\    pub fn property(tag: Tag) Properties {
                \\        return named_data[@intFromEnum(tag)];
                \\    }
                \\
                \\    const named_data = [_]Properties{
                \\
            );
            for (values.values()) |val_props| {
                try writer.writeAll("        .{");
                for (val_props, 0..) |val_prop, j| {
                    if (j != 0) try writer.writeByte(',');
                    try writer.writeByte(' ');
                    try writer.writeAll(val_prop);
                }
                try writer.writeAll(" },\n");
            }
            try writer.writeAll(
                \\    };
                \\};
                \\};
                \\}
                \\
            );

            return allocating.toOwnedSlice();
        }

        var values_array = try arena.alloc(Value, values.count());
        defer arena.free(values_array);

        for (values.keys(), values.values()) |name, props| {
            const unique_index = builder.getUniqueIndex(name).?;
            const data_index = unique_index - 1;
            values_array[data_index] = .{ .name = name, .properties = props };
        }

        try writer.writeAll(
            \\
            \\tag: Tag,
            \\properties: Properties,
            \\
            \\/// Integer starting at 0 derived from the unique index,
            \\/// corresponds with the data array index.
            \\pub const Tag = enum(u16) {
        );
        for (values_array) |value| {
            try writer.print("    {f},\n", .{std.zig.fmtId(value.name)});
        }
        try writer.writeAll(
            \\};
            \\
            \\const Self = @This();
            \\
            \\pub fn fromName(name: []const u8) ?@This() {
            \\    const data_index = tagFromName(name) orelse return null;
            \\    return data[@intFromEnum(data_index)];
            \\}
            \\
            \\pub fn tagFromName(name: []const u8) ?Tag {
            \\    const unique_index = uniqueIndex(name) orelse return null;
            \\    return @enumFromInt(unique_index - 1);
            \\}
            \\
            \\pub fn fromTag(tag: Tag) @This() {
            \\    return data[@intFromEnum(tag)];
            \\}
            \\
            \\pub fn nameFromTagIntoBuf(tag: Tag, name_buf: []u8) []u8 {
            \\    std.debug.assert(name_buf.len >= longest_name);
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
            \\    buf: [longest_name]u8 = undefined,
            \\    len: std.math.IntFittingRange(0, longest_name),
            \\
            \\    pub fn span(self: *const NameBuf) []const u8 {
            \\        return self.buf[0..self.len];
            \\    }
            \\};
            \\
            \\pub fn exists(name: []const u8) bool {
            \\    if (name.len < shortest_name or name.len > longest_name) return false;
            \\
            \\    var index: u16 = 0;
            \\    for (name) |c| {
            \\        index = findInList(dafsa[index].child_index, c) orelse return false;
            \\    }
            \\    return dafsa[index].end_of_word;
            \\}
            \\
            \\
        );
        try writer.print("pub const shortest_name = {};\n", .{shortest_name});
        try writer.print("pub const longest_name = {};\n\n", .{longest_name});
        try writer.writeAll(
            \\/// Search siblings of `first_child_index` for the `char`
            \\/// If found, returns the index of the node within the `dafsa` array.
            \\/// Otherwise, returns `null`.
            \\pub fn findInList(first_child_index: u16, char: u8) ?u16 {
            \\
        );
        try writer.print("    @setEvalBranchQuota({d});\n", .{values.count() * 2});
        try writer.writeAll(
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
            \\pub fn uniqueIndex(name: []const u8) ?u16 {
            \\    if (name.len < shortest_name or name.len > longest_name) return null;
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
            \\pub fn nameFromUniqueIndex(index: u16, buf: []u8) []u8 {
            \\    std.debug.assert(index >= 1 and index <= data.len);
            \\
            \\    var node_index: u16 = 0;
            \\    var count: u16 = index;
            \\    var w = std.Io.Writer.fixed(buf);
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
            \\    return w.buffered();
            \\}
            \\
            \\
        );
        if (self.needs_large_dafsa_node) {
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
        } else {
            try writer.writeAll(
                \\const Node = packed struct(u32) {
                \\    char: u8,
                \\    /// Nodes are numbered with "an integer which gives the number of words that
                \\    /// would be accepted by the automaton starting from that state." This numbering
                \\    /// allows calculating "a one-to-one correspondence between the integers 1 to L
                \\    /// (L is the number of words accepted by the automaton) and the words themselves."
                \\    ///
                \\    /// Essentially, this allows us to have a minimal perfect hashing scheme such that
                \\    /// it's possible to store & lookup the properties of each name using a separate array.
                \\    number: u8,
                \\    /// If true, this node is the end of a valid name.
                \\    /// Note: This does not necessarily mean that this node does not have child nodes.
                \\    end_of_word: bool,
                \\    /// If true, this node is the end of a sibling list.
                \\    /// If false, then (index + 1) will contain the next sibling.
                \\    end_of_list: bool,
                \\    /// Index of the first child of this node.
                \\    child_index: u14,
                \\};
                \\
                \\
            );
        }
        try builder.writeDafsa(writer);
        try writeData(writer, values_array);
        try writer.writeAll(
            \\};
            \\}
            \\
        );

        return allocating.toOwnedSlice();
    }
}

fn writeData(writer: *std.Io.Writer, values: []const Value) !void {
    try writer.writeAll("pub const data = blk: {\n");
    try writer.print("    @setEvalBranchQuota({d});\n", .{values.len * 7});
    try writer.writeAll("    break :blk [_]@This(){\n");
    for (values) |value| {
        try writer.print("        .{{ .tag = .{f}, .properties = .{{", .{std.zig.fmtId(value.name)});
        for (value.properties, 0..) |property, j| {
            if (j != 0) try writer.writeByte(',');
            try writer.writeByte(' ');
            try writer.writeAll(property);
        }
        if (value.properties.len != 0) try writer.writeByte(' ');
        try writer.writeAll("} },\n");
    }
    try writer.writeAll("    };\n");
    try writer.writeAll("};\n");
}

const DafsaBuilder = struct {
    root: *Node,
    arena: std.heap.ArenaAllocator.State,
    allocator: Allocator,
    unchecked_nodes: std.ArrayListUnmanaged(UncheckedNode),
    minimized_nodes: std.HashMapUnmanaged(*Node, *Node, Node.DuplicateContext, std.hash_map.default_max_load_percentage),
    previous_word_buf: [128]u8 = undefined,
    previous_word: []u8 = &[_]u8{},

    const UncheckedNode = struct {
        parent: *Node,
        char: u8,
        child: *Node,
    };

    pub fn init(allocator: Allocator) !DafsaBuilder {
        var arena = std.heap.ArenaAllocator.init(allocator);
        errdefer arena.deinit();

        const root = try arena.allocator().create(Node);
        root.* = .{};
        return DafsaBuilder{
            .root = root,
            .allocator = allocator,
            .arena = arena.state,
            .unchecked_nodes = .{},
            .minimized_nodes = .{},
        };
    }

    pub fn deinit(db: *DafsaBuilder) void {
        db.arena.promote(db.allocator).deinit();
        db.unchecked_nodes.deinit(db.allocator);
        db.minimized_nodes.deinit(db.allocator);
        db.* = undefined;
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

        pub fn calcNumbers(db: *Node) void {
            db.number = @intFromBool(db.is_terminal);
            for (db.children) |maybe_child| {
                const child = maybe_child orelse continue;
                // A node's number is the sum of the
                // numbers of its immediate child nodes.
                child.calcNumbers();
                db.number += child.number;
            }
        }

        pub fn numDirectChildren(db: *const Node) u8 {
            var num: u8 = 0;
            for (db.children) |child| {
                if (child != null) num += 1;
            }
            return num;
        }
    };

    pub fn insert(db: *DafsaBuilder, str: []const u8) !void {
        if (std.mem.order(u8, str, db.previous_word) == .lt) {
            @panic("insertion order must be sorted");
        }

        var common_prefix_len: usize = 0;
        for (0..@min(str.len, db.previous_word.len)) |i| {
            if (str[i] != db.previous_word[i]) break;
            common_prefix_len += 1;
        }

        try db.minimize(common_prefix_len);

        var node = if (db.unchecked_nodes.items.len == 0)
            db.root
        else
            db.unchecked_nodes.getLast().child;

        for (str[common_prefix_len..]) |c| {
            std.debug.assert(node.children[c] == null);

            var arena = db.arena.promote(db.allocator);
            const child = try arena.allocator().create(Node);
            db.arena = arena.state;

            child.* = .{};
            node.children[c] = child;
            try db.unchecked_nodes.append(db.allocator, .{
                .parent = node,
                .char = c,
                .child = child,
            });
            node = node.children[c].?;
        }
        node.is_terminal = true;

        db.previous_word = db.previous_word_buf[0..str.len];
        @memcpy(db.previous_word, str);
    }

    pub fn minimize(db: *DafsaBuilder, down_to: usize) !void {
        if (db.unchecked_nodes.items.len == 0) return;
        while (db.unchecked_nodes.items.len > down_to) {
            const unchecked_node = db.unchecked_nodes.pop().?;
            if (db.minimized_nodes.getPtr(unchecked_node.child)) |child| {
                unchecked_node.parent.children[unchecked_node.char] = child.*;
            } else {
                try db.minimized_nodes.put(db.allocator, unchecked_node.child, unchecked_node.child);
            }
        }
    }

    pub fn finish(db: *DafsaBuilder) !void {
        try db.minimize(0);
    }

    fn nodeCount(db: *const DafsaBuilder) usize {
        return db.minimized_nodes.count();
    }

    fn edgeCount(db: *const DafsaBuilder) usize {
        var count: usize = 0;
        var it = db.minimized_nodes.iterator();
        while (it.next()) |entry| {
            for (entry.key_ptr.*.children) |child| {
                if (child != null) count += 1;
            }
        }
        return count;
    }

    fn contains(db: *const DafsaBuilder, str: []const u8) bool {
        var node = db.root;
        for (str) |c| {
            node = node.children[c] orelse return false;
        }
        return node.is_terminal;
    }

    fn calcNumbers(db: *const DafsaBuilder) void {
        db.root.calcNumbers();
    }

    fn getUniqueIndex(db: *const DafsaBuilder, str: []const u8) ?usize {
        var index: usize = 0;
        var node = db.root;

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

    fn writeDafsa(db: *const DafsaBuilder, writer: *std.Io.Writer) !void {
        try writer.writeAll("const dafsa = [_]Node{\n");

        // write root
        try writer.writeAll("    .{ .char = 0, .end_of_word = false, .end_of_list = true, .number = 0, .child_index = 1 },\n");

        var queue: std.ArrayList(*Node) = .empty;
        defer queue.deinit(db.allocator);

        var child_indexes: std.AutoHashMapUnmanaged(*Node, usize) = .empty;
        defer child_indexes.deinit(db.allocator);

        try child_indexes.ensureTotalCapacity(db.allocator, @intCast(db.edgeCount()));

        var first_available_index: usize = db.root.numDirectChildren() + 1;
        first_available_index = try db.writeDafsaChildren(db.root, writer, &queue, &child_indexes, first_available_index);

        while (queue.items.len > 0) {
            // TODO: something with better time complexity
            const node = queue.orderedRemove(0);

            first_available_index = try db.writeDafsaChildren(node, writer, &queue, &child_indexes, first_available_index);
        }

        try writer.writeAll("};\n");
    }

    fn writeDafsaChildren(
        db: *const DafsaBuilder,
        node: *Node,
        writer: *std.Io.Writer,
        queue: *std.ArrayList(*Node),
        child_indexes: *std.AutoHashMapUnmanaged(*Node, usize),
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
                try queue.append(db.allocator, child);
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
