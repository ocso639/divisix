ENTRY(start)

SECTIONS {
    . = 1M;
    _kernel_physical_start = .;

    .boot :
    {
        *(.multiboot_header)
    }

    . = ALIGN(0x1000);
    _boot_end = .;

    . += 0xFFFFFFFF80000000;
    _kernel_virtual_start = .;
    .text : AT(_boot_end)
    {
        *(.multiboot)
        *(.text)
    }
} 