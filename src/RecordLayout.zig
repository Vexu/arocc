const std = @import("std");


const Type = @import("Type.zig");
const Attribute = @import("Attribute.zig");
const Compilation = @import("Compilation.zig");
const Parser = @import("Parser.zig");

const assert = std.debug.assert;


const RequestedLayout = struct {
    // null for none. 8 for `#parama pack()`
    // n*8 for `#prama pack(N)`
    packed_bits: ?u29,
    // requested alignment
    aligned_bits: u29,
};

pub const TypeLayout = struct {
    size_bits: u29,
    field_alignment_bits: u29,
    pointer_alignment_bits: u29,
    required_alignmnet_bits: u29,
};

const FieldLayout = struct {
    offset_bits: u29,
    size_bits: u29,
};

const int_type = Type { .specifier =  .int };

pub const BITS_PER_BYTE: u29 = 8;

pub fn computeLayout(ty:Type, p: *const Parser, layout: *TypeLayout) void {

    if (ty.isRecord()) {
        recordLayout(ty, p, layout);
    } else if (ty.isArray()) {
        checkNoAttbiute(ty);
        layoutArray(ty,p,layout);
    } else if (ty.isEnum()) {
        checkNoAttbiute(ty);
        layoutEnum(ty, p.pp.comp, layout);
    } else {
        checkNoAttbiute(ty);
        layout.size_bits = @intCast(u29, ty.bitSizeof(p.pp.comp).?);
        layout.pointer_alignment_bits = ty.alignof(p.pp.comp) * BITS_PER_BYTE;
        layout.field_alignment_bits = layout.pointer_alignment_bits;
        layout.required_alignmnet_bits = BITS_PER_BYTE;
    }
}

fn checkNoAttbiute(ty:Type) void {
    if( ty.requestedAlignment != null or ty.requestedPack != null ) {
        // maybe this is a warning?
        std.debug.panic("alignment ignored for this field type in records",.{});
    }
}

fn alignTo(n:u29,m:u29) ?u29 {
    assert(std.math.isPowerOfTwo(m));
    var mask = m - 1;
    var res:u29=0;
    if( @addWithOverflow(u29, n, mask,&res) ) {
        return null;
    } else {
        return res & ~mask;
    }
}



pub fn recordLayout(ty:Type, p: *const Parser, layout: *TypeLayout) void {
    assert(ty.isRecord());
    const record_ty = ty.getRecord() orelse unreachable;
    const rec = record_ty.data.record;

    std.debug.print("\nrecord = {s}\n", .{rec.name});
    std.debug.print("\trec:{any}\n", .{rec});

    var requested_layout = RequestedLayout{
        .packed_bits = ty.requestedPack() orelse BITS_PER_BYTE,
        .aligned_bits = ty.requestedAlignment(p.pp.comp) orelse BITS_PER_BYTE,
    };

    // pack value must be multiple of 2 and <= 128
    var max_field_alignment_bits = if (requested_layout.packed_bits) |pack| blk: {
        if (pack > 128 or pack < BITS_PER_BYTE or !std.math.isPowerOfTwo(pack) ) {
            //TODO compiler warning?
            std.debug.panic("pack value is invalid {any}",.{ty});
            unreachable;
        }
        break :blk pack;
    } else BITS_PER_BYTE;

    const flds_layout = std.ArrayList(TypeLayout).initCapacity(p.arena, rec.fields.len) catch |err| {
        // out of memory error. TODO: error msg
        std.debug.panic("OOM {any}",.{err});
    };

    layout.size_bits = 0;


    for (rec.fields) |fld, idx| {
        var fld_layout = &flds_layout.items[idx];

        computeLayout( fld.ty, p, fld_layout );

        var align_bits = fld_layout.field_alignment_bits;

        if( fld.bit_width ) |bit_width| {

            if(bit_width > fld_layout.size_bits ) {
                // TODO: real error
                std.debug.panic("size of bit field exteends size of type {any}",.{fld});
            }

            // these targets ignore type alignment on bitfields.
            if(minZeroWidthBitfieldAlignment(p.pp.comp) != null) {
                align_bits = 1;
            }
            if( bit_width == 0 ) {
                if(minZeroWidthBitfieldAlignment(p.pp.comp)) |target_align| {
                    align_bits = std.math.max( align_bits, target_align );
                }
            }

            var is_packed = ty.requestedPack() != null or fld.ty.requestedPack() != null;
            var has_packing_annotation = is_packed or requested_layout.packed_bits != null;
            const annotation_alignment = fld.ty.requestedAlignment(p.pp.comp);
            _ = annotation_alignment;
            var first_unused_bit = switch( ty.specifier ) {
                .@"union" => 0,
                .@"struct" => layout.size_bits,
                else => unreachable,
            };

            var field_alignment_bits = 1;

            if( bit_width == 0) {
                if(requested_layout.packed_bits) |pak| {
                    field_alignment_bits = std.math.max(field_alignment_bits, pak );
                }
            } else if( p.pp.comp.mimic == .gcc) {
                if(requested_layout.packed_bits) |pak| {
                    field_alignment_bits = std.math.max(field_alignment_bits, pak );
                }
                if( !has_packing_annotation ) {
                    var start_bit = alignTo(first_unused_bit, field_alignment_bits);
                    var does_field_cross_boundy = start_bit % fld_layout.field_alignment_bits + bit_width > fld_layout.size_bits;
                    if(  fld_layout.field_alignment_bits > fld_layout.size_bits or does_field_cross_boundy ) {
                        field_alignment_bits = std.math.max(field_alignment_bits, fld_layout.field_alignment_bits);
                    }
                }

            } else {
                assert( p.pp.comp.mimic == .clang );
                
            }



        } else {
            _ = 10;
        }

    }

    rec.size = 1;
    rec.alignment = requested_layout.aligned_bits / BITS_PER_BYTE;

    layout.size_bits = BITS_PER_BYTE;
    layout.field_alignment_bits = max_field_alignment_bits;
    layout.pointer_alignment_bits = BITS_PER_BYTE;
    layout.required_alignmnet_bits = BITS_PER_BYTE;

}

fn layoutArray(ty:Type, p: *const Parser, layout: *TypeLayout) void {


    var ar_ty = ty.unwrap(); // strip any alignment / typedef

    if( ar_ty.data.array.len > std.math.maxInt(u29)) {
        // TODO: real error msg.
        std.debug.panic("array len to big to hold in u29",.{});
    }
    const a_len = @intCast(u29, ar_ty.data.array.len);


    computeLayout(ar_ty.data.array.elem, p, layout);

    var full_size:u29=0;
    if( @mulWithOverflow(u29, layout.size_bits, a_len, &full_size) ) {
        // TODO, meaningfull error and return.
        std.debug.panic("array sizne for type overflows {any}",.{ty});
        }
        if( alignTo( full_size, layout.size_bits) ) |final_align| {
        layout.size_bits = final_align;
    } else {
        // TODO, meaningfull error and return.
        std.debug.panic("can not align array/array-type {any}",.{ty});
    }
    layout.pointer_alignment_bits = layout.field_alignment_bits;
}

fn layoutEnum(ty:Type, comp: *const Compilation, layout: *TypeLayout)  void {
    
    std.debug.assert( ty.isEnum() );

    var alignment = rawAlignOf(&ty, comp);

    layout.size_bits = @intCast(u29,ty.bitSizeof(comp).?);
    layout.pointer_alignment_bits = alignment * BITS_PER_BYTE;
    layout.field_alignment_bits = alignment * BITS_PER_BYTE;
    layout.required_alignmnet_bits = BITS_PER_BYTE;

    // only clang honers requested alignment
    if(comp.mimic == .clang) {
        if( ty.requestedAlignment(comp) ) |req_align| {
            layout.field_alignment_bits = std.math.max( layout.field_alignment_bits, req_align );
            layout.pointer_alignment_bits = std.math.min( layout.pointer_alignment_bits, req_align );
        }
    }
}

fn rawAlignOf(ty:*const Type, comp: *const Compilation) u29 {
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

fn minZeroWidthBitfieldAlignment( comp: *const Compilation ) ?u29 {
    switch(comp.target.cpu.arch) {
        .avr => return 8,
        .arm => {
            if( std.Target.arm.featureSetHas( comp.target.cpu.features,  .has_v7 ) ) {
                switch(comp.target.os.tag) {
                    .ios => return 32,
                    else => return null,
                }
            } else return null;
        },
        else => return null,
    }

}


fn packAllEnums(comp: *const Compilation) bool {
    return switch (comp.target.cpu.arch) {
        .hexagon => true,
        else => false,
    };

}
