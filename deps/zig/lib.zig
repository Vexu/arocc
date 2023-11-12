pub const arch = struct {
    pub const x86_64 = struct {
        pub const abi = @import("arch/x86_64/abi.zig");
        pub const bits = @import("arch/x86_64/bits.zig");
        pub const encoder = @import("arch/x86_64/encoder.zig");
        pub const Mir = @import("arch/x86_64/Mir.zig");
        pub const Lower = @import("arch/x86_64/Lower.zig");
    };
};
pub const RegisterManager = @import("register_manager.zig").RegisterManager;
pub const InternPool = @import("InternPool.zig");
