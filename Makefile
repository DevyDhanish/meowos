all:
	nasm -f bin boot.asm -o boot.bin
	cat boot.bin > boot.img
	truncate -s 1440K boot.img
	qemu-system-x86_64 -hda boot.img -m 512