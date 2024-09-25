# Variables
CC = gcc
CFLAGS = -Wall -std=c11

# Cible par défaut qui compile et lance le programme
all: my_program

# Compilation du programme
my_program: btree.o main.o repl.o
	$(CC) -o my_program btree.o main.o repl.o

# Compilation des fichiers objets
btree.o: btree.c
	$(CC) $(CFLAGS) -c btree.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

repl.o: repl.c
	$(CC) $(CFLAGS) -c repl.c

# Lancer le programme
run: my_program
	./my_program

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f *.o my_program
