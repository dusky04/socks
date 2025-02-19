CC = gcc
CFLAGS = -Wall -Wextra -ggdb

flux: main.c chunk.c memory.c debug.c value.c vm.c compiler.c scanner.c
	$(CC) $(CFLAGS) chunk.c main.c memory.c debug.c value.c vm.c compiler.c scanner.c -o flux

clean:
	del flux.exe