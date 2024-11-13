# reminder : https://dev.to/erhant/a-makefile-template-for-small-projects-1akc

TARGET = mytree # nom du output

CC = gcc # nom du compileur

CFLAGS = -Wall -Wextra -g # debug lors de la compilation

SRC_DIR = src # dossier source

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/btree.c $(SRC_DIR)/repl.c # fichiers à compiler avec le chemin complet

OBJ = $(SRC:.c=.o) # replace par .o les fichiers en .c dans src pour la compilation

$(TARGET): $(OBJ) # regle de compilation par défaut : https://condor.depaul.edu/ealshaer/courses/TDC561/resources/MakefileTutorial.htm
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c # genere chaque .o à partir des .c
	$(CC) $(CFLAGS) -c $< -o $@

clean: # make clean
	rm -f $(OBJ) $(TARGET)

rebuild: clean $(TARGET)

.PHONY: clean rebuild # jsp mais marche pas sans (makefile template)

