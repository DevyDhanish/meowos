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

mov si, OK
call printstr

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

%include "a20.asm"
%include "disk.asm"
%include "print.asm"
%include "gdt.asm"

bits 32
_main32:
    mov ax, data_seg
    mov ds, ax
    mov ss, ax

    mov ebp, 0x9000
    mov esp, ebp

    mov al, 'A'
    mov ah, 0x0f
    mov [0xb8000], ax

    jmp $

init_msg db "Stack initialized at - [0x7c00]", 13, 10, 0
info  db "Attempting to read kernel from the disk", 13, 10, 0
mode_info db "Switched to protected mode" 13,10,0

times 510-($-$$) db 0

db 0x55
db 0xaa