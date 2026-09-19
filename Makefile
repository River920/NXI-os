.PHONY: all build run clean mkdir

all: build run

build: mkdir
	# Compile the bootloader
	nasm -f bin -I src/bootloader/ src/bootloader/bootloader.asm -o output/bootloader/bootloader.bin
	# Compile the kernel_entry
	nasm "src/kernel/kernel_entry.asm" -f elf -o "output/kernel/kernel_entry.o"
	# Compile the zeroes
	nasm "src/kernel/zeroes.asm" -f bin -o "output/kernel/zeroes.bin"
	# Compile the kernel
	i386-elf-gcc -ffreestanding -c "src/kernel/kernel.c" -o "output/kernel/kernel.o"
	# Combine the 2 kernel parts into 1
	i386-elf-ld -m elf_i386 -s -Ttext 0x1000 --oformat binary -o "output/kernel/full_kernel.bin" "output/kernel/kernel_entry.o" "output/kernel/kernel.o"
	# Concatenate bootloader, zeroes and kernel into the os
	cat "output/bootloader/bootloader.bin" "output/kernel/full_kernel.bin" "output/kernel/zeroes.bin" > "output/os/os.bin"

run: output/os/os.bin
	# Emulate the os
	qemu-system-x86_64 -drive format=raw,file="output/os/os.bin",index=0,if=floppy, -m 128M

clean:
	# Clean out unnecessary files
	rm -f output/bootloader/bootloader.bin
	rm -f output/kernel/full_kernel.bin
	rm -f output/kernel/kernel_entry.o
	rm -f output/kernel/kernel.o
	rm -f output/kernel/zeroes.bin
	rm -f output/os/os.bin
	clear

mkdir:
	# Make output directories
	mkdir -p output/bootloader output/kernel output/os
