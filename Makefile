CC = gcc
CFLAGS = -Wall -g -w -mconsole -municode
EXEC = main
SRC = src/main.c

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

clean:
	rm -f $(EXEC)
