#ifndef SOCKS_VALUE_H
#define SOCKS_VALUE_H

#include "common.h"

// Tagged Union
typedef enum {
  VAL_BOOL,
  VAL_NIL,
  VAL_NUMBER,
} ValueType;

typedef struct {

  // To define what kind of Value it is
  ValueType type;

  // A value can be any one of these types right now
  union {
    bool boolean;
    double number;
  } as;

} Value;

// Macros to confirm whether a value is of the correct type we assumed it to be
// Mostly so I don't blow myself in the foot
#define IS_BOOL(value) ((value).type == VAL_BOOL)
#define IS_NIL(value) ((value).type == VAL_NIL)
#define IS_NUMBER(value) ((value).type == VAL_NUMBER)

#define AS_BOOL(value) ((value).as.boolean)
#define AS_NUMBER(value) ((value).as.number)

// Macros for C types conversion to Value (which are flux types)
#define BOOL_VAL(value) ((Value){VAL_BOOL, {.boolean = value}})
#define NIL_VAL ((Value){VAL_NIL, {.number = 0}})
#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})

typedef struct {
  // Total number of entries the array can store
  int capacity;

  // Number of elements in use
  int count;

  // the bytecode array
  Value *values;
} ValueArray;

// For each value type, we have a separate case that handles comparing the value
// itself. Given how similar the cases are, you might wonder why we can’t simply
// memcmp() the two Value structs and be done with it. The problem is that
// because of padding and different-sized union fields, a Value contains unused
// bits. C gives no guarantee about what is in those, so it’s possible that two
// equal Values actually differ in memory that isn’t used.
bool valuesEqual(Value a, Value b);

void initValueArray(ValueArray *array);
void writeValueArray(ValueArray *array, Value value);
void printValue(Value value);
void freeValueArray(ValueArray *array);

#endif