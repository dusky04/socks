#include <stdio.h>

#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "value.h"
#include "vm.h"

VM vm;

void initVM() {}

void freeVM() {}

static InterpretResult run() {
// Deference ip to get the bytecode and then increment the ip
// hence it always points to instruction about to be executed
#define READ_BYTE() (*(vm.ip++))

// For OP_CONSTANT, the next byte contains the index of the constant
// stored in the chunk
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

  while (true) {
#ifdef DEBUG_TRACE_EXECUTION
    // offset calculation turns it to a relative offset
    disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->bytecode));
#endif

    uint8_t instruction = READ_BYTE();
    switch (instruction) {
    case OP_CONSTANT: {
      Value constant = READ_CONSTANT();
      printValue(constant);
      printf("\n");
      break;
    }
    case OP_RETURN:
      return INTERPRET_OK;
    }
  }

#undef READ_BYTE
#undef READ_CONSTANT
}

InterpretResult interpret(Chunk *chunk) {
  vm.chunk = chunk;

  // Point the IP at the start of the bytecode
  vm.ip = chunk->bytecode;
  return run();
}