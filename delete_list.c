#include <stdlib.h>
#include <stdio.h> // to be removed
#include "linked.h"
#include "emp_rec.h"
#include "delete_list.h"
#include "myprint.h" // to be removed
typedef struct linked *nodeType;
/*
  This function will accept a pointer
  of nodeType that is the head of the linked
  List and will delete each node of the list
  to deallocate memory.
*/

void delete_list(nodeType pt){
  //print_emp_data(pt);
  nodeType iterator;
  while(pt != NULL){
    iterator = pt;
    printf("%f\n",(pt->ptr)->monthly_salary);
    pt = pt->back;
    free(iterator);
    printf("delete\n" );
    }
  }
