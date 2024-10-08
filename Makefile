# reminder : https://dev.to/erhant/a-makefile-template-for-small-projects-1akc

CC = gcc # compileur
CFLAGS = -Wall -g # warning + debug flags
SRC = src/btree.c # source à compiler 
OBJ = $(SRC:.c=.o) # btree.c -> btree.o
TARGET = btree # nom de l'exécutable final

all: $(TARGET) # génére executable

$(TARGET): $(OBJ) # target dependant de objet + compileur gcc + debug + exécutable
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) 	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: # regle de netoyage
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean # empeche les conflit de nommage lors de l'appelle de clean



