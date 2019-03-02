#include <stdio.h>
#include "linked.h"
#include "emp_rec.h"
#include "myprint.h"
typedef struct emp *EmpPtr;
typedef struct linked *nodeType;

void print_emp_data(nodeType pt){
  nodeType iterator = pt;
  while(iterator != NULL){
  printf("fread: %s %s %f %f %f %f %f \n", (iterator->ptr)-> first_name, (iterator->ptr)->last_name,
  (iterator->ptr)->monthly_salary *12/26, (iterator->ptr)->monthly_salary *12,
  (iterator->ptr)->fed_tax_percent, (iterator->ptr)->state_tax_percent, (iterator->ptr)->total_medical);
  iterator = iterator->back;
  }
}
