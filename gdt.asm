gdt_start:
gdt_null:
    dd 0x00
    dd 0x00
gdt_code:
    dw 0xffff       ; limit 1
    dw 0            ; base 1
    db 0            ; base 2
    db 10011010b    ; access bits
    db 11001111b    ; flags and limit 2
    db 0            ; base 3
gdt_data:
    dw 0xffff
    dw 0
    db 0
    db 10010010b
    db 11001111b    
    db 0
gdt_end:

gdt_desc:
    dw gdt_end - gdt_start - 1
    dd gdt_start

code_seg equ gdt_code - gdt_start
data_seg equ gdt_data - gdt_start