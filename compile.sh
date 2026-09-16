clear

# Compile the bootloader
nasm -f bin -I src/bootloader/ src/bootloader/bootloader.asm -o output/bootloader/bootloader.bin

# Compile the kernel
i386-elf-gcc -ffreestanding -c "src/kernel/kernel.c" -o "output/kernel/kernel.o"

# Compile the kernel_entry
nasm "src/kernel/kernel_entry.asm" -f elf -o "output/kernel/kernel_entry.o"

# Compile the zeroes
nasm "src/kernel/zeroes.asm" -f bin -o "output/kernel/zeroes.bin"

# Combine the 2 kernel parts into 1
i386-elf-ld -m elf_i386 -s -Ttext 0x1000 --oformat binary -o "output/kernel/full_kernel.bin" "output/kernel/kernel_entry.o" "output/kernel/kernel.o"

# Concatenate bootloader, zeroes and kernel into the os
cat "output/bootloader/bootloader.bin" "output/kernel/full_kernel.bin" "output/kernel/zeroes.bin" > "output/os/os.bin"

# Emulate the os
qemu-system-x86_64 -drive format=raw,file="output/os/os.bin",index=0,if=floppy,  -m 128M