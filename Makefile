x86_64_bootloader_asm_source_files := $(shell find src/bootloader -name *.asm)
x86_64_bootloader_asm_object_files := $(patsubst src/bootloader/%.asm, output/bootloader/%.o, $(x86_64_bootloader_asm_source_files))

$(x86_64_bootloader_asm_object_files): output/bootloader/%.o : src/bootloader/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst output/bootloader/%.o, src/bootloader/%.asm, $@) -o $@

.PHONY build-x86_64: $(x86_64_bootloader_asm_object_files)
	mkdir -p dist/x86_64 && .
	x86_64-elf-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(x86_64_bootloader_asm_object_files) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue -o dist/x86_64/kernel.iso targets/x86_64/iso
