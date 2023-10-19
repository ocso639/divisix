[bits 32]
global start 
extern _kentry

start:
    mov eax, p3_table
    or eax, 0b11 ;
    mov dword [p4_table + 0], eax

    mov eax, p2_table
    or eax, 0b11
    mov dword [p3_table + 0], eax

    mov ecx, 0
    
.map_p2_table:
    mov eax, 0x40000
    mul ecx
    or eax, 0b10000011
    mov [p2_table + ecx * 8], eax
    inc ecx
    cmp ecx, 512
    jne .map_p2_table

    mov eax, p4_table
    mov cr3, eax

    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    mov ecx, 0xC0000080
    rdmsr
    or eax, 1 << 8
    wrmsr

    mov eax, cr0
    or eax, 1 << 31
    or eax, 1 << 16
    mov cr0, eax

    lgdt [gdt64.pointer]

    mov ax, gdt64.data
    mov ss, ax
    mov ds, ax
    mov es, ax  

    jmp gdt64.code:long_mode_start
section .bss
    
align 4096

p4_table:
    resb 4096
p3_table:
    resb 4096
p2_table:
    resb 4096

section .rodata
gdt64:
    dq 0
.code: equ $ - gdt64
    dq 0x00af9a000000ffff
.data: equ $ - gdt64
    dq 0x00cf92000000ffff
.pointer:
    dw .pointer - gdt64 - 1
    dq gdt64

section .text
[bits 64]
long_mode_start:
    call _kentry