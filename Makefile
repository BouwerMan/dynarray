CC=gcc

CFLAGS:=-Wall -Wextra -pedantic -std=gnu17

all:
	$(CC) $(CFLAGS) main.c -o main

clean:
	rm main
