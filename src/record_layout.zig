const std = @import("std");

const Type = @import("Type.zig");
const Attribute = @import("Attribute.zig");
const Compilation = @import("Compilation.zig");
const Parser = @import("Parser.zig");
const Record = Type.Record;
const Field = Record.Field;
const TypeLayout = Type.TypeLayout;

const assert = std.debug.assert;

// almost all the code for record layout
// was liberally copied from this repro
// https://github.com/mahkoh/repr-c
// specifically the code in "repc/impl/src/" directory.
// At the time of this writing (Q2 2022)
// that code marked as "SPDX-License-Identifier: MIT OR Apache-2.0"
// so is compatable with arocc's MIT licence

const RecordContext = struct {
    // Whether the record has an __attribute__((packed)) annotation.
    attr_packed: bool,
    // The value of #pragma pack(N) at the type level if any.
    max_field_align_bits: ?u29,
    // The alignment of this record.
    aligned_bits: u29,
    is_union: bool,
    // The size of the record. This might not be a multiple of 8 if the record contains bit-fields.
    // For structs, this is also the offset of the first bit after the last field.
    size_bits: u29,
};

const int_type = Type{ .specifier = .int };

pub const BITS_PER_BYTE: u29 = 8;

pub fn computeLayout(ty: *Type, p: *const Parser, type_layout: *TypeLayout) void {
    if (ty.isRecord()) {
        const record_ty = ty.getRecord() orelse unreachable;
        const rec = record_ty.data.record;
        if( rec.type_layout.field_alignment_bits != 0 ) {
            type_layout.* = rec.type_layout;
        } else {
            // I don't think this should ever happen...
            std.debug.panic("field of type record not laid out.", .{});
        }
    } else if (ty.isArray()) {
        layoutArray(ty, p, type_layout);
    } else if (ty.isEnum()) {
        layoutEnum(ty, p.pp.comp, type_layout);
    } else {
        type_layout.size_bits = @intCast(u29, ty.bitSizeof(p.pp.comp).?);
        type_layout.pointer_alignment_bits = rawAlignOf(ty, p.pp.comp) * BITS_PER_BYTE;
        type_layout.field_alignment_bits = type_layout.pointer_alignment_bits;
        type_layout.required_alignmnet_bits = BITS_PER_BYTE;
    }

}



pub fn recordLayout(ty: *Type, p: *const Parser) void {
    assert(ty.isRecord());
    const record_ty = ty.getRecord() orelse unreachable;
    const rec = record_ty.data.record;

    var pack_value : ?u29 = null;
    if( p.pragma_pack) |pak| {
        const pv = @intCast(u29, pak) * BITS_PER_BYTE;
        if( pv >= 8 and pv <= 128 and std.math.isPowerOfTwo(pv)) {
            pack_value = pv;
        }
    }


    var req_align:u29 = annotationAlignment(ty, p.pp.comp) orelse BITS_PER_BYTE;

    var record_context = RecordContext{
        .attr_packed =  ty.isPacked(),
        .max_field_align_bits = pack_value,
        .aligned_bits = req_align,
        .is_union = record_ty.specifier == .@"union",
        .size_bits = 0,
    };

    // std.debug.print("new-record {s} {any}\n", .{rec.name, record_context});

    for (rec.fields) |*fld| {
    
        var type_layout: TypeLayout = .{
            .size_bits = 0,
            .field_alignment_bits = 0,
            .pointer_alignment_bits = 0,
            .required_alignmnet_bits = 0,
        };
        // recursion
        computeLayout(&fld.ty, p, &type_layout);

        if (fld.bit_width != null) {
            layoutBitField(p.pp.comp, fld, &type_layout, &record_context);
        } else {
            layoutRegluarField(p.pp.comp, fld, type_layout, &record_context);
        }
        // std.debug.print("fld-post {s}\n\tfld_type_layout:{any}\n\tcontext:{any}\n\tlayout:{any}\n", .{fld.name,type_layout, record_context, fld.layout});
    }

    record_context.size_bits = alignTo(record_context.size_bits, record_context.aligned_bits);
    rec.type_layout.size_bits = record_context.size_bits;
    rec.type_layout.field_alignment_bits = record_context.aligned_bits;
    rec.type_layout.pointer_alignment_bits = record_context.aligned_bits;
    rec.type_layout.required_alignmnet_bits = BITS_PER_BYTE;
    rec.size = record_context.size_bits / BITS_PER_BYTE;
    rec.alignment = record_context.aligned_bits / BITS_PER_BYTE;

    // std.debug.print("done record {s}\n\t{any}\n\ta:{} s:{}\n\n", .{rec.name, rec.type_layout, rec.alignment, rec.size});

}

fn layoutRegluarField(
    comp: *const Compilation,
    fld: *Field,
    fld_layout: TypeLayout,
    record_context: *RecordContext,
) void {

    var fld_align_bits = fld_layout.field_alignment_bits;
    if (record_context.attr_packed or fld.ty.isPacked()) {
        fld_align_bits = BITS_PER_BYTE;
    }
    
    if( annotationAlignment(&fld.ty, comp) ) |anno| {
        fld_align_bits = std.math.max( fld_align_bits, anno );
    }

    if (record_context.max_field_align_bits) |req_bits| {
        fld_align_bits = std.math.min(fld_align_bits, req_bits);
    }

    var offset_bits = if (record_context.is_union) 0 else alignTo(record_context.size_bits, fld_align_bits);
    var size_bits = fld_layout.size_bits;

    record_context.size_bits = std.math.max(record_context.size_bits, offset_bits + size_bits);
    record_context.aligned_bits = std.math.max(record_context.aligned_bits, fld_align_bits);

    fld.layout.offset_bits = offset_bits;
    fld.layout.size_bits = size_bits;
}

fn layoutBitField(
    comp: *const Compilation,
    fld: *Field,
    fld_layout: *TypeLayout,
    record_context: *RecordContext,
) void {
    assert(fld.bit_width != null);
    const bit_width = fld.bit_width orelse unreachable;
    
    const ty_size_bits = fld_layout.size_bits;
    var ty_fld_algn_bits = fld_layout.field_alignment_bits;

    if( bit_width > fld_layout.size_bits ) {
        // TODO: errror msg.
    }

    if( ignoreNonZeroSizedBitfieldTypeAlignment(comp) ) {
        ty_fld_algn_bits = 1;        
    }

    if (bit_width > 0) {
        if (bit_width > fld_layout.size_bits) {
            // TODO: real error
            std.debug.panic("size of bit field exteends size of type {any}", .{fld});
        }
    } else {
        if (minZeroWidthBitfieldAlignment(comp)) |target_align| {
            ty_fld_algn_bits = std.math.max(ty_fld_algn_bits, target_align);
        }
    }

    const attr_packed = record_context.attr_packed or fld.ty.isPacked();
    const has_packing_annotation = attr_packed or record_context.max_field_align_bits != null;
    
    const annotation_alignment:u29 = annotationAlignment(&fld.ty, comp) orelse 1;

    var first_unused_bit: u29 = if (record_context.is_union) 0 else record_context.size_bits;

    var field_align_bits: u29 = 1;

    if (bit_width == 0) {
        field_align_bits = std.math.max(ty_fld_algn_bits, annotation_alignment);
    } else if (comp.mimic == .gcc) {
        std.debug.panic("gcc not working yet", .{});
        field_align_bits = annotation_alignment;
        if (record_context.max_field_align_bits) |max_bits| {
            field_align_bits = std.math.min(annotation_alignment, max_bits);
        }

        if (!has_packing_annotation) {
            var start_bit = alignTo(first_unused_bit, field_align_bits);

            var does_field_cross_boundary = start_bit % ty_fld_algn_bits + bit_width > ty_size_bits;

            if (ty_fld_algn_bits > ty_size_bits or does_field_cross_boundary) {
                field_align_bits = std.math.max(field_align_bits, ty_fld_algn_bits);
            }
        }
    } else {
        assert(comp.mimic == .clang);

        // On Clang, the alignment requested by annotations is not respected if it is
        // larger than the value of #pragma pack. See test case 0083.
        if (annotation_alignment <= record_context.max_field_align_bits orelse std.math.maxInt(u29)) {
            field_align_bits = std.math.max(field_align_bits, annotation_alignment);
        }
        // On Clang, if there are no packing annotations and the field would cross a
        // storage boundary if it were positioned at the first unused bit in the record,
        // it is aligned to the type's field alignment. See test case 0083.
        if (!has_packing_annotation) {
            var does_field_cross_boundary = first_unused_bit % ty_fld_algn_bits + bit_width > ty_size_bits;

            if (does_field_cross_boundary)
                field_align_bits = std.math.max(field_align_bits, ty_fld_algn_bits);
        }
    }

    var offset_bits = alignTo(first_unused_bit, field_align_bits);
    record_context.size_bits = std.math.max(record_context.size_bits, offset_bits + bit_width);

    // Unnamed fields do not contribute to the record alignment except on a few targets.
    // See test case 0079.
    if (fld.name_tok != 0 or minZeroWidthBitfieldAlignment(comp) != null) {
        var inherited_align_bits:u29 = undefined;

        if( bit_width == 0 ) {
            // If the width is 0, #pragma pack and __attribute__((packed)) are ignored.
            // See test case 0075.
            inherited_align_bits = std.math.max( ty_fld_algn_bits, annotation_alignment );

        } else if( record_context.max_field_align_bits ) |max_align_bits| {
            // Otherwise, if a #pragma pack is in effect, __attribute__((packed)) on the field or
            // record is ignored. See test case 0076.
            inherited_align_bits = std.math.max( ty_fld_algn_bits, annotation_alignment );
            inherited_align_bits = std.math.min( inherited_align_bits, max_align_bits);
        } else if( attr_packed ) {
            // Otherwise, if the field or the record is packed, the field alignment is 1 bit unless
            // it is explicitly increased with __attribute__((aligned)). See test case 0077.
            inherited_align_bits = annotation_alignment;
        } else {
            // Otherwise, the field alignment is the field alignment of the underlying type unless
            // it is explicitly increased with __attribute__((aligned)). See test case 0078.
            inherited_align_bits = std.math.max(ty_fld_algn_bits, annotation_alignment);
        }
        record_context.aligned_bits = std.math.max(record_context.aligned_bits, inherited_align_bits);
    }

    fld.layout.size_bits = bit_width;
    fld.layout.offset_bits = offset_bits;

}

fn layoutArray(ty: *const Type, p: *const Parser, type_layout: *TypeLayout) void {
    var ar_ty = ty.getArray() orelse unreachable; // strip any alignment / typedef

    if (ar_ty.data.array.len > std.math.maxInt(u29)) {
        // TODO: real error msg.
        std.debug.panic("array len to big to hold in u29", .{});
    }
    const a_len = @intCast(u29, ar_ty.data.array.len);

    computeLayout(&ar_ty.data.array.elem, p, type_layout);

    var full_size: u29 = 0;
    if (@mulWithOverflow(u29, type_layout.size_bits, a_len, &full_size)) {
        // TODO, meaningfull error and return.
        std.debug.panic("array sizne for type overflows {any}", .{ty});
    }
    type_layout.size_bits = alignTo(full_size, type_layout.field_alignment_bits);

    type_layout.pointer_alignment_bits = type_layout.field_alignment_bits;
}

fn layoutEnum(ty: *const Type, comp: *const Compilation, type_layout: *TypeLayout) void {
    std.debug.assert(ty.isEnum());

    var alignment = ty.alignof(comp);

    type_layout.size_bits = @intCast(u29, ty.bitSizeof(comp).?);
    type_layout.pointer_alignment_bits = alignment * BITS_PER_BYTE;
    type_layout.field_alignment_bits = alignment * BITS_PER_BYTE;
    type_layout.required_alignmnet_bits = BITS_PER_BYTE;

    // only clang honers requested alignment
    if (comp.mimic == .clang) {
        if (ty.requestedAlignment(comp)) |req_align| {
            type_layout.field_alignment_bits = std.math.max(type_layout.field_alignment_bits, req_align);
            type_layout.pointer_alignment_bits = std.math.min(type_layout.pointer_alignment_bits, req_align);
        }
    }
}


fn alignTo(n: u29, m: u29) u29 {
    if( !std.math.isPowerOfTwo(m) ) {
        std.debug.panic("align pow fail. n:{} m:{}\n", .{n,m});
    }
    var mask = m - 1;
    var res: u29 = 0;
    if (@addWithOverflow(u29, n, mask, &res)) {
        std.debug.panic("alingTo overflow", .{});
    } else {
        return res & ~mask;
    }
}



fn annotationAlignment(ty:*const Type, comp: *const Compilation ) ?u29 {
    var req_align:?u29 = null;
    if(ty.getAttribute(.aligned)) |args| {
        if( args.alignment ) |al| {
            req_align = al.requested * BITS_PER_BYTE;
        } else {
            req_align = comp.defaultAlignment() * BITS_PER_BYTE;
        }
    }
    return req_align;
}


fn rawAlignOf(ty: *const Type, comp: *const Compilation) u29 {
    return switch (ty.specifier) {
        .typeof_type, .decayed_typeof_type => rawAlignOf(ty.data.sub_type, comp),
        .typeof_expr, .decayed_typeof_expr => rawAlignOf(&ty.data.expr.ty, comp),
        .attributed => rawAlignOf(&ty.data.attributed.base, comp),
        else => ty.alignof(comp),
    };
}



//
// TODO: Move all these to Compilation?
//


fn ignoreNonZeroSizedBitfieldTypeAlignment(comp: *const Compilation) bool {
    switch (comp.target.cpu.arch) {
        .avr => return true,
        .arm => {
            if (std.Target.arm.featureSetHas(comp.target.cpu.features, .has_v7)) {
                switch (comp.target.os.tag) {
                    .ios => return true,
                    else => return false,
                }
            }
        },
        else => return false,
    }
    return false;
}

fn minZeroWidthBitfieldAlignment(comp: *const Compilation) ?u29 {
    switch (comp.target.cpu.arch) {
        .avr => return 8,
        .arm => {
            if (std.Target.arm.featureSetHas(comp.target.cpu.features, .has_v7)) {
                switch (comp.target.os.tag) {
                    .ios => return 32,
                    else => return null,
                }
            } else return null;
        },
        else => return null,
    }
}

// TODO : very likely not correct.
fn unnamedFieldAffectsAlignment(comp: *const Compilation) bool {
    switch (comp.target.cpu.arch) {
        .arch64 => {
            if (comp.target.os.isDarwin() or comp.target.os.tag == .windows) return false;
        },
        .armeb => {
            if (std.Target.arm.featureSetHas(comp.target.cpu.features, .has_v7)) {
                if (comp.target.abi.default(comp.target.cpu.arch, comp.target.os) == .eabi) return true;
            }
        },
    }
    return false;
}

fn packAllEnums(comp: *const Compilation) bool {
    return switch (comp.target.cpu.arch) {
        .hexagon => true,
        else => false,
    };
}
