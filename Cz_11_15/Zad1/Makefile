CFLAGS = -Wall
CC = gcc

zad1: zad1.c
	$(CC) $(CFLAGS) zad1.c -o zad1

clean:
	rm -f ./zad1.o ./zad1

test: zad1
	@echo -e "\n\nTESTING\n\n"
	./zad1 plik katalog slink

all: zad1 test
