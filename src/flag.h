#ifndef BIN_FLAG_H
#define BIN_FLAG_H
#include <stdlib.h>

typedef struct {
  char * flag;
  int val;
} bin_flag_t;

typedef struct {
  bin_flag_t * flags;
  size_t num;
} bin_flags_t;

#endif //BIN_FLAG_H
