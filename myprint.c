#include <stdio.h>
#include "linked.h"
#include "emp_rec.h"
#include "myprint.h"

/*
  This function will accept head pointer
  pointing to the pointer to the first node
  in the linked list and will print out
  each employee's gross pay, taxes amount, medical insurance
  amount, and net pay in bi-weekly scale.
  It will also print each total.
*/
void print_emp_data(nodeType* pt){

  nodeType iterator = *pt; //pointer to the first node
  float total_bi_weekly = 0;
  float total_fed_tax = 0;
  float total_state_tax = 0;
  float total_insurance = 0;
  float total_net_wage = 0;
  while(iterator != NULL){

    //find each value to be printed
    float bi_weekly_pay = (iterator->ptr)->monthly_salary *12/26;
    float fed_tax = bi_weekly_pay * ((iterator->ptr)->fed_tax_percent /100);
    float state_tax = bi_weekly_pay * ((iterator->ptr)->state_tax_percent /100);
    float medical = ((iterator->ptr)->total_medical * 12/26);

    //increment totals
    total_bi_weekly+=bi_weekly_pay;
    total_fed_tax+=fed_tax;
    total_state_tax+=state_tax;
    total_insurance+=medical;
    total_net_wage+=(bi_weekly_pay - fed_tax - state_tax - medical);

    printf("%-10s %-14s %6.2f %13.2f %10.2f %11.2f %12.2f \n",(iterator->ptr)-> last_name, (iterator->ptr)->first_name,
  bi_weekly_pay, fed_tax, state_tax, medical, bi_weekly_pay - fed_tax - state_tax - medical);
    iterator = iterator->back;
  }
  printf("TOTAL PAYMENTS \t\t %8.2f %13.2f %10.2f %11.2f %12.2f  \n", total_bi_weekly, total_fed_tax, total_state_tax, total_insurance, total_net_wage );
}
