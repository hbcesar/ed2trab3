#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

void crescente(int n){
	int i;

	for(i=1; i<=n; i++){
		printf("%d\n", i);
	}
}

void descrescente(int n){
	int i;

	for(i=n; i>0; i--){
		printf("%d\n", i);
	}
}

void aleatorio(int n){
	int i;

	srand(time(NULL));

	for(i=0; i<n; i++){
		printf("%d\n", rand() % MAX);
	}
}

int main(int argc, char* argv []){
	int n, tipo;

	if(argc != 3){
		printf("Erro, número de argumentos inválidos!");
		exit(1);
	}
	//obtem o numero de elementos a serem gerados
	n = atoi(argv[2]);

	
	if(strcmp(argv[1], "-a")==0)
		aleatorio(n);
	else if(strcmp(argv[1], "-c")==0){
		crescente(n);
	}
	else if (strcmp(argv[1], "-d")==0){
		descrescente(n);
	}

	return 0;
}