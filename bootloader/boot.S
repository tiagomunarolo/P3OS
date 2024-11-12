.global _start              // Setup entry point

_start:
    ldr x30, =stack_top     // x30 => Link register (return address for function calls)
    mov sp, x30             // move address of stack to stack pointer register
    bl kernel_init          // branch with link to kernel_init method on kernel.c
    b _infinite_loop        // infinite loop (after return from initialization)

_infinite_loop:
    b .                     // Freezes cpu