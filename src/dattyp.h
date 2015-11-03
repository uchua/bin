#ifndef DATA_TYPES_H
#define DATA_TYPES_H
#include <stdlib.h>

/** list **/
typedef struct lnode {
  void * dat;
  struct lnode * next;
} lnode;

typedef struct llist {
  size_t size;
  lnode start;
} llist;

#endif //DATA_TYPES_H
