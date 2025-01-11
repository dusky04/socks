#include "chunk.h"
#include "memory.h"
#include "value.h"

void initChunk(Chunk *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->bytecode = NULL;
  initValueArray(&chunk->constants);
}

void writeChunk(Chunk *chunk, uint8_t byte) {

  // Increase capacity dynamically
  if (chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->bytecode =
        GROW_ARRAY(uint8_t, chunk->bytecode, oldCapacity, chunk->capacity);
  }

  chunk->bytecode[chunk->count++] = byte;
}

int addConstant(Chunk *chunk, Value value) {
  writeValueArray(&chunk->constants, value);
  return chunk->constants.count - 1;
}

void freeChunk(Chunk *chunk) {
  FREE_ARRAY(uint8_t, chunk->bytecode, chunk->capacity);
  freeValueArray(&chunk->constants);
  initChunk(chunk);
}