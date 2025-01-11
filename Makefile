CC = gcc
CFLAGS = -Wall -Wextra -ggdb

socks: main.c chunk.c memory.c debug.c value.c
	$(CC) $(CFLAGS) chunk.c main.c memory.c debug.c value.c -o socks

clean:
	del socks.exe