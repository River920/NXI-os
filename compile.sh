clear

nasm -f bin bootloader.asm -o bootloader.bin

i386-elf-g++ -ffreestanding -c "kernel.cpp" -o "kernel.o"

nasm "kernel_entry.asm" -f elf -o "kernel_entry.o"

nasm "zeroes.asm" -f bin -o "zeroes.bin"

i386-elf-ld -m elf_i386 -s -Ttext 0x1000 --oformat binary -o "full_kernel.bin" "kernel_entry.o" "kernel.o"

nasm "bootloader.asm" -f bin -o "bootloader.bin"

cat "bootloader.bin" "full_kernel.bin" > "everything.bin"

cat "everything.bin" "zeroes.bin" > "OS.bin"

qemu-system-x86_64 -drive format=raw,file="OS.bin",index=0,if=floppy,  -m 128M