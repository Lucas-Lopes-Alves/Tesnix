CAMINHO?=isos/teste.iso
ISO?=teste

build32:
	i686-elf-gcc -ffreestanding -nostdlib -c kernel.c -o bin/kernel.o
	i686-elf-ld -T kernel.ld bin/kernel.o -o iso/boot/kernel.elf
	grub-mkrescue iso -o isos/$(ISO).iso

emulate:
	qemu-system-x86_64 -cdrom $(CAMINHO)

buildwsl:
	i686-elf-gcc.exe -ffreestanding -nostdlib -c kernel.c -o bin/kernel.o
	i686-elf-ld.exe -T kernel.ld bin/kernel.o -o iso/boot/kernel.elf
	grub-mkrescue iso -o isos/$(ISO).iso