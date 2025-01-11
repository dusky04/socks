#ifndef SOCKS_VALUE_H
#define SOCKS_VALUE_H

#include "common.h"

typedef double Value;

typedef struct {
  // Total number of entries the array can store
  int capacity;

  // Number of elements in use
  int count;

  // the bytecode array
  Value *values;
} ValueArray;

void initValueArray(ValueArray *array);
void writeValueArray(ValueArray *array, Value value);
void printValue(Value value);
void freeValueArray(ValueArray *array);

#endif