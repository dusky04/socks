#ifndef SOCKS_MEMORY_H
#define SOCKS_MEMORY_H

#include "common.h"

#define GROW_CAPACITY(capacity) ((capacity < 8) ? 8 : 2 * capacity)

#define GROW_ARRAY(type, pointer, old_capacity, new_capacity)                  \
  (type *)reallocate(pointer, sizeof(type) * (old_capacity),                   \
                     sizeof(type) * (new_capacity))

#define FREE_ARRAY(type, pointer, old_capacity)                                \
  reallocate(pointer, sizeof(type) * old_capacity, 0)

void *reallocate(void *pointer, size_t old_capacity, size_t new_capacity);

#endif