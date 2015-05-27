all: METODOS
	#./gera -a 10 > entrada.txt
	./trab3 merge 20 < entrada.txt

METODOS:
	#gcc gera.c -o gera
	gcc -c algoritmosOrdenacao.c
	gcc -c funcoes.c
	gcc -c main.c
	gcc funcoes.o algoritmosOrdenacao.o main.o -o trab3

