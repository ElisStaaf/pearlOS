// kernel.c
#define DISPLAY_THEME  WHITE_ON_BLUE
#define KERNEL_STARTUP ksh_start();
#define KERNEL_UPDATE

// mem.h
#define KERNEL_MEMORY_OFFSET_START 0xffffff
#define KERNEL_MEMORY_OFFSET_END   0xffffffff
#define MEMORY_INDEX_BASE_SIZE     10000
