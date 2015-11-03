#include <stdlib.h>
#include <string.h>
#include "flag.h"

int is_flag(const char * in_str, size_t len) {
  if (len == 2) {
    return (in_str[0] == '-' && in_str[1] != '-');
  }
  else if (len > 2) {
    return (in_str[0] == '-' && in_str[1] == '-' && in_str[2] != '-');
  }
  else {
    return 0;
  }
}

void get_flag(const char * in_str, size_t len, char ** dst) {
  int i, j;
  i = 0;
  while (in_str[i] == '-' && i < len) {
    i++;
  }
  *(dst) = malloc(sizeof(char) * len-(i-1));
  j = 0;
  while (i < len) {
    *(dst)[j] = in_str[i];
    i++;
    j++;
  }
}

int check_flag(char * flag_str, bin_flags_t flags) {
  int i, r;
  r = -1;
  for (i = 0; i < flags.num; i++) {
    if (!strcmp(flag_str, flags.flags[i].flag)) {
      r = flags.flags[i].val;
      break;
    }
  }
  return r;
}
