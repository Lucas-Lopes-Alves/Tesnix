PLACE?=isos/teste.iso
CC=i686-elf-gcc
AS = i686-elf-as
CFLAGS= -ffreestanding -nostdlib -Iinclude
LDFLAGS= -ffreestanding -nostdlib -lgcc

# Saves all the files ending with .c to
# change them from .c to .o
SRCS_C := $(wildcard src/*.c)
SRCS_S := $(wildcard src/*.s)
OBJS := $(patsubst src/%.c, bin/%.o, $(SRCS_C))
OBJS += $(patsubst src/%.s, bin/%.o, $(SRCS_S))

all: build

build: $(OBJS)
	@echo "Linking the object files"
	@$(CC) $(LDFLAGS) -T kernel.ld $(OBJS) -o iso/boot/kernel.elf
	@echo "Creating the iso at $(PLACE)"
	@grub-mkrescue iso -o $(PLACE) > /dev/null 2>&1

# Tells make how to create the C and Assembly 
# object files and where to place them
bin/%.o: src/%.c
	@echo "Compiling the C files"
	@$(CC) $(CFLAGS) -c $< -o $@

bin/%.o: src/*.s
	@echo "Compiling the Assembly files"
	@$(AS) $< -o $@

emulate:
	qemu-system-i386 -cdrom $(PLACE)