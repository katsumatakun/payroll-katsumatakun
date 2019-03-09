#include <stdio.h>
#include "emp_rec.h"
#include "print_rawdata.h"

/*
  This function accepts a pointer to emp(information of a employee)
   and print all of the data, such that name, address, id, monthly salary,
   tax rates, medical insuarance amount, and status.
*/

void print_raw_data(EmpPtr pt){

printf("%s %s\n", pt-> last_name, pt->first_name);
printf("Address: %s %s %s %s\n", pt->addr, pt->city, pt-> state, pt-> zipcode);
printf("Emp ID = %ld \n", pt->emp_id );
printf("Monthly Salary %.2f\n", pt->monthly_salary);
printf("Fed tax rate %.3f\n", pt->fed_tax_percent);
printf("State tax rate %.3f\n", pt-> state_tax_percent);
printf("Total Medical %.2f\n",pt->total_medical);
printf("Status %c\n\n", pt-> status);
}
