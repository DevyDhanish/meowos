read_disk:
    pusha
    mov bx, [KERNEL_LOCATION]
    mov ah, 2
    mov al, 20      ; read 20 sectors
    mov ch, 0       ; cylinder 0
    mov dh, 0       ; head 0
    mov cl, 2       ; start from sector 2
    mov dl, [boot_drive]
    int 0x13
    jc disk_error

    ; cmp ah, 0
    ; je disk_ok

    popa
    ret

disk_error:
    mov si, ERROR
    call printstr
    jmp $

disk_ok:
    pusha
    mov si, OK
    call printstr
    popa
    ret

KERNEL_LOCATION equ 0x10000
boot_drive db 0x0
OK    db "Kernel code loaded at location [0x10000]", 13, 10, 0
ERROR db "Error reading disk", 13, 10, 0
