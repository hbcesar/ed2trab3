#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerEntrada(int* entrada, int n){
	int i;

	for(i=0; i<n; i++){
		scanf("%d", entrada+i);
	}
}

int estaOrdenado(int* entrada, int n){
	int i;

	for(i=0; i<n-1; i++){
		if(entrada[i] > entrada[i+1])
			return 0;
	}

	return 1;
}

void imprimir(int* entrada, int n){
	int i;

	for(i=0; i<n; i++){
		printf("%d\n", entrada[i]);
	}
}

void zerar(int* entrada, int n){
	int i;

	for(i=0; i<n; i++){
		entrada[i] = 0;
	}
}
