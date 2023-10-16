%define port 3f8h

extern init_serial
extern outs

init_serial:
    mov dx, port + 1
    mov al, 0x00
    out dx, al

    mov dx, port + 3
    mov al, 0x80
    out dx, al
    
    mov dx, port
    mov al, 0x03
    out dx, al

    mov dx, port + 1
    mov al, 0x00
    out dx, al

    mov dx, port + 3 
    mov al, 0x03
    out dx, al

    mov dx, port + 2
    mov al, 0xC7
    out dx, al
    
    mov dx, port + 4
    mov al, 0x0B
    out dx, al

    mov dx, port + 4
    mov al, 0x1E
    out dx, al

    mov dx, port
    mov al, 0xAE
    out dx, al

    mov dx, port + 4
    mov al, 0x0F
    out dx, al
    ret

outs:
    mov rdx, rdi
    mov rax, rsi
    out dx, al 
    ret 