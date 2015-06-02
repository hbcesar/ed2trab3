#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int x = 3;
	int mascara = 000000000000000000000000000000000000000000000000000000000000001;

	int bit;

	bit = x & mascara;

	printf("Bit %d\n", bit);
	x = x >> 1;
	bit = x & mascara;	
	printf("Bit %d\n", bit);
	x = x >> 1;
	bit = x & mascara;	
	printf("Bit %d\n", bit);

}