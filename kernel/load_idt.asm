section .text

global load_idt

load_idt:
    mov eax, ebp
    lidt [eax]
    sti
    ret