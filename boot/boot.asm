org 0x7c00
bits 16

KERNEL_OFFSET equ 0x1000

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

; load sector and kernel
mov bx, KERNEL_OFFSET
mov ah, 2
mov al, 40              ; loading 15 sectors
mov ch, 0
mov dh, 0
mov cl, 2
mov dl, [boot_drive]
int 0x13

call CheckA20       ; check if a20 is enabled, if not, enable it
call CheckA20       ; if the above instruction enabled the a20 gate, check again to see if a20 is enabled
; if you see output
; EE    - enabled by default, no need to enable it again
; DE    - disabled by default, so it was enabled by CheckA20 function
; DD    - disabled by default, and CheckA20 was not able to enable it. 

;moving to PM
cli
lgdt [gdt_desc]
mov eax, cr0
or eax, 1
mov cr0, eax

jmp code_seg:_main32

jmp $

; ---------------------------

%include "boot/a20.asm"
%include "boot/print.asm"
%include "boot/gdt.asm"

bits 32
_main32:
    mov ax, data_seg
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000
    mov esp, ebp

    call KERNEL_OFFSET

    jmp $

init_msg db "Stack initialized at - [0x7c00]", 13, 10, 0
info  db "Attempting to read kernel from the disk", 13, 10, 0
mode_info db "Switched to protected mode" 13,10,0
boot_drive db 0

times 510-($-$$) db 0

db 0x55
db 0xaa