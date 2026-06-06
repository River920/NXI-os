[org 0x7c00]                        
KERNEL_LOCATION equ 0x1000


mov [BOOT_DISK], dl                 

%include "disk.asm"
                                    
BOOT_DISK: db 0

%include "gdt.asm"

%include "pm.asm"

                                     
 
times 510-($-$$) db 0              
dw 0xaa55