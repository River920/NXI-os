section .text
    [bits 32]
    [extern _start]
    movzx %edi, byte [0x0500]
    call _start
    jmp $