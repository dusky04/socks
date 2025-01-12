#ifndef SOCKS_VM_H
#define SOCKS_VM_H

#include "chunk.h"
#include "common.h"

#define MAX_STACK_LIMIT 256

typedef struct {
  // Chunk currently being operated on
  Chunk *chunk;

  // Instruction pointer
  // always points to the next instruction
  // to be executed
  uint8_t *ip;

  // Stack based VM
  Value stack[MAX_STACK_LIMIT];
  Value *stackTop; // Points at the element just past the element
                   // containing the top value on the stack
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_RUNTIME_ERROR,
  INTERPRET_COMPILE_ERROR
} InterpretResult;

void initVM();
void freeVM();

InterpretResult interpret(Chunk *chunk);

// Stack operations
void push(Value value);
Value pop();

#endif