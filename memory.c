#include <stdlib.h>

#include "memory.h"

void *reallocate(void *pointer, size_t old_capacity, size_t new_capacity) {
  if (new_capacity == 0) {
    free(pointer);
    return NULL;
  }

  void *result = realloc(pointer, new_capacity);
  if (!result) // allocation failed
    exit(1);

  return result;
}