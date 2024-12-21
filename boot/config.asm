KERNEL_SIZE   db  33
STACK_OFFSET  db  9000
KERNEL_OFFSET equ 0x1000

MSG_REAL_MODE    db "Started in 16-bit Real Mode",     0
MSG_PROT_MODE    db "Landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL  db "Loading kernel into memory...",   0
MSG_CRASH_KERNEL db "[KERNEL PANIC] Nothing to do!!!", 0
