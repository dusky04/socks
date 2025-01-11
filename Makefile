CC = gcc
CFLAGS = -Wall -Wextra -ggdb

socks: main.c chunk.c memory.c debug.c
	$(CC) $(CFLAGS) chunk.c main.c memory.c debug.c -o socks

clean:
	del socks.exe