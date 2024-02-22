all:
	nasm -f bin boot.asm -o boot.bin
	cat boot.bin > boot.img
	truncate -s 1440K boot.img
	qemu-system-i386 -hda boot.img