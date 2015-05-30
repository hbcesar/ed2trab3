all: METODOS
	./gera -a 10 > entrada.txt
	./trab3 radix 10 < entrada.txt

METODOS:
	#gcc gera.c -o gera
	gcc -c algoritmosOrdenacao.c
	gcc -c pilha.c
	gcc -c funcoes.c
	gcc -c main.c
	gcc funcoes.o pilha.o algoritmosOrdenacao.o main.o -o trab3

