CC=gcc
CFLAGS=-Wall

all: game

game: main.o menu.o country.o
	$(CC) $(CFLAGS) -o game main.o menu.o country.o

main.o: main.c menu.h
	$(CC) $(CFLAGS) -c main.c

menu.o: menu.c menu.h country.h
	$(CC) $(CFLAGS) -c menu.c

country.o: country.c country.h
	$(CC) $(CFLAGS) -c country.c

clean:
	rm -f *.o game
