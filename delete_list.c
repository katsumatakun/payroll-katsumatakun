#include <stdlib.h>
#include "linked.h"
#include "delete_list.h"
typedef struct linked *nodeType;


void delete_list(nodeType pt){
  nodeType iterator;
  while(pt != NULL){
      iterator = pt;
      pt = pt->back;
      free(iterator);
    }
  }
