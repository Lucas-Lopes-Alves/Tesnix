build32:
	x86_64-elf-gcc -m32 -ffreestanding -nostdlib -c kernel.c -o bin/kernel.o
	x86_64-elf-ld -m elf_i386 -T kernel.ld bin/kernel.o -o iso/boot/kernel.bin
	grub-mkrescue iso -o isos/teste.iso