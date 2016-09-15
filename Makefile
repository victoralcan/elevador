all: main.o elevador.o io.o
	gcc main.o elevador.o io.o -o T
main.o: main.c	
	gcc -c main.c
elevador.o: elevador.c
	gcc -c elevador.c
io.o: io.c
	gcc -c io.c
	
	
