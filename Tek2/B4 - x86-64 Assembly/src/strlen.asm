; strlen
bits 64
global strlen:function
section .text

strlen:
        XOR     RAX, RAX
        CMP     BYTE[RDI], 0x00
        JZ      .exit

.loop:
        INC     RAX
        INC     RDI
        CMP     BYTE[RDI], 0x00
        JZ      .exit
        JMP     .loop

.exit:
        RET