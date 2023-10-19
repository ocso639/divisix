ENTRY(start)

SECTIONS {
    .boot :
    {
        *(.multiboot_header)
    }
    .text :
    {
        *(.multiboot)
        *(.text)
    }
} 