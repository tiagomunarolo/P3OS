.global _start              // Setup entry point

_start:
    // mrs: Move Register from System register
    mrs	x0, mpidr_el1       // Reads from mpidr_el1 register: provide information on processor affinity, which is critical for determining which physical core the current CPU is executing on in a multi-core system
_store_lr_address:    
    // x30 => Link register (return address for function calls)
    ldr x30, =stack_top     
    mov sp, x30             // move address of stack to stack pointer register
    bl kernel_init          // branch with link to kernel_init method on kernel.c
    b _infinite_loop        // infinite loop (after return from initialization)

_infinite_loop:
    b .                     // Freezes cpu
