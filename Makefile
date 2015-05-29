all: METODOS
	./gera -a 5 > entrada.txt
	./trab3 quickrecursivomediana3 5 < entrada.txt

METODOS:
	#gcc gera.c -o gera
	gcc -c algoritmosOrdenacao.c
	gcc -c funcoes.c
	gcc -c main.c
	gcc funcoes.o algoritmosOrdenacao.o main.o -o trab3

