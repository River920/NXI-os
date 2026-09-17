[org 0x7c00]                        
KERNEL_LOCATION equ 0x1000

; Clear carry flag
clc
; Switch to the BIOS (= request low memory size)
int 0x12

; AX = amount of continuous memory in KB starting from 0.
mov [BOOT_MEM_AMOUNT], ax

mov [BOOT_DISK], dl                 

%include "disk.asm"

BOOT_MEM_AMOUNT: dw 0                     
BOOT_DISK: db 0

%include "gdt.asm"

%include "pm.asm"

                                     
 
times 510-($-$$) db 0              
dw 0xaa55