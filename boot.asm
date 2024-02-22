org 0x7c00
bits 16

; all code between these lines

; set all the seg registers to 0, and set the sp to 0x7c00
cli
mov bp, 0x7c00
mov sp, bp
sti

; clear the screen
mov ah, 0x00
mov al, 0x03
int 0x10

mov [boot_drive], dl

mov si, init_msg
call printstr

mov si, info
call printstr

call read_disk

jmp KERNEL_LOCATION:next_segment

; ---------------------------

jmp $

%include "disk.asm"
%include "print.asm"

init_msg db "Cleared segmentation registers, stack was initialized", 13, 10, 0
info  db "attempting to read kernel from the disk", 13, 10, 0

times 510-($-$$) db 0

db 0x55
db 0xaa

next_segment:
mov ah, 0x0e
mov al, 'A'
int 0x10