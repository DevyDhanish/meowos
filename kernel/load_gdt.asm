section .text

global load_gdt

load_gdt:
    mov eax, [eax + 4]

    lgdt [eax]

    ret
