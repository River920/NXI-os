clear

nasm -f bin bootloader.asm -o bootloader.bin

gcc -ffreestanding -m32 -g -c "kernel.cpp" -o "kernel.o"

nasm "kernel_entry.asm" -f elf -o "kernel_entry.o"

nasm "zeroes.asm" -f bin -o "zeroes.bin"

ld -e main -m elf_i386 -s -o "full_kernel.bin" -Ttext 0x1000 "kernel_entry.o" "kernel.o"

nasm "bootloader.asm" -f bin -o "bootloader.bin"

cat "bootloader.bin" "full_kernel.bin" > "everything.bin"

cat "everything.bin" "zeroes.bin" > "OS.bin"

qemu-system-x86_64 -drive format=raw,file="OS.bin",index=0,if=floppy,  -m 128M