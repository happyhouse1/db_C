# reminder : https://dev.to/erhant/a-makefile-template-for-small-projects-1akc

TARGET = esgi-tree # nom du output

CC = gcc # nom du compileur

CFLAGS = -Wall -Wextra -g # debug lors de la compilation

SRC = src/main.c src/btree.c src/repl.c # fichiers à compiler avec le chemin complet car bug avec variables
OBJ = src/main.o src/btree.o src/repl.o # fichiers objets avec chemins complets car bug avec variables

all: $(TARGET) # règle de compilation par défaut

$(TARGET): $(OBJ) # compilation de l'exécutable final
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# règles explicites pour chaque fichier .o fixed
src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/btree.o: src/btree.c
	$(CC) $(CFLAGS) -c src/btree.c -o src/btree.o

src/repl.o: src/repl.c
	$(CC) $(CFLAGS) -c src/repl.c -o src/repl.o

clean: # make clean
	rm -f $(OBJ) $(TARGET)

rebuild: clean all # recompile tout

.PHONY: all clean rebuild # déclare les cibles phony pour éviter les erreurs
