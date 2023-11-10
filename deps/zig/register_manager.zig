const std = @import("std");
const math = std.math;
const mem = std.mem;
const assert = std.debug.assert;
const Allocator = std.mem.Allocator;
const StaticBitSet = std.bit_set.StaticBitSet;
const expect = std.testing.expect;
const expectEqual = std.testing.expectEqual;
const expectEqualSlices = std.testing.expectEqualSlices;

const log = std.log.scoped(.register_manager);

pub const AllocateRegistersError = error{
    /// No registers are available anymore
    OutOfRegisters,
    /// Can happen when spilling an instruction in codegen runs out of
    /// memory, so we propagate that error
    OutOfMemory,
    /// Can happen when spilling an instruction in codegen triggers integer
    /// overflow, so we propagate that error
    Overflow,
    /// Can happen when spilling an instruction triggers a codegen
    /// error, so we propagate that error
    CodegenFail,
};

pub fn RegisterManager(
    comptime Function: type,
    comptime Register: type,
    comptime Inst: type,
    comptime tracked_registers: []const Register,
) type {
    // architectures which do not have a concept of registers should
    // refrain from using RegisterManager
    assert(tracked_registers.len > 0); // see note above

    return struct {
        /// Tracks the AIR instruction allocated to every register. If
        /// no instruction is allocated to a register (i.e. the
        /// register is free), the value in that slot is undefined.
        ///
        /// The key must be canonical register.
        registers: TrackedRegisters = undefined,
        /// Tracks which registers are free (in which case the
        /// corresponding bit is set to 1)
        free_registers: RegisterBitSet = RegisterBitSet.initFull(),
        /// Tracks all registers allocated in the course of this
        /// function
        allocated_registers: RegisterBitSet = RegisterBitSet.initEmpty(),
        /// Tracks registers which are locked from being allocated
        locked_registers: RegisterBitSet = RegisterBitSet.initEmpty(),

        const Self = @This();

        pub const TrackedRegisters = [tracked_registers.len]Inst;
        pub const TrackedIndex = std.math.IntFittingRange(0, tracked_registers.len - 1);
        pub const RegisterBitSet = StaticBitSet(tracked_registers.len);

        fn getFunction(self: *Self) *Function {
            return @fieldParentPtr(Function, "register_manager", self);
        }

        fn excludeRegister(reg: Register, register_class: RegisterBitSet) bool {
            const index = indexOfRegIntoTracked(reg) orelse return true;
            return !register_class.isSet(index);
        }

        fn markRegIndexAllocated(self: *Self, tracked_index: TrackedIndex) void {
            self.allocated_registers.set(tracked_index);
        }
        fn markRegAllocated(self: *Self, reg: Register) void {
            self.markRegIndexAllocated(indexOfRegIntoTracked(reg) orelse return);
        }

        fn markRegIndexUsed(self: *Self, tracked_index: TrackedIndex) void {
            self.free_registers.unset(tracked_index);
        }
        fn markRegUsed(self: *Self, reg: Register) void {
            self.markRegIndexUsed(indexOfRegIntoTracked(reg) orelse return);
        }

        fn markRegIndexFree(self: *Self, tracked_index: TrackedIndex) void {
            self.free_registers.set(tracked_index);
        }
        fn markRegFree(self: *Self, reg: Register) void {
            self.markRegIndexFree(indexOfRegIntoTracked(reg) orelse return);
        }

        pub fn indexOfReg(
            comptime set: []const Register,
            reg: Register,
        ) ?std.math.IntFittingRange(0, set.len - 1) {
            const Id = @TypeOf(reg.id());
            comptime var min_id: Id = std.math.maxInt(Id);
            comptime var max_id: Id = std.math.minInt(Id);
            inline for (set) |elem| {
                const elem_id = comptime elem.id();
                min_id = @min(elem_id, min_id);
                max_id = @max(elem_id, max_id);
            }

            const OptionalIndex = std.math.IntFittingRange(0, set.len);
            comptime var map = [1]OptionalIndex{set.len} ** (max_id + 1 - min_id);
            inline for (set, 0..) |elem, elem_index| map[comptime elem.id() - min_id] = elem_index;

            const id_index = reg.id() -% min_id;
            if (id_index >= map.len) return null;
            const set_index = map[id_index];
            return if (set_index < set.len) @intCast(set_index) else null;
        }

        pub fn indexOfRegIntoTracked(reg: Register) ?TrackedIndex {
            return indexOfReg(tracked_registers, reg);
        }

        pub fn regAtTrackedIndex(tracked_index: TrackedIndex) Register {
            return tracked_registers[tracked_index];
        }

        /// Returns true when this register is not tracked
        pub fn isRegIndexFree(self: Self, tracked_index: TrackedIndex) bool {
            return self.free_registers.isSet(tracked_index);
        }
        pub fn isRegFree(self: Self, reg: Register) bool {
            return self.isRegIndexFree(indexOfRegIntoTracked(reg) orelse return true);
        }

        /// Returns whether this register was allocated in the course
        /// of this function.
        ///
        /// Returns false when this register is not tracked
        pub fn isRegAllocated(self: Self, reg: Register) bool {
            const index = indexOfRegIntoTracked(reg) orelse return false;
            return self.allocated_registers.isSet(index);
        }

        /// Returns whether this register is locked
        ///
        /// Returns false when this register is not tracked
        fn isRegIndexLocked(self: Self, tracked_index: TrackedIndex) bool {
            return self.locked_registers.isSet(tracked_index);
        }
        pub fn isRegLocked(self: Self, reg: Register) bool {
            return self.isRegIndexLocked(indexOfRegIntoTracked(reg) orelse return false);
        }

        pub const RegisterLock = struct { tracked_index: TrackedIndex };

        /// Prevents the register from being allocated until they are
        /// unlocked again.
        /// Returns `RegisterLock` if the register was not already
        /// locked, or `null` otherwise.
        /// Only the owner of the `RegisterLock` can unlock the
        /// register later.
        pub fn lockRegIndex(self: *Self, tracked_index: TrackedIndex) ?RegisterLock {
            log.debug("locking {}", .{regAtTrackedIndex(tracked_index)});
            if (self.isRegIndexLocked(tracked_index)) {
                log.debug("  register already locked", .{});
                return null;
            }
            self.locked_registers.set(tracked_index);
            return RegisterLock{ .tracked_index = tracked_index };
        }
        pub fn lockReg(self: *Self, reg: Register) ?RegisterLock {
            return self.lockRegIndex(indexOfRegIntoTracked(reg) orelse return null);
        }

        /// Like `lockReg` but asserts the register was unused always
        /// returning a valid lock.
        pub fn lockRegIndexAssumeUnused(self: *Self, tracked_index: TrackedIndex) RegisterLock {
            log.debug("locking asserting free {}", .{regAtTrackedIndex(tracked_index)});
            assert(!self.isRegIndexLocked(tracked_index));
            self.locked_registers.set(tracked_index);
            return RegisterLock{ .tracked_index = tracked_index };
        }
        pub fn lockRegAssumeUnused(self: *Self, reg: Register) RegisterLock {
            return self.lockRegIndexAssumeUnused(indexOfRegIntoTracked(reg) orelse unreachable);
        }

        /// Like `lockReg` but locks multiple registers.
        pub fn lockRegs(
            self: *Self,
            comptime count: comptime_int,
            regs: [count]Register,
        ) [count]?RegisterLock {
            var results: [count]?RegisterLock = undefined;
            for (&results, regs) |*result, reg| result.* = self.lockReg(reg);
            return results;
        }

        /// Like `lockRegAssumeUnused` but locks multiple registers.
        pub fn lockRegsAssumeUnused(
            self: *Self,
            comptime count: comptime_int,
            regs: [count]Register,
        ) [count]RegisterLock {
            var results: [count]RegisterLock = undefined;
            for (&results, regs) |*result, reg| result.* = self.lockRegAssumeUnused(reg);
            return results;
        }

        /// Unlocks the register allowing its re-allocation and re-use.
        /// Requires `RegisterLock` to unlock a register.
        /// Call `lockReg` to obtain the lock first.
        pub fn unlockReg(self: *Self, lock: RegisterLock) void {
            log.debug("unlocking {}", .{regAtTrackedIndex(lock.tracked_index)});
            self.locked_registers.unset(lock.tracked_index);
        }

        /// Returns true when at least one register is locked
        pub fn lockedRegsExist(self: Self) bool {
            return self.locked_registers.count() > 0;
        }

        /// Allocates a specified number of registers, optionally
        /// tracking them. Returns `null` if not enough registers are
        /// free.
        pub fn tryAllocRegs(
            self: *Self,
            comptime count: comptime_int,
            insts: [count]?Inst,
            register_class: RegisterBitSet,
        ) ?[count]Register {
            comptime assert(count > 0 and count <= tracked_registers.len);

            var free_and_not_locked_registers = self.free_registers;
            free_and_not_locked_registers.setIntersection(register_class);

            var unlocked_registers = self.locked_registers;
            unlocked_registers.toggleAll();

            free_and_not_locked_registers.setIntersection(unlocked_registers);

            if (free_and_not_locked_registers.count() < count) return null;

            var regs: [count]Register = undefined;
            var i: usize = 0;
            for (tracked_registers) |reg| {
                if (i >= count) break;
                if (excludeRegister(reg, register_class)) continue;
                if (self.isRegLocked(reg)) continue;
                if (!self.isRegFree(reg)) continue;

                regs[i] = reg;
                i += 1;
            }
            assert(i == count);

            for (regs, insts) |reg, inst| {
                log.debug("tryAllocReg {} for inst {?}", .{ reg, inst });
                self.markRegAllocated(reg);

                if (inst) |tracked_inst| {
                    // Track the register
                    const index = indexOfRegIntoTracked(reg).?; // indexOfReg() on a callee-preserved reg should never return null
                    self.registers[index] = tracked_inst;
                    self.markRegUsed(reg);
                }
            }

            return regs;
        }

        /// Allocates a register and optionally tracks it with a
        /// corresponding instruction. Returns `null` if all registers
        /// are allocated.
        pub fn tryAllocReg(self: *Self, inst: ?Inst, register_class: RegisterBitSet) ?Register {
            return if (tryAllocRegs(self, 1, .{inst}, register_class)) |regs| regs[0] else null;
        }

        /// Allocates a specified number of registers, optionally
        /// tracking them. Asserts that count is not
        /// larger than the total number of registers available.
        pub fn allocRegs(
            self: *Self,
            comptime count: comptime_int,
            insts: [count]?Inst,
            register_class: RegisterBitSet,
        ) AllocateRegistersError![count]Register {
            comptime assert(count > 0 and count <= tracked_registers.len);

            var locked_registers = self.locked_registers;
            locked_registers.setIntersection(register_class);

            if (count > register_class.count() - locked_registers.count()) return error.OutOfRegisters;

            const result = self.tryAllocRegs(count, insts, register_class) orelse blk: {
                // We'll take over the first count registers. Spill
                // the instructions that were previously there to a
                // stack allocations.
                var regs: [count]Register = undefined;
                var i: usize = 0;
                for (tracked_registers) |reg| {
                    if (i >= count) break;
                    if (excludeRegister(reg, register_class)) break;
                    if (self.isRegLocked(reg)) continue;

                    log.debug("allocReg {} for inst {?}", .{ reg, insts[i] });
                    regs[i] = reg;
                    self.markRegAllocated(reg);
                    const index = indexOfRegIntoTracked(reg).?; // indexOfReg() on a callee-preserved reg should never return null
                    if (insts[i]) |inst| {
                        // Track the register
                        if (self.isRegFree(reg)) {
                            self.markRegUsed(reg);
                        } else {
                            const spilled_inst = self.registers[index];
                            try self.getFunction().spillInstruction(reg, spilled_inst);
                        }
                        self.registers[index] = inst;
                    } else {
                        // Don't track the register
                        if (!self.isRegFree(reg)) {
                            const spilled_inst = self.registers[index];
                            try self.getFunction().spillInstruction(reg, spilled_inst);
                            self.freeReg(reg);
                        }
                    }

                    i += 1;
                }

                break :blk regs;
            };

            log.debug("allocated registers {any} for insts {any}", .{ result, insts });
            return result;
        }

        /// Allocates a register and optionally tracks it with a
        /// corresponding instruction.
        pub fn allocReg(
            self: *Self,
            inst: ?Inst,
            register_class: RegisterBitSet,
        ) AllocateRegistersError!Register {
            return (try self.allocRegs(1, .{inst}, register_class))[0];
        }

        /// Spills the register if it is currently allocated. If a
        /// corresponding instruction is passed, will also track this
        /// register.
        fn getRegIndex(
            self: *Self,
            tracked_index: TrackedIndex,
            inst: ?Inst,
        ) AllocateRegistersError!void {
            log.debug("getReg {} for inst {?}", .{ regAtTrackedIndex(tracked_index), inst });
            if (!self.isRegIndexFree(tracked_index)) {
                self.markRegIndexAllocated(tracked_index);

                // Move the instruction that was previously there to a
                // stack allocation.
                const spilled_inst = self.registers[tracked_index];
                if (inst) |tracked_inst| self.registers[tracked_index] = tracked_inst;
                try self.getFunction().spillInstruction(regAtTrackedIndex(tracked_index), spilled_inst);
                if (inst == null) self.freeRegIndex(tracked_index);
            } else self.getRegIndexAssumeFree(tracked_index, inst);
        }
        pub fn getReg(self: *Self, reg: Register, inst: ?Inst) AllocateRegistersError!void {
            return self.getRegIndex(indexOfRegIntoTracked(reg) orelse return, inst);
        }
        pub fn getKnownReg(
            self: *Self,
            comptime reg: Register,
            inst: ?Inst,
        ) AllocateRegistersError!void {
            return self.getRegIndex((comptime indexOfRegIntoTracked(reg)) orelse return, inst);
        }

        /// Allocates the specified register with the specified
        /// instruction. Asserts that the register is free and no
        /// spilling is necessary.
        fn getRegIndexAssumeFree(
            self: *Self,
            tracked_index: TrackedIndex,
            inst: ?Inst,
        ) void {
            log.debug("getRegAssumeFree {} for inst {?}", .{ regAtTrackedIndex(tracked_index), inst });
            self.markRegIndexAllocated(tracked_index);

            assert(self.isRegIndexFree(tracked_index));
            if (inst) |tracked_inst| {
                self.registers[tracked_index] = tracked_inst;
                self.markRegIndexUsed(tracked_index);
            }
        }
        pub fn getRegAssumeFree(self: *Self, reg: Register, inst: ?Inst) void {
            self.getRegIndexAssumeFree(indexOfRegIntoTracked(reg) orelse return, inst);
        }

        /// Marks the specified register as free
        fn freeRegIndex(self: *Self, tracked_index: TrackedIndex) void {
            log.debug("freeing register {}", .{regAtTrackedIndex(tracked_index)});
            self.registers[tracked_index] = undefined;
            self.markRegIndexFree(tracked_index);
        }
        pub fn freeReg(self: *Self, reg: Register) void {
            self.freeRegIndex(indexOfRegIntoTracked(reg) orelse return);
        }
    };
}
