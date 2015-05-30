#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADPilha.h"
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
	int i, indice;

	for(i=0; i<n; i++){
		indice = permutacao[i];
		aux[i] = entrada[indice-1];
	}

	if(estaOrdenado(aux, n)){
		return 1;
	}
	else return 0;
}

int visit(int* entrada, int* permutacao, int* aux, int n, int k){
	int i;
	static int level = -1;

	level = level+1;
	permutacao[k] = level;
	if (level == n){
		if(verificar(entrada, permutacao, aux, n)){
			return 1;
 		}
	} else {
		for (i=0; i<n; i++){
			if (permutacao[i] == 0){
				if(visit(entrada, permutacao, aux, n, i))
					return 1;
			}
		}
	}
    
	level = level-1;
	permutacao[k] = 0;
	return 0;
}



int* permutacao(int* entrada, int n){
	int i;
	int* permutacao = (int*)malloc(n*sizeof(int));
	int* aux = (int*)malloc(n*sizeof(int));

	for(i=0; i<n; i++){
		permutacao[i] = aux[i] = 0;
	}
	
	visit(entrada, permutacao, aux, n, 0);

 	return aux;
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
	int i, j, topo = n-1, pe = 0;
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
			if (entrada[i] < entrada[i-1]){ 
				temp = entrada[i]; 
				entrada[i] = entrada[i-1];
				entrada[i-1] = temp; 
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
 * O algoritmo é baseado em se passar o menor elemento na primeira posicao,
 * o segundo menor na segunda posicao e assim por diante.
 * Porém, toda vez que se encontra um elemento menor do que o pivô, o antigo pivô assume o lugar deste novo pivô.
 * Isso faz com que alguns elementos já fiquem mais próximos da sua posição correta, porém não faz com que o numero de 
 * comparações diminua.
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


/* ------------------------------------------RANK SORT-------------------------------
 * Esse nao foi retirado de lugar nenhum, implementei by myself.
 * O rank sort é um algoritmo consideravelmente rapido e interessante, 
 * pois não faz nenhuma comparação entre elementos de sua entrada. 
 * Por outro lado, o algoritmo é limitado a capacidade de alocação (disponibilidade
 * de memória) para um vetor com o mesmo numero de casas do que seu maior 
 * elemento + 1 (para suportar o 0).
 */
int encontrarMaior(int* entrada, int n){
	int i, max=0;

	for(i=0; i<n; i++){
		if(entrada[i] > max){
			max = entrada[i];
		}
	}

	return max;
}

int* preencheElementos(int* entrada, int* aux, int n, int max){
	int i, indice;

	//preenche os elementos
	for(i=0; i<n; i++){
		indice = entrada[i];
		aux[indice] = aux[indice] + 1;
	}

	//soma as casas
	for(i=1; i<max; i++){
		aux[i] = aux[i] + aux[i-1];
	}

	return aux;
}

int* raknSort(int* entrada, int n){
	int* aux;
	int* ordenado;
	int i=0, j=0, pos=0, max=0;
	
	max = encontrarMaior(entrada, n);
	aux = (int*)malloc((++max)*sizeof(int));
	zerar(aux, max);

	aux = preencheElementos(entrada, aux, n, max);

	ordenado = (int*)malloc(n*sizeof(int));
	zerar(ordenado, n);

	//pequena correçao (ou gambiarra), que faz com que o algoritmo funcione bem com numeros 0 na entrada
	if(aux[0] != 0){
		j = aux[0];
		while (j>0){
			ordenado[pos++] = 0;
			j--;
		}
	}

	for(i=1, j=0; i<max; i++){
		j = aux[i]-aux[i-1];
		if(j>0){
			while(j>0){
				ordenado[pos++] = i;
				j--;
			}
		}
	}

	free(entrada);
	free(aux);

	return ordenado;
}

/* ------------------------------------------QUICK SORT RECURSIVO-------------------------------
 * Quicksort consiste em rearranjar as chaves com base em um elemento pivô, movendo as menores
 * do que este para a esquerda e as maiores para direita. A implementação do algoritmo é baseada na
 * idéia de dividir para conquistar. Ou seja, dividir o vetor em subvetores e realizar a mesma ação,
 * até que estes estejam pequenos o bastante para que a recursao/pilha retorne juntando os pequenos 
 * vetores, também reordenando-os. A utilização mais comum para isto se dá com uso de recursão.
 * Para implementar a versão não recursiva, fiz o uso de estrutura Pilha (implementada em Pilha.c).
 * A função divide é usada nas 6 implementações. A função que retorna mediana também é reutilizada.
 */

/* Funcao que divide os menores pra um lado e os maiores pro outro */
int divide(int *entrada, int esquerda, int direita,  int pivo){
    int pos, i, temp;

	temp = entrada[pivo];
	entrada[pivo] = entrada[direita];
	entrada[direita] = temp;

	pos = esquerda;

	for(i = esquerda; i < direita; i++){
		if (entrada[i] < entrada[direita]){
			temp = entrada[i];
			entrada[i] = entrada[pos];
			entrada[pos] = temp;
			pos++;
		}
	}

	temp = entrada[pos];
	entrada[pos] = entrada[direita];
	entrada[direita] = temp;

    return pos;
}

/* ------------------------------Primeiro Elemento como Pivô------------------------------ */
int* quickSortRecursivoPrimeiro(int *entrada, int esquerda, int direita){
	int pivo=0, pos=0;

	if (esquerda < direita){
		pivo = esquerda;
		pos = divide(entrada, esquerda, direita, pivo);
 		quickSortRecursivoPrimeiro(entrada, esquerda, pos - 1);
		quickSortRecursivoPrimeiro(entrada, pos + 1, direita);
	}

	return entrada;
}


/* ------------------------------Elemento Central como Pivô------------------------------ */
int* quickSortRecursivoCentral(int *entrada, int esquerda, int direita){
	int pivo=0, pos=0;

	if (esquerda < direita){
		pivo = (esquerda+direita)/2;
		pos = divide(entrada, esquerda, direita, pivo);
 		quickSortRecursivoCentral(entrada, esquerda, pos - 1);
		quickSortRecursivoCentral(entrada, pos + 1, direita);
	}

	return entrada;
}

/* ------------------------------Mediana de Três como Pivô------------------------------ */
/* Retorna a mediana */
int mediana(int* entrada, int a, int b, int c){
	int vet[3];

	vet[0] = entrada[a];
	vet[1] = entrada[b];
	vet[2] = entrada[c];

	/* para um vetor tão pequeno, a escolha do algoritmo de ordenação não traz significativa diferença
	 * nesse caso busquei o mais simples e com menos chamadas/atribuições
	 */
	selectionSort(vet, 3); 

	if(vet[1] == entrada[a])
		return a;
	else if (vet[1] == entrada[b])
		return b;
	else if (vet[1] == entrada[c])
		return c;

	return 0;
}

int* quickRecursivoMediana3(int *entrada, int esquerda, int direita){
	int pivo=0, pos=0;

	if (esquerda < direita){
		pivo = (esquerda+direita)/2;
		pivo = mediana(entrada, esquerda, pivo, direita);
		pos = divide(entrada, esquerda, direita, pivo);
 		quickRecursivoMediana3(entrada, esquerda, pos - 1);
		quickRecursivoMediana3(entrada, pos + 1, direita);
	}

	return entrada;
}

/* ------------------------------------------QUICK SORT NÃO RECURSIVO-------------------------------
 * Baseado em: http://homepages.dcc.ufmg.br/~rprates/aedsII/Quicksort_NaoRec.pdf
 * e: http://pwp.net.ipl.pt/cc.isel/cvaz/Textos/AED/QuickSort.pdf
 */
 /* ------------------------------Primeiro Elemento como Pivô------------------------------ */
int* quickSortPrimeiro(int* entrada, int n){
	Pilha* pilha = NULL;
	int direita=n-1, esquerda=0, pos, pivo;

	pilha = inicializaPilha(n);

	empilha(pilha, esquerda);
	empilha(pilha, direita);

	while(!vazia(pilha)){
		direita = desempilha(pilha);
		esquerda = desempilha(pilha);
		pivo = esquerda;

		if(direita <= esquerda)
			continue;

		pos = divide(entrada, esquerda, direita, pivo);

		if (pos-esquerda > direita-pos){
			empilha(pilha, esquerda);
			empilha(pilha, pos-1);
		}
	
		empilha(pilha, pos+1);
		empilha(pilha, direita);

		if (pos-esquerda <= direita-pos){
			empilha(pilha, esquerda);
			empilha(pilha, pos-1);
		}
	}

	return entrada;
}

/* ------------------------------Elemento Central como Pivô------------------------------ */
int* quickSortCentral(int* entrada, int n){
	Pilha* pilha = NULL;
	int direita=n-1, esquerda=0, pos, pivo;

	pilha = inicializaPilha(n);

	empilha(pilha, esquerda);
	empilha(pilha, direita);

	while(!vazia(pilha)){
		direita = desempilha(pilha);
		esquerda = desempilha(pilha);
		pivo = (direita + esquerda) / 2;

		if(direita <= esquerda)
			continue;

		pos = divide(entrada, esquerda, direita, pivo);

		if (pos-esquerda > direita-pos){
			empilha(pilha, esquerda);
			empilha(pilha, pos-1);
		}
	
		empilha(pilha, pos+1);
		empilha(pilha, direita);

		if (pos-esquerda <= direita-pos){
			empilha(pilha, esquerda);
			empilha(pilha, pos-1);
		}
	}

	return entrada;
}

/* ------------------------------Mediana de Três como Pivô------------------------------ */
int* quickSortMediana(int* entrada, int n){
	Pilha* pilha = NULL;
	int direita=n-1, esquerda=0, pos, pivo;

	pilha = inicializaPilha(n);

	empilha(pilha, esquerda);
	empilha(pilha, direita);

	while(!vazia(pilha)){
		direita = desempilha(pilha);
		esquerda = desempilha(pilha);
		pivo = mediana(entrada, esquerda, ((direita + esquerda) / 2), direita);

		if(direita <= esquerda)
			continue;

		pos = divide(entrada, esquerda, direita, pivo);

		if (pos-esquerda > direita-pos){
			empilha(pilha, esquerda);
			empilha(pilha, pos-1);
		}
	
		empilha(pilha, pos+1);
		empilha(pilha, direita);

		if (pos-esquerda <= direita-pos){
			empilha(pilha, esquerda);
			empilha(pilha, pos-1);
		}
	}

	return entrada;
}

/* ------------------------------------------MERGE SORT------------------------------------
 * Retirado de: http://pt.wikipedia.org/wiki/Merge_sort#C.C3.B3digo_em_C
 * e: https://www.youtube.com/watch?v=cDNqk4tdvqQ
 * O lema dessa algoritmo se basea no "dividir para conquistar". 
 * MergeSort faz separar as casas do vetor em grupos (de casas consecutivas) recursivamente,
 * até que o numero de elementos por grupo seja dois. Então, volta a recursão unindo os grupos,
 * porém desta vez, com elementos ordenados.
 */
void merge(int* entrada, int n){
	int mid;
	int i, j, k;
	int* tmp;
 
	tmp = (int*)malloc(n*sizeof(int));

	if (tmp == NULL) {
		exit(1);
	}
 
	mid = n/2;
 
	i = 0;
	j = mid;
	k = 0;

	while (i < mid && j < n) {
		if (entrada[i] <= entrada[j]) {
			tmp[k] = entrada[i++];
		}
		else {
			tmp[k] = entrada[j++];
		}
		++k;
	}
 
	if (i == mid) {
		while (j < n) {
			tmp[k++] = entrada[j++];
		}
	}
	else {
		while (i < mid) {
			tmp[k++] = entrada[i++];
		}
	}
 
	for (i = 0; i < n; ++i) {
		entrada[i] = tmp[i];
	}
 
	free(tmp);
}
 
int* mergeSort(int* entrada, int n){
	int mid;
 
	if(n > 1) {
		mid = n / 2;
		mergeSort(entrada, mid);
		mergeSort(entrada + mid, n - mid);
		merge(entrada, n);
	}

	return entrada;
}

/* ------------------------------------------HEAP SORT------------------------------------
 * Baseado em: https://www.youtube.com/watch?v=mhQpxD_ThWM
 * Esse é meu algoritmo de ordenação preferido.
 * Também é o preferido da minha professora.
 * O Heap Sort é baseado no ordenamento usando a abstração árvore balanceada.
 * Nessa implementação, o vetor é reorganizado de modo que o pai (por exemplo i=1)
 * tenha valor maior do que seus dois filhos (2*i e (2*i)+1). Assim, o primeiro elemento
 * desse vetor reorganizado é o maior de todos.
 */
int* heapfy(int* entrada, int n){
	int pai, filho1, filho2;
	int i, temp, flag=1, swap;

	while(flag){
		
		flag = 0;
		//n é decrementado pela funcao heapsort
		for(i=0; (2*i) < n-1; i++){
			pai = i;
			filho1 = (2 * (i + 1)) - 1;
			filho2 = (2 * (i + 1));

			if(filho2<n && (entrada[filho1] < entrada[filho2])){
				swap = filho2;
			} else {
				swap = filho1;
			}

			if(entrada[pai] < entrada[swap]){
				temp = entrada[pai];
				entrada[pai] = entrada[swap];
				entrada[swap] = temp;
				flag = 1;
			} 
		}
	}


	return entrada;
}

int* heapSort(int* entrada, int n){
	int* ordenado = NULL;
	int i, j, temp;

	/* dentro desse loop, o primeiro elemento do vetor
	 * é trocado com o ultimo, e o vetor é novamente submetido a "heapficação"
	 * porém, o tamanho do vetor passado vai decrementando de forma que o vetor
	 * seja ordenado de tras pra frente.
	 */
	for(i=n, j=n-1; i>0; i--, j--){
		entrada = heapfy(entrada, i);	
		temp = entrada[j];
		entrada[j] = entrada[0];
		entrada[0] = temp;
	}

	return entrada;

}

/* ------------------------------------------RADIX SORT (não binário)------------------------------------
 * Retirado de: http://pt.wikipedia.org/wiki/Radix_sort#C.C3.B3digo_em_C
 */
int* radixSort(int* entrada, int n){
    int i;
    int b[n];
    int maior = entrada[0];
    int exp = 1;
 
 	maior = encontrarMaior(entrada, n);
 
    while (maior/exp > 0) {
        int bucket[10] = { 0 };

    	for (i = 0; i < n; i++)
    	    bucket[(entrada[i] / exp) % 10]++; 

    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];

    	for (i = n - 1; i >= 0; i--)
    	    b[--bucket[(entrada[i] / exp) % 10]] = entrada[i];

    	for (i = 0; i < n; i++)
    	    entrada[i] = b[i];
    	
    	exp *= 10;
    }

    return entrada;
}