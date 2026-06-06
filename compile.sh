clear

nasm -f bin -I src/bootloader/ src/bootloader/bootloader.asm -o output/bootloader/bootloader.bin

i386-elf-gcc -ffreestanding -c "src/kernel/kernel.c" -o "output/kernel/kernel.o"

nasm "src/kernel/kernel_entry.asm" -f elf -o "output/kernel/kernel_entry.o"

nasm "src/kernel/zeroes.asm" -f bin -o "output/kernel/zeroes.bin"

i386-elf-ld -m elf_i386 -s -Ttext 0x1000 --oformat binary -o "output/kernel/full_kernel.bin" "output/kernel/kernel_entry.o" "output/kernel/kernel.o"

cat "output/bootloader/bootloader.bin" "output/kernel/full_kernel.bin" "output/kernel/zeroes.bin" > "output/os/os.bin"

qemu-system-x86_64 -drive format=raw,file="output/os/os.bin",index=0,if=floppy,  -m 128M