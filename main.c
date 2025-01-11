#include "chunk.h"
#include "debug.h"

int main(int argc, const char *argv[]) {

  Chunk chunk;

  initChunk(&chunk);
  writeChunk(&chunk, OP_RETURN);

  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT);
  writeChunk(&chunk, constant);

  disassembleChunk(&chunk, "Test Chunk");

  freeChunk(&chunk);

  return 0;
}