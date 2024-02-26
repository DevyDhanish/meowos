section .text

global load_idt
    mov eax, [eax + 4]
    lidt [eax]
    ret