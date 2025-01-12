#ifndef SOCKS_CHUNK_H
#define SOCKS_CHUNK_H

#include "common.h"
#include "value.h"

typedef enum {
  // OPCODE + index where the constant was stored
  OP_CONSTANT,

  OP_NEGATE,
  OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,

  OP_RETURN,
} OpCode;

typedef struct {
  // Total number of entries the array can store
  int capacity;

  // Number of elements in use
  int count;

  // the bytecode array
  uint8_t *bytecode;

  // Each number in the array is the line number for the
  // corresponding byte in the bytecode
  int *lines;

  // associated constants with the chunk
  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);

// Add a constant to a chunk
// return the index where the constant was appended
int addConstant(Chunk *chunk, Value value);

void freeChunk(Chunk *chunk);

#endif