#ifndef SOCKS_VM_H
#define SOCKS_VM_H

#include "chunk.h"
#include "common.h"

typedef struct {
  // Chunk currently being operated on
  Chunk *chunk;

  // Instruction pointer
  // always points to the next instruction
  // to be executed
  uint8_t *ip;
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_RUNTIME_ERROR,
  INTERPRET_COMPILE_ERROR
} InterpretResult;

void initVM();
void freeVM();

InterpretResult interpret(Chunk *chunk);

#endif