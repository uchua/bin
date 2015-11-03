#include <stddef.h>
#include <stdlib.h>
#include "dattyp.h"

/** list **/
// Initialize blank lnode
inline void init_lnode(lnode * ln) {
  ln->dat = NULL;
  ln->next = NULL;
}

// Initialize blank llist
inline void init_llist(llist * ll) {
  ll->size = 0;
  init_lnode(&ll->start);
}

// Add item to list
inline void add_llist(llist * ll, void * item) {
  if (ll->start.dat == NULL) {
    ll->start.dat = item;
  }
  else {
    lnode * n = malloc(sizeof(lnode));
    init_lnode(n);
    n->dat = item;
    lnode * end = &ll->start;
    while (end->next != NULL) {
      end = end->next;
    }
    end->next = n;
  }
  ll->size++;
}
