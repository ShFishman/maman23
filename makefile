main: main.o permutation.o
	gcc -Wall -ansi -pedantic main.o permutation.o -o main
main.o: main.c permutation.h
	gcc -c -ansi -Wall -pedantic main.c -o main.o
permutation.o: permutation.c
	gcc -c -Wall -ansi -pedantic permutation.c -o permutation.o

