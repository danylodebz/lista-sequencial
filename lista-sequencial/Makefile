CC = gcc
CFLAGS = -Wall -g

all: lista_sequencial

lista_sequencial: lista_sequencial.o
	$(CC) $(CFLAGS) -o lista_sequencial lista_sequencial.o

lista_sequencial.o: lista_sequencial.c
	$(CC) $(CFLAGS) -c lista_sequencial.c

clean:
	rm -f lista_sequencial lista_sequencial.o
