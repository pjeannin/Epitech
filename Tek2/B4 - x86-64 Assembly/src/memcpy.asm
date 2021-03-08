; memcpy
bits 64
global memcpy:function
section .text

memcpy:
        XOR     RCX, RCX
        MOV     RAX, RDI

.loop:
        CMP     RCX, RDI
        JE      .exit
        MOV     R8B, BYTE [RSI + RCX]
        MOV     BYTE [RAX + RCX], R8B
        INC     RCX
        JMP     .loop

.exit:
        RET