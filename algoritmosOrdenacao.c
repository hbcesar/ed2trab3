#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADFuncoes.h"


/* ------------------------------------------PERMUTACAO-------------------------------
 * O objetivo desse método é criar todas as permutações possiveis sobre as casas
 * do vetor, até que uma delas seja a combinação que gere um vetor com entradas ordenadas
 * é quase como jogar na mega-sena. O algoritmo é composto por três funções:
 * a função verificar, que gera o vetor a partir da combinação de permutações e verifica se este está ordenado
 * a função visit, que gera as combinações
 * e a função chamadora.
 * A função visit foi escrita com base em:
 * http://www.bearcave.com/random_hacks/permute.html
 * http://newton.ex.ac.uk/teaching/resources/jmr/recursion.html
 */

int verificar(int* entrada, int* permutacao, int* aux, int n){
	int i;

	for(i=0; i<n; i++){
		aux[i] = entrada[(permutacao[i])];
	}

	if(estaOrdenado(aux, n))
		return 1;
	else return 0;
}

void visit(int* entrada, int* permutacao, int* aux, int n, int k){
	int i;
	static int level = -1;

	level = level+1;
	permutacao[k] = level;
	if (level == n){
		if(verificar(entrada, permutacao, aux, n)){
			return;
 		}
	} else {
		for (i = 0; i < n; i++){
			if (permutacao[i] == 0){
				visit(entrada, permutacao, aux, n, i);
			}
		}
	}
    
	level = level-1;
	permutacao[k] = 0;
}



int* permutacao(int* entrada, int n){
	int* permutacao = (int*)malloc(n*sizeof(int));
	int* aux = (int*)malloc(n*sizeof(int));
	
	visit(entrada, permutacao, aux, n, 0);

 	return entrada;
}


/* ------------------------------------------BUBBLE SORT-------------------------------
 * http://pt.wikipedia.org/wiki/Bubble_sort#Implementa.C3.A7.C3.A3o
 *
 * O bubble sort é parecido com o permuta, em termos de ordem de grandeza das comparações
 * Basicamente, o algoritmo percorre o vetor do fim ao inicio
 * Em cada iteracao de i, j faz i iteracoes
 * verificando se o elemento no menor indice é maior que o elemento no indice posterior (j+1), 
 * se for, troca as posições destes.
 */
int* bubbleSort(int* entrada, int n){
	int i, j, temp;

	for(i=n-1; i>0; i--){
 		for(j=0; j<i; j++){
 			if(entrada[j]>entrada[j+1]){
 				temp = entrada[j];
 				entrada[j] = entrada[j+1];
 				entrada[j+1] = temp;
			}
		}
	}

	return entrada;
}


/* ------------------------------------------SHAKE SORT-------------------------------
 * Retirado de: http://rosettacode.org/wiki/Sorting_algorithms/Cocktail_sort#C
 * e: http://pt.wikipedia.org/wiki/Cocktail_sort#C.C3.B3digo_em_C (otimizacao topo/pe)
 *
 * Achei esse algoritmo meio samba do criolo doido
 * O que ele faz é o seguinte:
 * Enquanto temp for igual a zero (se houver algum elemento nao ordenado, temp é setada zero)
 * Percorre o vetor duas vezes para cada loop do while
 * Na primeira vez carrega o maior elemento para sua ordem no vetor (i indo de zero a n)
 * Na segunda vez carrega o menor para sua ordem (i indo de n a zero)
 * Se um dos dois casos nao setar temp = 0, termina o loop do while e o vetor está ordenado
 */
int* shakeSort(int* entrada, int n){
	int i, j, topo = n, pe = 0;
	int temp = 0;

	while ((!temp) && (pe<topo)){
		for (i=pe; i<topo; i++) {
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

		for(i=topo; i>pe; i--){
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


/* ------------------------------------------INSERTION SORT-------------------------------
 * Retirado de: http://pt.wikipedia.org/wiki/Insertion_sort#Algorithm
 * e: http://en.wikipedia.org/wiki/Insertion_sort
 * 
 * Esse metodo pode realizar um número altissimo de permutações
 * Nesse caso, a cada fim da iteracao de i teremos o vetor ordenado até aquele indice
 * Para cada casa do vetor que for "checada", o loop while verificará (de traz pra frente)
 * se a aquela casa for menor do que a anterior, o algoritmo permuta um por um até que esta 
 * chegue em sua posição correta.
 */
int* insertionSort(int* entrada, int n){
	int i, j, temp;


	for (i=1; i<n; i++){
		temp = entrada[i];
		j = i-1;
		while ((j>=0) && (temp < entrada[j])) {
			entrada[j+1] = entrada[j];
			j--;
		}
		entrada[j+1] = temp;
	}

	return entrada;
}


/* ------------------------------------------SHELL SORT-------------------------------
 * Retirado de: http://pt.wikipedia.org/wiki/Shell_sort#C.C3.B3digo_em_C
 * http://fr.wikipedia.org/wiki/Tri_de_Shell
 * http://en.wikipedia.org/wiki/Shellsort
 * https://www.youtube.com/watch?v=M9YCh-ZeC7Y
 * O big deal desse método consiste em comparar elementos com uma distância (gap) consideravel.
 * Então, esse gap é progressivamente reduzido. Isso faz com que elementos fora do lugar possam
 * ser movidos para sua posição correta mais rapidamente do que em simples insertion sort.
 * Na implementação a seguir, o gap é reduzido a metade.
 */
int* shellSort(int *entrada, int n){
    int i, j, aux;
    int gap = n;

    while ( gap > 1) {
        gap = gap/2;

        for(i = gap; i<n; i++) {
            aux = entrada[i];
            j = i - gap;

            while (j >= 0 && aux < entrada[j]) {
                entrada [j + gap] = entrada[j];
                j = j - gap;
            }

            entrada [j + gap] = aux;
        }
    }

    return entrada;
}

/* ------------------------------------------SELECTION SORT-------------------------------
 * Retirado de: http://pt.wikipedia.org/wiki/Selection_sort
 * https://www.youtube.com/watch?v=BSXIolKg5F8
 */
int* selectionSort(int* entrada, int n){ 
  int i, j, min, aux;

	for(i=0; i<(n-1); i++){
		min = i;

		for(j=(i+1); j<n; j++){
			if(entrada[j] < entrada[min]){
				min = j;
			}
		}

		if(i !=  min){
			aux = entrada[i];
			entrada[i] = entrada[min];
			entrada[min] = aux;
		}
	}

	return entrada;
}
