.global _start  // entry point
.text           // code section

_start:
    ldr x30, =stack_top    
    mov sp, x30     
    bl kmain
    b .