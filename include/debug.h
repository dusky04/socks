#ifndef FLUX_DEBUG_H
#define FLUX_DEBUG_H

#include "chunk.h"

// A 'chunk' contains sequence of instructions / opcodes (which are bytes)
void disassembleChunk(Chunk *chunk, const char *name);

// A 'instruction' consists of a
// 1. OPCODE
// 2. ARGS that the instruction might use
// the offset would be the number of bytes of bytes that to get
// to the next instruction
// returns the bytes needed to skip over to the next instruction
int disassembleInstruction(Chunk *chunk, int offset);

#endif