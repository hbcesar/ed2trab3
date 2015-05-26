#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADAlgoritmosOrdenacao.h"
#include "TADFuncoes.h"

void lerEntrada(int* entrada, int n){
	int i;

	for(i=0; i<n; i++){
		scanf("%d", entrada+i);
	}
}

int main(int argc, char* argv []){
	int n;
	int* entrada = NULL;
	int* ordenado = NULL;

	n = atoi(argv[2]);

	entrada = (int*)malloc(n*sizeof(int));


	lerEntrada(entrada, n);

	if(strcmp(argv[1], "perm") == 0){
		ordenado = permutacao(entrada, n);
	} else if(strcmp(argv[1], "bubble") == 0){
		ordenado = bubbleSort(entrada, n);
	} else if(strcmp(argv[1], "shake") == 0){
		ordenado = shakeSort(entrada, n); //DEFEITO
	} else if(strcmp(argv[1], "insertion") == 0){
		ordenado = insertionSort(entrada, n);
	} else if(strcmp(argv[1], "shell") == 0){
		ordenado = shellSort(entrada, n);
	} else if(strcmp(argv[1], "selection") == 0){
		ordenado = selectionSort(entrada, n);
	} else if(strcmp(argv[1], "rank") == 0){

	} else if(strcmp(argv[1], "quickrecursivoprimeiro") == 0){

	} else if(strcmp(argv[1], "quickrecursivocentral") == 0){

	} else if(strcmp(argv[1], "quickrecursivomediana3") == 0){

	} else if(strcmp(argv[1], "quickprimeiro") == 0){

	} else if(strcmp(argv[1], "quickcentral") == 0){

	} else if(strcmp(argv[1], "quickmediana3") == 0){

	} else if(strcmp(argv[1], "merge") == 0){

	} else if(strcmp(argv[1], "heap") == 0){

	} else if(strcmp(argv[1], "radix") == 0){

	} else if(strcmp(argv[1], "radixbin") == 0){

	} else if(strcmp(argv[1], "bucket") == 0){

	} else {
		printf("Algoritmo especificado não é válido\n");
	}

	imprimir(ordenado, n);

	return 0;

}