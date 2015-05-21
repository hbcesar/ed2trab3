#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ------------------------------------------PERMUTACAO-------------------------------
// Retirado de: http://goo.gl/KgeVIt
int* permutacao(int* entrada, int n){
	int i, j, temp;

	//primeiro for faz com que cada indice do vetor seja verificado
	for(i=0; i<n; i++){
		//segundo for percorre do fim do vetor até o indice que esta sendo verificado (descrescendo)
		//e carrega consigo o menor elemento daquele subvetor
		for(j=n-1; j>=i; j--){
			//toda vez que acha um elemento menor, troca de lugar
			if(entrada[i] > entrada[j]){
				temp = entrada[i];
				entrada[i] = entrada[j];
				entrada[j] = temp;
			}
		}
	}

/*
 * Pior caso:
 * elementos ordenados em forma decrescente
 */

 return entrada;
}


// ------------------------------------------BUBBLE SORT-------------------------------
 //http://pt.wikipedia.org/wiki/Bubble_sort#Implementa.C3.A7.C3.A3o
int* buubleSort(int* entrada, int n){
	int i, j, temp;

	/*
	 * O bubble sort é parecido com o permuta, em termos de ordem de grandeza das comparações
	 * Basicamente, o algoritmo percorre o vetor do fim ao inicio
	 * Em cada iteracao de i, j faz i iteracoes
	 * verificando se o elemento no menor indice é maior que o elemento no indice posterior (j+1), 
	 * se for, troca as posições destes.
	 */
	for(i=n-1; i>0; i--){
 		for(j=0; j<i; j++){
 			if(entrada[j]>entrada[j+1]){
 				temp = vetor[j];
 				entrada[j] = entrada[j+1];
 				entrada[j+1] = temp;
			}
		}
	}

	return entrada;
}


// ------------------------------------------SHAKE SORT-------------------------------
// Retirado de: http://rosettacode.org/wiki/Sorting_algorithms/Cocktail_sort#C
// e: http://pt.wikipedia.org/wiki/Cocktail_sort#C.C3.B3digo_em_C (otimizacao topo/pe)
int* shakeSort(int* entrada, int n){
	int i, j, topo = n, pe = 0;
	int temp = 0;


	/*
	 * Achei esse algoritmo meio samba do criolo doido
	 * O que ele faz é o seguinte:
	 * Enquanto temp for igual a zero (se houver algum elemento nao ordenado, temp é setada zero)
	 * Percorre o vetor duas vezes para cada loop do while
	 * Na primeira vez carrega o maior elemento para sua ordem no vetor (i indo de zero a n)
	 * Na segunda vez carrega o menor para sua ordem (i indo de n a zero)
	 * Se um dos dois casos nao setar temp = 0, termina o loop do while e o vetor está ordenado
	 */
	while ((!temp) && (pe<topo) {
		for (i=pe, t=1; i<topo; i++) {
			if (entrada[i] > entrada[i+1]){ 
				temp = entrada[i]; 
				entrada[i] = entrada[i+1];
				entrada[i+1] = temp; 
				temp = 0;
			}
		}
		
		topo--;

		if (temp)
			break;

		for(i=topo, t=1; i>pe; i--){
			if (entrada[i] > entrada[i+1]){ 
				temp = entrada[i]; 
				entrada[i] = entrada[i+1];
				entrada[i+1] = temp; 
				temp = 0;
			}
		}

		pe++;
	}

	return entrada;
}


// ------------------------------------------INSERTION SORT-------------------------------
// Retirado de: http://pt.wikipedia.org/wiki/Insertion_sort#Algorithm
// e: http://en.wikipedia.org/wiki/Insertion_sort
int* insertionSort(int* entrada, int n){
	int i, j, eleito;
	for (i = 1; i < tam; i++){
		eleito = numeros[i];
		j = i - 1;
		while ((j>=0) && (eleito < numeros[j])) {
			numeros[j+1] = numeros[j];
			j--;
		}
		numeros[j+1] = eleito;
	}
}