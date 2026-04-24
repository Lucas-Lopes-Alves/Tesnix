PLACE?=isos/teste.iso
ISO?=teste
DESTINY?=isos

.PHONY: debug

build: kernel.c boot.s
	i686-elf-gcc -ffreestanding -nostdlib -c src/*.c -o bin/*.o
	i686-elf-as boot.s -o bin/boot.o
	i686-elf-gcc -T kernel.ld -ffreestanding -nostdlib -O2 bin/*.o bin/boot.o -o iso/boot/kernel.elf -lgcc
	grub-mkrescue iso -o $(DESTINY)/$(ISO).iso

debug: kernel.c boot.s
	i686-elf-gcc -ffreestanding -nostdlib -c src/*.c -g -o bin/*.o
	i686-elf-as boot.s -o bin/Dboot.o
	i686-elf-gcc -T kernel.ld bin/D*.o -o debug/iso/boot/Dkernel.elf -ffreestanding -nostdlib -lgcc
	grub-mkrescue debug/iso -o isos/debug.iso

emulate:
	qemu-system-i386 -cdrom $(PLACE)