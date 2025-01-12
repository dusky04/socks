CC = gcc
CFLAGS = -Wall -Wextra -ggdb

socks: main.c chunk.c memory.c debug.c value.c vm.c compiler.c scanner.c
	$(CC) $(CFLAGS) chunk.c main.c memory.c debug.c value.c vm.c compiler.c scanner.c -o socks

clean:
	del socks.exe