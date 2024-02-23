read_disk:
    pusha
    mov bx, [KERNEL_OFFSET]
    mov ah, 2
    mov al, 20      ; read 20 sectors
    mov ch, 0       ; cylinder 0
    mov dh, 0       ; head 0
    mov cl, 2       ; start from sector 2
    mov dl, [boot_drive]
    int 0x13
    popa
    ret
