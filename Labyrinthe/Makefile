CC=gcc
FLAGS=-Wall -Werror -g

all : 	prog

prog :	fonctions.o main.o
		$(CC) fonctions.o main.o -o prog -lm

fonctions.o:	fonctions.c fonctions.h
		$(CC) -c fonctions.c $(FLAGS) -o fonctions.o

main.o:	main.c fonctions.h
		$(CC) -c main.c $(FLAGS) -o main.o

clean :
		rm -f *.o
		rm -f prog
