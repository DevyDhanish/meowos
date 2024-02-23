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
	$(LD) -o $(BUILD)/kernel.bin -Ttext 0x1000 $(BUILD)/ke.o $(BUILD)/stdio.o $(BUILD)/vga.o $(BUILD)/kernel.o --oformat binary

	cat $(BUILD)/boot.bin $(BUILD)/kernel.bin > $(BUILD)/boot.img
	truncate -s 1440K $(BUILD)/boot.img
	qemu-system-i386 -hda $(BUILD)/boot.img -m 512