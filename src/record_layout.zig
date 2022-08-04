const std = @import("std");
const Type = @import("Type.zig");
const Attribute = @import("Attribute.zig");
const Compilation = @import("Compilation.zig");
const Parser = @import("Parser.zig");
const Record = Type.Record;
const Field = Record.Field;
const TypeLayout = Type.TypeLayout;

// almost all the code for record layout
// was liberally copied from this repro
// https://github.com/mahkoh/repr-c
// specifically the code in "repc/impl/src/" directory.
// At the time of this writing (Q3 2022)
// that code marked as "SPDX-License-Identifier: MIT OR Apache-2.0"
// so is compatible with arocc's MIT licence

const BITS_PER_BYTE = 8;

const SysVContext = struct {
    /// Does the record has an __attribute__((packed)) annotation.
    attr_packed: bool,
    /// The value of #pragma pack(N) at the type level if any.
    max_field_align_bits: ?u64,
    /// The alignment of this record.
    aligned_bits: u32,
    is_union: bool,
    /// The size of the record. This might not be a multiple of 8 if the record contains bit-fields.
    /// For structs, this is also the offset of the first bit after the last field.
    size_bits: u64,

    fn init(ty: *Type, comp: *const Compilation, pragma_pack: ?u8) SysVContext {
        var pack_value: ?u64 = null;
        if (pragma_pack) |pak| {
            pack_value = pak * BITS_PER_BYTE;
        }
        var req_align: u29 = BITS_PER_BYTE;
        if (ty.requestedAlignment(comp)) |aln| {
            req_align = aln * BITS_PER_BYTE;
        }
        return SysVContext{
            .attr_packed = ty.hasAttribute(.@"packed"),
            .max_field_align_bits = pack_value,
            .aligned_bits = req_align,
            .is_union = ty.is(.@"union"),
            .size_bits = 0,
        };
    }

    fn layoutFields(self: *SysVContext, rec: *const Record, comp: *const Compilation) void {
        for (rec.fields) |*fld, fld_indx| {
            var type_layout = TypeLayout.init(0, 0);

            computeLayout(fld.ty, comp, &type_layout);

            var field_attrs: ?[]const Attribute = null;
            if (rec.field_attributes) |attrs| {
                field_attrs = attrs[fld_indx];
            }

            if (fld.bit_width != null) {
                self.layoutBitField(comp, fld, field_attrs, type_layout);
            } else {
                self.layoutRegularField(fld, field_attrs, type_layout);
            }
        }
    }

    fn layoutRegularField(
        self: *SysVContext,
        fld: *Field,
        fld_attrs: ?[]const Attribute,
        fld_layout: TypeLayout,
    ) void {
        var fld_align_bits = fld_layout.field_alignment_bits;

        // If the struct or the field is packed, then the alignment of the underlying type is
        // ignored. See test case 0084.
        if (self.attr_packed or isPacked(fld_attrs)) {
            fld_align_bits = BITS_PER_BYTE;
        }

        // The field alignment can be increased by __attribute__((aligned)) annotations on the
        // field. See test case 0085.
        if (annotationAlignment(fld_attrs)) |anno| {
            fld_align_bits = std.math.max(fld_align_bits, anno);
        }

        // #pragma pack takes precedence over all other attributes. See test cases 0084 and
        // 0085.
        if (self.max_field_align_bits) |req_bits| {
            fld_align_bits = std.math.min(fld_align_bits, req_bits);
        }

        // A struct field starts at the next offset in the struct that is properly
        // aligned with respect to the start of the struct.
        const offset_bits = if (self.is_union) 0 else std.mem.alignForwardGeneric(u64, self.size_bits, fld_align_bits);
        const size_bits = fld_layout.size_bits;

        // The alignment of a record is the maximum of its field alignments. See test cases
        // 0084, 0085, 0086.
        self.size_bits = std.math.max(self.size_bits, offset_bits + size_bits);
        self.aligned_bits = std.math.max(self.aligned_bits, fld_align_bits);

        fld.layout.offset_bits = offset_bits;
        fld.layout.size_bits = size_bits;
    }

    fn layoutBitField(
        self: *SysVContext,
        comp: *const Compilation,
        fld: *Field,
        fld_attrs: ?[]const Attribute,
        fld_layout: TypeLayout,
    ) void {
        const bit_width = fld.bit_width.?;

        const ty_size_bits = fld_layout.size_bits;
        var ty_fld_algn_bits: u32 = fld_layout.field_alignment_bits;

        // Some targets ignore the alignment of the underlying type when laying out
        // non-zero-sized bit-fields. See test case 0072. On such targets, bit-fields never
        // cross a storage boundary. See test case 0081.
        if (comp.ignoreNonZeroSizedBitfieldTypeAlignment()) {
            ty_fld_algn_bits = 1;
        }

        if (bit_width == 0) {
            // Some targets have a minimum alignment of zero-sized bit-fields. See test case
            // 0074.
            if (comp.minZeroWidthBitfieldAlignment()) |target_align| {
                ty_fld_algn_bits = std.math.max(ty_fld_algn_bits, target_align);
            }
        }

        // __attribute__((packed)) on the record is identical to __attribute__((packed)) on each
        // field. See test case 0067.
        const attr_packed = self.attr_packed or isPacked(fld_attrs);
        const has_packing_annotation = attr_packed or self.max_field_align_bits != null;

        const annotation_alignment: u32 = annotationAlignment(fld_attrs) orelse 1;

        const first_unused_bit: u64 = if (self.is_union) 0 else self.size_bits;
        var field_align_bits: u64 = 1;

        if (bit_width == 0) {
            field_align_bits = std.math.max(ty_fld_algn_bits, annotation_alignment);
        } else if (comp.langopts.emulate == .gcc) {
            // On GCC, the field alignment is at least the alignment requested by annotations
            // except as restricted by #pragma pack. See test case 0083.
            field_align_bits = annotation_alignment;
            if (self.max_field_align_bits) |max_bits| {
                field_align_bits = std.math.min(annotation_alignment, max_bits);
            }

            // On GCC, if there are no packing annotations and
            // - the field would otherwise start at an offset such that it would cross a
            //   storage boundary or
            // - the alignment of the type is larger than its size,
            // then it is aligned to the type's field alignment. See test case 0083.
            if (!has_packing_annotation) {
                const start_bit = std.mem.alignForwardGeneric(u64, first_unused_bit, field_align_bits);

                const does_field_cross_boundary = start_bit % ty_fld_algn_bits + bit_width > ty_size_bits;

                if (ty_fld_algn_bits > ty_size_bits or does_field_cross_boundary) {
                    field_align_bits = std.math.max(field_align_bits, ty_fld_algn_bits);
                }
            }
        } else {
            std.debug.assert(comp.langopts.emulate == .clang);

            // On Clang, the alignment requested by annotations is not respected if it is
            // larger than the value of #pragma pack. See test case 0083.
            if (annotation_alignment <= self.max_field_align_bits orelse std.math.maxInt(u29)) {
                field_align_bits = std.math.max(field_align_bits, annotation_alignment);
            }
            // On Clang, if there are no packing annotations and the field would cross a
            // storage boundary if it were positioned at the first unused bit in the record,
            // it is aligned to the type's field alignment. See test case 0083.
            if (!has_packing_annotation) {
                const does_field_cross_boundary = first_unused_bit % ty_fld_algn_bits + bit_width > ty_size_bits;

                if (does_field_cross_boundary)
                    field_align_bits = std.math.max(field_align_bits, ty_fld_algn_bits);
            }
        }

        const offset_bits = std.mem.alignForwardGeneric(u64, first_unused_bit, field_align_bits);
        self.size_bits = std.math.max(self.size_bits, offset_bits + bit_width);

        // Unnamed fields do not contribute to the record alignment except on a few targets.
        // See test case 0079.
        if (fld.name_tok != 0 or comp.unnamedFieldAffectsAlignment()) {
            var inherited_align_bits: u32 = undefined;

            if (bit_width == 0) {
                // If the width is 0, #pragma pack and __attribute__((packed)) are ignored.
                // See test case 0075.
                inherited_align_bits = std.math.max(ty_fld_algn_bits, annotation_alignment);
            } else if (self.max_field_align_bits) |max_align_bits| {
                // Otherwise, if a #pragma pack is in effect, __attribute__((packed)) on the field or
                // record is ignored. See test case 0076.
                inherited_align_bits = std.math.max(ty_fld_algn_bits, annotation_alignment);
                inherited_align_bits = std.math.min(inherited_align_bits, max_align_bits);
            } else if (attr_packed) {
                // Otherwise, if the field or the record is packed, the field alignment is 1 bit unless
                // it is explicitly increased with __attribute__((aligned)). See test case 0077.
                inherited_align_bits = annotation_alignment;
            } else {
                // Otherwise, the field alignment is the field alignment of the underlying type unless
                // it is explicitly increased with __attribute__((aligned)). See test case 0078.
                inherited_align_bits = std.math.max(ty_fld_algn_bits, annotation_alignment);
            }
            self.aligned_bits = std.math.max(self.aligned_bits, inherited_align_bits);
        }

        fld.layout.size_bits = bit_width;
        fld.layout.offset_bits = offset_bits;
    }
};

const MscvContext = struct {
    req_align_bits: u32,
    max_field_align_bits: ?u32,
    /// The alignment of pointers that point to an object of this type. This is greater to or equal
    /// to the required alignment. Once all fields have been laid out, the size of the record will be
    /// rounded up to this value.
    pointer_align_bits: u32,
    /// The alignment of this type when it is used as a record field. This is greater to or equal to
    /// the pointer alignment.
    field_align_bits: u32,
    size_bits: u64,
    ongoing_bitfield: ?OngoingBitfield,
    contains_non_bitfield: bool,
    is_union: bool,

    const OngoingBitfield = struct {
        size_bits: u64,
        unused_size_bits: u64,
    };

    fn init(ty: *const Type, comp: *const Compilation, pragma_pack: ?u8) MscvContext {
        var pack_value: ?u32 = null;
        if (ty.hasAttribute(.@"packed")) {
            // __attribute__((packed)) behaves like #pragma pack(1) in clang. See test case 0056.
            pack_value = BITS_PER_BYTE;
        }
        if (pack_value == null) {
            if (pragma_pack) |pack| {
                pack_value = pack * BITS_PER_BYTE;
                // std.debug.print("pragma : {}\n", .{pack});
            }
        }
        if (pack_value) |pack| {
            pack_value = msvcPragmaPack(comp, pack);
            // std.debug.print("pre:{} post:{?}\n", .{ pack, pack_value });
        }

        // The required alignment can be increased by adding a __declspec(align)
        // annotation. See test case 0023.
        var must_align: u29 = BITS_PER_BYTE;
        if (ty.requestedAlignment(comp)) |req_align| {
            must_align = req_align * BITS_PER_BYTE;
        }
        return MscvContext{
            .req_align_bits = must_align,
            .pointer_align_bits = must_align,
            .field_align_bits = must_align,
            .size_bits = 0,
            .max_field_align_bits = pack_value,
            .ongoing_bitfield = null,
            .contains_non_bitfield = false,
            .is_union = ty.is(.@"union"),
        };
    }

    fn layoutField(self: *MscvContext, comp: *const Compilation, fld: *Field, fld_attrs: ?[]const Attribute) void {
        var type_layout: TypeLayout = TypeLayout.init(0, 0);

        computeLayout(fld.ty, comp, &type_layout);

        // The required alignment of the field is the maximum of the required alignment of the
        // underlying type and the __declspec(align) annotation on the field itself.
        // See test case 0028.
        var req_align = type_layout.required_alignment_bits;
        if (annotationAlignment(fld_attrs)) |anno| {
            req_align = std.math.max(anno, req_align);
        }

        // The required alignment of a record is the maximum of the required alignments of its
        // fields except that the required alignment of bitfields is ignored.
        // See test case 0029.
        if (fld.bit_width == null) {
            self.req_align_bits = std.math.max(self.req_align_bits, req_align);
        }

        // The offset of the field is based on the field alignment of the underlying type.
        // See test case 0027.
        var fld_align_bits = type_layout.field_alignment_bits;
        if (self.max_field_align_bits) |max_align| {
            fld_align_bits = std.math.min(fld_align_bits, max_align);
        }

        if (isPacked(fld_attrs)) {
            // __attribute__((packed)) on a field is a clang extension. It behaves as if #pragma
            // pack(1) had been applied only to this field. See test case 0057.
            fld_align_bits = BITS_PER_BYTE;
        }
        // __attribute__((packed)) on a field is a clang extension. It behaves as if #pragma
        // pack(1) had been applied only to this field. See test case 0057.
        fld_align_bits = std.math.max(fld_align_bits, req_align);
        if (fld.bit_width) |bit_width| {
            self.layoutBitField(type_layout.size_bits, fld_align_bits, fld.name_tok != 0, bit_width);
        } else {
            self.layoutRegularField(type_layout.size_bits, fld_align_bits, fld);
        }
    }

    fn layoutBitField(self: *MscvContext, size_bits: u64, field_align: u64, is_named: bool, bit_width: u32) void {
        _ = self;
        _ = size_bits;
        _ = field_align;
        _ = is_named;
        _ = bit_width;
        // TODO
    }

    fn layoutRegularField(self: *MscvContext, size_bits: u64, field_align: u32, fld: *Field) void {
        self.contains_non_bitfield = true;
        self.ongoing_bitfield = null;
        self.pointer_align_bits = std.math.max(self.pointer_align_bits, field_align);
        self.field_align_bits = std.math.max(self.field_align_bits, field_align);
        const offset_bits = switch (self.is_union) {
            true => 0,
            false => std.mem.alignForwardGeneric(u64, self.size_bits, field_align),
        };
        self.size_bits = std.math.max(self.size_bits, offset_bits + size_bits);
        fld.layout = .{
            .offset_bits = offset_bits,
            .size_bits = size_bits,
        };
    }
};

pub fn compute(ty: *Type, comp: *const Compilation, pragma_pack: ?u8) void {
    // const mapper = comp.string_interner.getSlowTypeMapper();
    // const name = mapper.lookup(ty.getRecord().?.name);
    // std.debug.print("struct {s}\n", .{name});
    switch (comp.langopts.emulate) {
        .gcc, .clang => {
            var context = SysVContext.init(ty, comp, pragma_pack);
            var rec = getMutableRecord(ty);

            context.layoutFields(rec, comp);

            context.size_bits = std.mem.alignForwardGeneric(u64, context.size_bits, context.aligned_bits);

            rec.type_layout = TypeLayout{
                .size_bits = context.size_bits,
                .field_alignment_bits = context.aligned_bits,
                .pointer_alignment_bits = context.aligned_bits,
                .required_alignment_bits = BITS_PER_BYTE,
            };
        },
        .msvc => {
            var context = MscvContext.init(ty, comp, pragma_pack);
            var rec = getMutableRecord(ty);

            for (rec.fields) |*fld, fld_indx| {
                var field_attrs: ?[]const Attribute = null;
                if (rec.field_attributes) |attrs| {
                    field_attrs = attrs[fld_indx];
                }

                context.layoutField(comp, fld, field_attrs);
            }
            rec.type_layout = TypeLayout{
                .size_bits = context.size_bits,
                .field_alignment_bits = context.field_align_bits,
                .pointer_alignment_bits = context.pointer_align_bits,
                .required_alignment_bits = context.req_align_bits,
            };
        },
    }
}

pub fn computeLayout(ty: Type, comp: *const Compilation, type_layout: *TypeLayout) void {
    if (ty.getRecord()) |rec| {
        type_layout.* = rec.type_layout;
    } else {
        type_layout.size_bits = ty.bitSizeof(comp) orelse 0;
        type_layout.pointer_alignment_bits = ty.alignof(comp) * BITS_PER_BYTE;
        type_layout.field_alignment_bits = type_layout.pointer_alignment_bits;
        type_layout.required_alignment_bits = BITS_PER_BYTE;
    }
}

pub fn getMutableRecord(ty: *Type) *Type.Record {
    return switch (ty.specifier) {
        .attributed => getMutableRecord(&ty.data.attributed.base),
        .typeof_type, .decayed_typeof_type => getMutableRecord(ty.data.sub_type),
        .typeof_expr, .decayed_typeof_expr => getMutableRecord(&ty.data.expr.ty),
        .@"struct", .@"union" => ty.data.record,
        else => unreachable,
    };
}

fn isPacked(attrs: ?[]const Attribute) bool {
    const a = attrs orelse return false;

    for (a) |attribute| {
        if (attribute.tag != .@"packed") continue;
        return true;
    }
    return false;
}

/// get alignment annotation on the field
/// not the one on the underlying type
fn annotationAlignment(attrs: ?[]const Attribute) ?u32 {
    const a = attrs orelse return null;

    var max_requested: ?u32 = null;
    for (a) |attribute| {
        if (attribute.tag != .aligned) continue;
        if (attribute.args.aligned.alignment) |alignment| {
            const requested = alignment.requested * BITS_PER_BYTE;
            if (max_requested == null or max_requested.? < requested) {
                max_requested = requested;
            }
        }
    }
    return max_requested;
}

// The effect of #pragma pack(N) depends on the target.
//
// x86: By default, there is no maximum field alignment. N={1,2,4} set the maximum field
//      alignment to that value. All other N activate the default.
// x64: By default, there is no maximum field alignment. N={1,2,4,8} set the maximum field
//      alignment to that value. All other N activate the default.
// arm: By default, the maximum field alignment is 8. N={1,2,4,8,16} set the maximum field
//      alignment to that value. All other N activate the default.
// arm64: By default, the maximum field alignment is 8. N={1,2,4,8} set the maximum field
//        alignment to that value. N=16 disables the maximum field alignment. All other N
//        activate the default.
//
// See test case 0020.
pub fn msvcPragmaPack(comp: *const Compilation, pack: u32) ?u32 {
    return switch (pack) {
        8, 16, 32 => pack,
        64 => if (comp.target.cpu.arch == .i386) null else pack,
        128 => if (comp.target.cpu.arch == .thumb) pack else null,
        else => {
            return switch (comp.target.cpu.arch) {
                .thumb, .aarch64 => 64,
                else => null,
            };
        },
    };
}
