CheckA20:
    pusha
    push ds
    push es
    push di 
    push si 

    cli 

    xor ax, ax
    mov es, ax
    mov di, 0x0500

    mov ax, 0xffff
    mov ds, ax
    mov si, 0x0510

    mov al, byte es:[di]
    push ax

    mov al, byte ds:[si]
    push ax

    mov byte es:[di], 0x00
    mov byte ds:[si], 0xff

    cmp byte es:[di], 0xff
    jne gate_enabled

    mov ah, 0x0e
    mov al, 'D'
    int 0x10

    pop ax
    mov byte ds:[si], al

    pop ax
    mov byte es:[di], al

    in al, 0x92
    or al, 2
    out 0x92, al

    jmp CheckA20_exit

gate_enabled:
    mov ah, 0x0e
    mov al, 'E'
    int 0x10

    pop ax
    mov byte ds:[si], al

    pop ax
    mov byte es:[di], al

    jmp CheckA20_exit

CheckA20_exit:
    pop si
    pop di 
    pop es 
    pop ds 
    popa
    ret

DISABLED: db "A20 gate is disabled enabling it right now"
ENABLED:  db "A20 gate is already enabled skipping"