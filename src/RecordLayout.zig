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
        // TODO : this won't work,
        // need to call try p.withAttributes(ty, attr_buf_top) but don't know how to do that.
        recordLayout(ty, p);
        const record_ty = ty.getRecord() orelse unreachable;
        const rec = record_ty.data.record;
        type_layout.* = rec.type_layout;
    } else if (ty.isArray()) {
        checkNoAttbiute(ty, p);
        layoutArray(ty, p, type_layout);
    } else if (ty.isEnum()) {
        checkNoAttbiute(ty, p);
        layoutEnum(ty, p.pp.comp, type_layout);
    } else {
        checkNoAttbiute(ty, p);
        type_layout.size_bits = @intCast(u29, ty.bitSizeof(p.pp.comp).?);
        type_layout.pointer_alignment_bits = ty.alignof(p.pp.comp) * BITS_PER_BYTE;
        type_layout.field_alignment_bits = type_layout.pointer_alignment_bits;
        type_layout.required_alignmnet_bits = BITS_PER_BYTE;
        // std.debug.print("basic layout of {s} is {d}\n", .{ty.specifier, type_layout.size_bits });
    }

}

fn checkNoAttbiute(ty: *const Type, p: *const Parser) void {
    if (ty.requestedAlignment(p.pp.comp) != null or ty.isPacked()) {
        // maybe this is a warning?
        // std.debug.print("alignment ignored for this field type in records\n", .{});
    }
}


pub fn recordLayout(ty: *Type, p: *const Parser) void {
    assert(ty.isRecord());
    const record_ty = ty.getRecord() orelse unreachable;
    const rec = record_ty.data.record;

    // std.debug.print("laying out : {s}\n", .{rec.name});
    var record_context = RecordContext{
        .attr_packed = ty.isPacked(),
        .max_field_align_bits = if( ty.isPacked() ) 1 else null, // TODO: get pack value
        .aligned_bits = (ty.requestedAlignment(p.pp.comp) orelse 1) * BITS_PER_BYTE,
        .is_union = ty.specifier == .@"union",
        .size_bits = 0,
    };

    // if( record_context.aligned_bits != BITS_PER_BYTE ) {
    //     std.debug.print("record {s} requested align {d}\n", .{rec.name, record_context.aligned_bits});
    // }

    // pack value must be multiple of 2 and <= 128
    if (record_context.max_field_align_bits) |pack| {
        if (pack > 128 or pack < BITS_PER_BYTE or !std.math.isPowerOfTwo(pack)) {
            //TODO compiler warning
            std.debug.panic("pack value is invalid {any}", .{ty});
            unreachable;
        }
    }

    for (rec.fields) |*fld| {
        var type_layout: TypeLayout = .{
            .size_bits = 0,
            .field_alignment_bits = 0,
            .pointer_alignment_bits = 0,
            .required_alignmnet_bits = 0,
        };
        // recursion
        computeLayout(&fld.ty, p, &type_layout);
        // std.debug.print("\tfld {s} is size {d}\n", .{fld.name, type_layout.size_bits});

        // var old_sz = record_context.size_bits;
        if (fld.bit_width != null) {
            // std.debug.print("bitfield-layout b:{d}\n", .{fld.bit_width});
            layoutBitField(p.pp.comp, fld, &type_layout, &record_context);
        } else {
            // std.debug.print("regluar-layout\n", .{});
            layoutRegluarField(p.pp.comp, fld, type_layout, &record_context);
        }
        // std.debug.print("fld : {any}\n\tcontext : {any}\n\tlayout : {any}\n", .{type_layout, record_context, fld.layout});
        // std.debug.print("\tfld {s} adding {d} to record. total {d}\n", .{fld.name, record_context.size_bits - old_sz, record_context.size_bits});
    }

    record_context.size_bits = alignTo(record_context.size_bits, record_context.aligned_bits);
    // if(record_context.max_field_align_bits) |pak| {
    //     record_context.size_bits =  alignTo(record_context.size_bits, pak);
    // }
    rec.type_layout.size_bits = record_context.size_bits;
    rec.type_layout.field_alignment_bits = record_context.aligned_bits;
    rec.type_layout.pointer_alignment_bits = record_context.aligned_bits;
    rec.type_layout.required_alignmnet_bits = BITS_PER_BYTE;
    rec.size = rec.type_layout.size_bits / BITS_PER_BYTE;
    rec.alignment = rec.type_layout.field_alignment_bits / BITS_PER_BYTE;
    
    // std.debug.print("\nrecord = {s}\n", .{rec.name});
    // std.debug.print("\trec:{any}\n", .{rec.type_layout});
}

fn layoutRegluarField(
    comp: *const Compilation,
    fld: *Field,
    fld_layout: TypeLayout,
    record_context: *RecordContext,
) void {
    var align_bits = fld_layout.field_alignment_bits;
    if (record_context.attr_packed or fld.ty.isPacked()) {
        align_bits = BITS_PER_BYTE;
    }
    align_bits = std.math.max(align_bits, fld.ty.alignof(comp));
    if (record_context.max_field_align_bits) |req_bits| {
        align_bits = std.math.min(align_bits, req_bits);
    }

    var offset_bits = if (record_context.is_union) 0 else alignTo(record_context.size_bits, align_bits);

    // std.debug.print("rc.sb : {d}, ob : {d}, fl.sb : {d}\n", .{ record_context.size_bits, offset_bits, fld_layout.size_bits });
    record_context.size_bits = std.math.max(record_context.size_bits, offset_bits + fld_layout.size_bits);
    record_context.aligned_bits = std.math.max(record_context.aligned_bits, align_bits);

    fld.layout.offset_bits = offset_bits;
    fld.layout.size_bits = fld_layout.size_bits;
    // std.debug.print("fld layout type {s} size {d}\n", .{fld.ty.specifier, record_context.size_bits});
}

fn layoutBitField(
    comp: *const Compilation,
    fld: *Field,
    fld_layout: *TypeLayout,
    record_context: *RecordContext,
) void {
    assert(fld.bit_width != null);
    var bit_width = fld.bit_width orelse unreachable;
    var ty_align_bits = fld_layout.field_alignment_bits;

    // these targets ignore type alignment on bitfields.
    if (minZeroWidthBitfieldAlignment(comp) != null) {
        ty_align_bits = 1;
    }
    if (bit_width > 0) {
        if (bit_width > fld_layout.size_bits) {
            // TODO: real error
            std.debug.panic("size of bit field exteends size of type {any}", .{fld});
        }
    } else {
        if (minZeroWidthBitfieldAlignment(comp)) |target_align| {
            ty_align_bits = std.math.max(ty_align_bits, target_align);
        }
    }

    var attr_packed = record_context.attr_packed or fld.ty.isPacked();
    var has_packing_annotation = attr_packed or record_context.max_field_align_bits != null;
    const annotation_alignment: u29 = fld.ty.requestedAlignment(comp) orelse 1;
    var first_unused_bit: u29 = if (!record_context.is_union) 0 else record_context.size_bits;

    var field_align_bits: u29 = 1;

    if (bit_width == 0) {
        field_align_bits = std.math.max(ty_align_bits, annotation_alignment);
    } else if (comp.mimic == .gcc) {
        field_align_bits = annotation_alignment;
        if (record_context.max_field_align_bits) |max_bits| {
            field_align_bits = std.math.min(annotation_alignment, max_bits);
        }

        if (!has_packing_annotation) {
            var start_bit = alignTo(first_unused_bit, field_align_bits);

            var does_field_cross_boundary = start_bit % ty_align_bits + bit_width > fld_layout.size_bits;

            if (ty_align_bits > fld_layout.size_bits or does_field_cross_boundary) {
                field_align_bits = std.math.max(field_align_bits, ty_align_bits);
            }
        }
    } else {
        assert(comp.mimic == .clang);

        // On Clang, the alignment requested by annotations is not respected if it is
        // larger than the value of #pragma pack
        if (annotation_alignment <= record_context.max_field_align_bits orelse std.math.maxInt(u29)) {
            field_align_bits = std.math.max(field_align_bits, annotation_alignment);
        }
        // On Clang, if there are no packing annotations and the field would cross a
        // storage boundary if it were positioned at the first unused bit in the record,
        // it is aligned to the type's field alignment.
        if (!has_packing_annotation) {
            var does_field_cross_boundary = first_unused_bit % ty_align_bits + bit_width > fld_layout.size_bits;

            if (does_field_cross_boundary)
                field_align_bits = std.math.max(field_align_bits, ty_align_bits);
        }
    }

    var offset_bits = alignTo(first_unused_bit, field_align_bits);
    record_context.size_bits = std.math.max(record_context.size_bits, offset_bits + bit_width);
    fld_layout.field_alignment_bits = ty_align_bits;

    // Unnamed fields do not contribute to the record alignment except on a few targets.
    // TODO: is this how to check for unnamed field?
    if (fld.name.len == 0 or minZeroWidthBitfieldAlignment(comp) != null) {
        std.debug.print("some stuff", .{});
    }


}

fn layoutArray(ty: *const Type, p: *const Parser, type_layout: *TypeLayout) void {
    var ar_ty = ty.getArray() orelse unreachable; // strip any alignment / typedef

    if (ar_ty.data.array.len > std.math.maxInt(u29)) {
        // TODO: real error msg.
        std.debug.panic("array len to big to hold in u29", .{});
    }
    const a_len = @intCast(u29, ar_ty.data.array.len);

    computeLayout(&ar_ty.data.array.elem, p, type_layout);
    // std.debug.print("array type says {any}\n", .{type_layout});

    // std.debug.print("array elm layout {any}\n\tresult = {any}\n", .{ar_ty.data.array.elem, type_layout});
    // var arr_elm_sz = type_layout.size_bits;

    var full_size: u29 = 0;
    if (@mulWithOverflow(u29, type_layout.size_bits, a_len, &full_size)) {
        // TODO, meaningfull error and return.
        std.debug.panic("array sizne for type overflows {any}", .{ty});
    }
    type_layout.size_bits = alignTo(full_size, type_layout.field_alignment_bits);

    type_layout.pointer_alignment_bits = type_layout.field_alignment_bits;
    // std.debug.print("arry layout. elm {d} len {d} total {d}\n", .{arr_elm_sz, a_len, type_layout.size_bits});
}

fn layoutEnum(ty: *const Type, comp: *const Compilation, type_layout: *TypeLayout) void {
    std.debug.assert(ty.isEnum());

    var alignment = rawAlignOf(ty, comp);

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

fn alingTo(n: u29, m: u29) u29 {
    // TODO: error msg
    std.debug.assert(std.math.isPowerOfTwo(m));
    var mask = m - 1;
    var tmp: u29 = 0;
    // I don't use the result. another way to do this?
    if (@addWithOverflow(u29, n, mask, &tmp)) {
        // TODO: compiler error
        std.debug.panic("aling math overflow", .{});
    }
    return n & !mask;
}

fn rawAlignOf(ty: *const Type, comp: *const Compilation) u29 {
    return switch (ty.specifier) {
        .typeof_type, .decayed_typeof_type => rawAlignOf(ty.data.sub_type, comp),
        .typeof_expr, .decayed_typeof_expr => rawAlignOf(&ty.data.expr.ty, comp),
        .attributed => rawAlignOf(&ty.data.attributed.base, comp),
        else => ty.alignof(comp),
    };
}

fn alignTo(n: u29, m: u29) u29 {
    assert(std.math.isPowerOfTwo(m));
    var mask = m - 1;
    var res: u29 = 0;
    if (@addWithOverflow(u29, n, mask, &res)) {
        std.debug.panic("alingTo overflow", .{});
    } else {
        return res & ~mask;
    }
}


//
// TODO: Move all these to Compilation?
//

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
