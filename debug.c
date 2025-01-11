#include <stdio.h>

#include "chunk.h"
#include "debug.h"

void disassembleChunk(Chunk *chunk, const char *name) {
  printf("\nChunk: %s\n", name);
  printf("-----------------------\n");

  for (int offset = 0; offset < chunk->count;) {
    offset = disassembleInstruction(chunk, offset);
  }
}

// A simple instruction rn might only have an OPCODE
// so it returns the bytes needed to skip over to the next instruction
static int simpleInstruction(const char *name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

int disassembleInstruction(Chunk *chunk, int offset) {
  printf("%04d ", offset);

  uint8_t instruction = chunk->bytecode[offset];
  switch (instruction) {
  case OP_RETURN:
    return simpleInstruction("OP_RETURN", offset);
  default:
    printf("Unknown opcode %d\n", instruction);
    return offset + 1;
  }
}