section .text

global load_gdt

load_gdt:
    mov eax, ebp
    lgdt [eax]
    ret
