#include <stdio.h>
#include "linked.h"
#include "emp_rec.h"
#include "myprint.h"

/*
  This function will accept a pointer of nodeType
  that is the head of a linked list and will print
  out each employee's payment record stored in each
  node of the list.
*/
void print_emp_data(nodeType pt){

  nodeType iterator = pt;
  while(iterator != NULL){
    float bi_weekly_pay = (iterator->ptr)->monthly_salary *12/26;
    float fed_tax = bi_weekly_pay * ((iterator->ptr)->fed_tax_percent /100);
    float state_tax = bi_weekly_pay * ((iterator->ptr)->state_tax_percent /100);
    float medical = ((iterator->ptr)->total_medical * 12/26);
    // printf("%s %s\n", (iterator->ptr)-> last_name, (iterator->ptr)->first_name);
    // printf("Bi-weekly pay total: %.2f \n", bi_weekly_pay);
    // printf("Federal Tax: %.2f \n", fed_tax);
    // printf("State Tax: %.2f \n", state_tax);
    // printf("Medical Insuarance: %.2f \n", medical);
    // printf("Net Pay: %.2f\n\n", bi_weekly_pay - fed_tax - state_tax - medical);
    printf("%-10s %-14s %6.2f %13.2f %10.2f %10.2f %10.2f \n",(iterator->ptr)-> last_name, (iterator->ptr)->first_name,
  bi_weekly_pay, fed_tax, state_tax, medical, bi_weekly_pay - fed_tax - state_tax - medical);
    iterator = iterator->back;
  }
}
