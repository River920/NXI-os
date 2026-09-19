section .text
    [bits 32]
    [extern _start]
    movzx eax, byte [0x0500]
    push eax
    call _start
    jmp $