.section .text // Define the code section
.global _start // Entry point

_start:
    // Check if we're on the main core
    mrs x0, mpidr_el1 // Read MPIDR register
    and x0, x0, #3    // Mask off affinity bits
                      // cbnz = branch if not zero (x0 != 0 ? goto freeze : else continue)
    cbnz x0, freeze   // If affinity is zero, branch to 2f
    
    ldr x1, =_start   // Set stack to start below our code
    mov sp, x1        // move address of stack to stack pointer register
    bl kernel_init    // branch with link to kernel_init method on kernel.c
    b freeze          // Should not reach here

freeze:         // We're not on the main core, so freeze
    wfe         // Wait for event
    b freeze    // Infinite loop
    