#include <stdbool.h>
#include <stdio.h>

#include "chunk.h"
#include "common.h"
#include "compiler.h"
#include "debug.h"
#include "value.h"
#include "vm.h"

VM vm;

static void resetStack() {
  // Point the SP at the start of the stack
  vm.stackTop = vm.stack;
}

void initVM() { resetStack(); }

void freeVM() {}

static InterpretResult run() {
// Deference ip to get the bytecode and then increment the ip
// hence it always points to instruction about to be executed
#define READ_BYTE() (*(vm.ip++))

// For OP_CONSTANT, the next byte contains the index of the constant
// stored in the chunk
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

#define BINARY_OP(op)                                                          \
  do {                                                                         \
    double b = pop();                                                          \
    double a = pop();                                                          \
    push(a op b);                                                              \
  } while (false)

  while (true) {
#ifdef DEBUG_TRACE_EXECUTION
    printf("STACK: ");

    for (Value *slot = vm.stack; slot < vm.stackTop; slot++) {
      printf("[");
      printValue(*slot);
      printf("]");
    }
    printf("\n");

    // offset calculation turns it to a relative offset
    disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->bytecode));
#endif

    uint8_t instruction = READ_BYTE();
    switch (instruction) {
    case OP_CONSTANT: {
      Value constant = READ_CONSTANT();
      printf("Value pushed by OP_CONSTANT: ");
      printValue(constant);
      printf("\n");
      push(constant);
      break;
    }
    case OP_ADD:
      BINARY_OP(+);
      break;
    case OP_SUBTRACT:
      BINARY_OP(-);
      break;
    case OP_MULTIPLY:
      BINARY_OP(*);
      break;
    case OP_DIVIDE:
      BINARY_OP(/);
      break;
    case OP_NEGATE:
      push(-pop());
      break;
    case OP_RETURN: {
      printf("Value popped by OP_RETURN: ");
      printValue(pop());
      printf("\n");
      return INTERPRET_OK;
    }
    }
  }

#undef READ_BYTE
#undef READ_CONSTANT
#undef BINARY_OP
}

InterpretResult interpret(const char *source) {
  Chunk chunk;
  initChunk(&chunk);

  // Can't compile
  if (!compile(source, &chunk)) {
    freeChunk(&chunk);
    return INTERPRET_COMPILE_ERROR;
  }

  // The compiler will read the source
  // and populate the empty chunk with bytecode

  vm.chunk = &chunk;
  // Point IP towards the starting of the bytecode
  vm.ip = vm.chunk->bytecode;

  InterpretResult result = run();

  freeChunk(&chunk);

  return result;
}

void push(Value value) {
  // Dereference the SP and store the value at that addrese
  *(vm.stackTop) = value;
  vm.stackTop++;
}

Value pop() {
  // Since SP always points to the element past
  // the top element, so you decrement first
  // then dereference
  vm.stackTop--;
  return *(vm.stackTop);
}