pub const codegen = struct {
    pub const x86_64 = @import("codegen/x86_64.zig");
};
pub const RegisterManager = @import("register_manager.zig").RegisterManager;
