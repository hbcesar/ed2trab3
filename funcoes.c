#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estaOrdenado(int* entrada, int n){
	int i;

	for(i=0; i<n-1; i++){
		if(entrada[i] > entrada[i+1])
			return 0;
	}

	return 1;
}