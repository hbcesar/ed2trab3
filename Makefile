all: METODOS
	./gera -a 10 > entrada.txt
	./trab3 perm 10 < entrada.txt

METODOS:
	gcc gerar.c -o gera
	gcc -c algoritmosOrdenacao.c
	gcc -c main.c
	gcc algoritmosOrdenacao.o main.o -o trab3

