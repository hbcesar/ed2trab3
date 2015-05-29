#ifndef TADPILHA_H_
#define TADPILHA_H_

typedef struct pilha{
	int topo, max;
	int* buffer;
} Pilha;


Pilha* inicializaPilha(int n);
int vazia(Pilha* pilha);
void empilha(Pilha* pilha, int elemento);
int desempilha(Pilha* pilha);

#endif