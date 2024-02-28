CC := x86_compiler/bin/i686-elf-gcc
LD := x86_compiler/bin/i686-elf-ld

BOOT := boot
BUILD := build
KERNEL := kernel

all:
	nasm -f bin $(BOOT)/boot.asm -o $(BUILD)/boot.bin
	nasm -f elf32 $(BOOT)/kernel_entry.asm -o $(BUILD)/ke.o


	$(CC) -ffreestanding -c $(KERNEL)/main.c -o $(BUILD)/kernel.o
	$(CC) -c $(KERNEL)/vga/vga.c -o $(BUILD)/vga.o
	$(CC) -c $(KERNEL)/stdio.c -o $(BUILD)/stdio.o
	$(CC) -c $(KERNEL)/utils.c -o $(BUILD)/utils.o
	nasm -f elf32 $(KERNEL)/load_gdt.asm -o $(BUILD)/lg.o
	nasm -f elf32 $(KERNEL)/load_idt.asm -o $(BUILD)/li.o
	nasm -f elf32 $(KERNEL)/interrupts.asm -o $(BUILD)/int.o
	$(CC) -c $(KERNEL)/idt.c -o $(BUILD)/idt.o
	$(CC) -c $(KERNEL)/gdt.c -o $(BUILD)/gdt.o
	$(CC) -c $(KERNEL)/handler.c -o $(BUILD)/handler.o
	$(LD) -o $(BUILD)/kernel.bin -Ttext 0x1000 $(BUILD)/ke.o $(BUILD)/stdio.o $(BUILD)/lg.o $(BUILD)/gdt.o $(BUILD)/int.o $(BUILD)/handler.o $(BUILD)/li.o $(BUILD)/idt.o $(BUILD)/utils.o $(BUILD)/vga.o $(BUILD)/kernel.o --oformat binary

	cat $(BUILD)/boot.bin $(BUILD)/kernel.bin > $(BUILD)/boot.img
	truncate -s 1440K $(BUILD)/boot.img
	qemu-system-i386 -hda $(BUILD)/boot.img -m 1G