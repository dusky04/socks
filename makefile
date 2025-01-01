CC = gcc
CFLAGS = -Wall -Wextra

socks: main.c chunk.c debug.c memory.c value.c
	$(CC) $(CFLAGS) main.c chunk.c debug.c memory.c value.c -o socks