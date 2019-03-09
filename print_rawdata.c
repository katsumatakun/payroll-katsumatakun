#include <stdio.h>
#include "linked.h"
#include "emp_rec.h"
#include "print_rawdata.h"
typedef struct emp *EmpPtr;

void print_raw_data(EmpPtr pt){

printf("%s %s\n", pt-> first_name, pt->last_name);
printf("Address: %s %s %s %s\n", pt->addr, pt->city, pt-> state, pt-> zipcode);
printf("Emp ID = %ld \n", pt->emp_id );
printf("Monthly Salary %g\n", pt->monthly_salary);
printf("Fed tax rate %g\n", pt->fed_tax_percent);
printf("State tax rate %g\n", pt-> state_tax_percent);
printf("Total Medical %g\n",pt->total_medical);
printf("Status %c\n\n", pt-> status);
}
