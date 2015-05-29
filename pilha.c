#include <stdio.h>
#include <stdlib.h>
#include "TADPilha.h"


Pilha* inicializaPilha(int n){
	Pilha* novo = (Pilha*) malloc(sizeof(Pilha));

	novo->max = n;
	novo->topo = 0;
	novo->buffer = (int*) malloc(n*sizeof(int));

	return novo;
}

int vazia(Pilha* pilha){
	int t = pilha->topo;

	if(t > 0)
		return 0;
	else 
		return 1;
}

void empilha(Pilha* pilha, int elemento){
	int t = pilha->topo;

	if(t++ < pilha->max){
		pilha->buffer[t] = elemento;
		pilha->topo = t;
	} else {
		printf("Tamanho máximo de pilha atingido.\n");
	}
}

int desempilha(Pilha* pilha){
	int elemento, t;

	if(!vazia(pilha)){
		t = pilha->topo;
		elemento = pilha->buffer[t--];
		pilha->topo = t;
		return elemento;
	} 

	return 0;
}