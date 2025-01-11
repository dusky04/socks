#ifndef SOCKS_CHUNK_H
#define SOCKS_CHUNK_H

#include "common.h"
#include <stdint.h>

typedef enum {
  OP_RETURN,
} OpCode;

typedef struct {
  // Total number of entries the array can store
  int capacity;

  // Number of elements in use
  int count;

  // the bytecode array
  uint8_t *bytecode;
} Chunk;

void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte);
void freeChunk(Chunk *chunk);

#endif