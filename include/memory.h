#ifndef FLUX_MEMORY_H
#define FLUX_MEMORY_H

#include "common.h"

#define ALLOCATE(type, count) (type *)reallocate(NULL, 0, sizeof(type) * count)

#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

#define GROW_CAPACITY(capacity) (capacity < 8 ? 8 : 2 * capacity)

#define GROW_ARRAY(type, pointer, oldCapacity, newCapacity)                    \
  (type *)reallocate(pointer, sizeof(type) * oldCapacity,                      \
                     sizeof(type) * newCapacity)

#define FREE_ARRAY(type, pointer, capacity)                                    \
  reallocate(pointer, sizeof(type) * capacity, 0)

void *reallocate(void *pointer, int oldCapacity, int newCapacity);
void freeObjects();

#endif
