#include <stdlib.h>
#include "linked.h"
#include "delete_list.h"
typedef struct linked *nodeType;
/*
  This function will accept a pointer
  of nodeType that is the head of the linked
  List and will delete each node of the list.
*/

void delete_list(nodeType pt){
  nodeType iterator;
  while(pt != NULL){
      iterator = pt;
      pt = pt->back;
      free(iterator);
    }
  }
