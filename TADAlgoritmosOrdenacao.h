#ifndef TADALGORITMOSORDENACAO_H_
#define TADALGORITMOSORDENACAO_H_

int* permutacao(int* entrada, int n);
int* bubbleSort(int* entrada, int n);
int* shakeSort(int* entrada, int n);
int* insertionSort(int* entrada, int n);
int* shellSort(int *entrada, int n);
int* selectionSort(int* entrada, int n);
int* raknSort(int* entrada, int n);
int* quickSortRecursivoPrimeiro(int *entrada, int esquerda, int direita);
int* quickSortRecursivoCentral(int *entrada, int esquerda, int direita);
int* quickRecursivoMediana3(int *entrada, int esquerda, int direita);
int* quickSortPrimeiro(int* entrada, int n);
int* quickSortCentral(int* entrada, int n);
int* quickSortMediana(int* entrada, int n);
int* mergeSort(int* entrada, int n);
int* heapSort(int* entrada, int n);
int* radixSort(int* entrada, int n);

int* bucketSort(int* entrada, int n);


#endif