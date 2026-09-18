# NXI-os 
<img width="200" height="200" alt="NXI_Logo" src="https://github.com/user-attachments/assets/676c86a4-3584-4246-8b67-7dab2f36446a" />

an os im tryna make.

tutorial is used(because theres no way i did it my self lol): https://www.youtube.com/watch?v=MwPjvJ9ulSc&list=PLm3B56ql_akNcvH8vvJRYOc7TbYhRs19M


# Required software to build

- nasm - Compile assembly files
- i386-elf-gcc - Compile C files
- i386-elf-ld - Link .o files
- qemu-system-x86 - Emulate the os

Installation guide for Debian/Ubuntu type linux only  
**nasm**
```nasm
sudo apt install nasm
```
**i386-elf-ld**
```i386-elf-ld
sudo apt update
sudo apt install build-essential bison flex texinfo libgmp3-dev libmpc-dev libmpfr-dev

export PREFIX="$HOME/opt/cross"
export TARGET=i386-elf
export PATH="$PREFIX/bin:$PATH"

mkdir -p ~/src && cd ~/src
wget https://ftp.gnu.org/gnu/binutils/binutils-2.42.tar.gz
tar -xf binutils-2.42.tar.gz

mkdir build-binutils && cd build-binutils
../binutils-2.42/configure --target=$TARGET --prefix="$PREFIX" \
    --with-sysroot --disable-nls --disable-werror
make -j$(nproc)
make install

echo 'export PATH="$HOME/opt/cross/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc
i386-elf-ld --version
```
**i386-elf-gcc**
```i386-elf-gcc
cd ~/src
wget https://ftp.gnu.org/gnu/gcc/gcc-13.2.0/gcc-13.2.0.tar.gz
tar -xf gcc-13.2.0.tar.gz

mkdir build-gcc && cd build-gcc
../gcc-13.2.0/configure --target=$TARGET --prefix="$PREFIX" \
    --disable-nls --enable-languages=c,c++ --without-headers

make -j$(nproc) all-gcc
make -j$(nproc) all-target-libgcc
make install-gcc
make install-target-libgcc

i386-elf-gcc --version
```
**qemu-system-x86**
```qemu-system-x86
sudo apt install qemu-system-x86
```

# Credits and resources

**itoa function**
 - https://www.strudel.org.uk/itoa/

**osdev**
 - https://wiki.osdev.org/Expanded_Main_Page
 - https://f.osdev.org/

