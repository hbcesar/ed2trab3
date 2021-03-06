#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADAlgoritmosOrdenacao.h"
#include "TADFuncoes.h"

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
		ordenado = shakeSort(entrada, n);

	} else if(strcmp(argv[1], "insertion") == 0){
		ordenado = insertionSort(entrada, n);

	} else if(strcmp(argv[1], "shell") == 0){
		ordenado = shellSort(entrada, n);

	} else if(strcmp(argv[1], "selection") == 0){
		ordenado = selectionSort(entrada, n);

	} else if(strcmp(argv[1], "rank") == 0){
		ordenado = raknSort(entrada, n);

	} else if(strcmp(argv[1], "quickrecursivoprimeiro") == 0){
		ordenado = quickSortRecursivoPrimeiro(entrada, 0, n-1);

	} else if(strcmp(argv[1], "quickrecursivocentral") == 0){
		ordenado = quickSortRecursivoCentral(entrada, 0, n-1);

	} else if(strcmp(argv[1], "quickrecursivomediana3") == 0){
		ordenado = quickRecursivoMediana3(entrada, 0, n-1);

	} else if(strcmp(argv[1], "quickprimeiro") == 0){
		ordenado = quickSortPrimeiro(entrada, n);

	} else if(strcmp(argv[1], "quickcentral") == 0){
		ordenado = quickSortCentral(entrada, n);

	} else if(strcmp(argv[1], "quickmediana3") == 0){
		ordenado = quickSortMediana(entrada, n);

	} else if(strcmp(argv[1], "merge") == 0){
		ordenado =  mergeSort(entrada, n);

	} else if(strcmp(argv[1], "heap") == 0){
		ordenado =  heapSort(entrada, n);

	} else if(strcmp(argv[1], "radix") == 0){
		ordenado = radixSort(entrada, n);

	} else if(strcmp(argv[1], "radixbin") == 0){

	} else if(strcmp(argv[1], "bucket") == 0){
		ordenado = bucketSort(entrada, n);

	} else {
		printf("Algoritmo especificado não é válido\n");
	}

	imprimir(ordenado, n);

	return 0;

}