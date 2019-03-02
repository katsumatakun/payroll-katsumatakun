#include "linked.h"
#include "emp_rec.h"
#include "myprint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct emp *EmpPtr;
typedef struct linked *nodeType;

void print_emp_data(nodeType pt){
  /*nodeType iterator = (nodeType) malloc(sizeof(struct linked));
  iterator = pt;*/
  nodeType iterator = pt;
  while(iterator != NULL){
  printf("fread: %s %s %s \n", (iterator->ptr)-> first_name, (iterator->ptr)->last_name, (iterator->ptr)->addr);
  iterator = iterator->back;
  }
}
