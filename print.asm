printstr
    pusha
    mov ah, 0x0e
    mov al, [si]
    p_loop:
        int 0x10
        inc si
        mov al, [si]
        cmp al, 0
        jne p_loop
    popa
    ret