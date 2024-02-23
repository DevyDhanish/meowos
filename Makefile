CC := x86_compiler/bin/i686-elf-gcc
LD := x86_compiler/bin/i686-elf-ld


all:
	nasm -f bin boot.asm -o boot.bin
	nasm -f elf32 kernel_entry.asm -o ke.o

	$(CC) -ffreestanding -c main.c -o kernel.o
	$(LD) -o kernel.bin -Ttext 0x1000 ke.o kernel.o --oformat binary

	cat boot.bin kernel.bin > boot.img
	truncate -s 1440K boot.img
	qemu-system-i386 -hda boot.img -m 512