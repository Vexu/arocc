//! Stub to satisfy the type system.
pub const File = struct {
    dummy: u32,
    pub const Elf = struct {
        pub fn zigObjectPtr(_: *Elf) ?*ZigObject {
            return null;
        }
        pub fn symbol(_: *Elf, _: u32) *Symbol {
            return undefined;
        }
        pub const Symbol = struct {
            flags: struct { needs_zig_got: bool },
        };
    };
    pub const ZigObject = struct {
        pub fn symbol(_: *ZigObject, _: u32) u32 {
            return undefined;
        }
        pub const Symbol = struct {
            sym_index: u32,
        };
    };
    pub fn cast(_: *File, comptime T: type) ?*T {
        return null;
    }
};
