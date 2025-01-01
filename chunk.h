// bytecode is a series of instructions
// in this bytecode, each instruction(ADD, SUB, etc.) has one byte opcode

#ifndef SOCKS_CHUNK_H
#define SOCKS_CHUNK_H

#include "common.h"
#include <stdint.h>

typedef enum {
  OP_RETURN, // return from the current function
} OpCode;

// chunk refers to a sequence of bytecodes.
// chunk is a dynamic array
typedef struct {
  // no. of entries in use
  int count;

  // total no. of entries allocated
  int capacity;

  // pointer to our bytecode
  uint8_t *code;
} Chunk;

void init_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte);
void free_chunk(Chunk *chunk);

#endif
