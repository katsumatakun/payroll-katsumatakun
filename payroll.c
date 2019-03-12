#include <stdio.h>
#include <stdlib.h>
#include "emp_rec.h"
#include "linked.h"
#include "insert.h"
#include "print_calculated.h"
#include "print_rawdata.h"

/*
  This program reads a structured binary file of eployee records
  that is unsorted and first print out all of the data for
  each employee and then print out employee's bi-weekly net pay
  and total payment in descending alphabetical order.
*/
int main(int argc, char* argv[]) {

  //invalid input
  if (argc != 2) {
    printf("usage: progam name, binary file name\n");
    return -1;
  }

  //Open file with checking
  FILE *fp;
  if((fp = fopen(argv[1], "rb")) == NULL ) {
    printf("Input file not open\n");
    return -1;
  }

  nodeType head_ptr = NULL;

  //Allocate space for the first record while checking if there
  //is memory space.
  EmpPtr q;
  q = (EmpPtr) malloc(sizeof(struct emp));
  if(q == NULL){
    printf("No more memory space available \n");
    return -1;
  }


  //Read the first data with checking
  //if could not read data, terminate the program
  int num_element;
  num_element = fread(q, sizeof(struct emp), 1, fp);
  if(num_element != 1){
    printf("Reading data failed \n");
    free(q);  // deallocation
    return -1;
  }

  //while not EOF
  while(num_element == 1){
    print_raw_data(q);

    //Insert data with dainamically allocation
    head_ptr = insertData(head_ptr, q);
    if(head_ptr == NULL){
      printf("No more memory space available \n");
      return -1;
    }

    //Allocate memory for the next record
    q = (EmpPtr) malloc(sizeof(struct emp));
    if(q == NULL){
      printf("No more memory space available \n");
      return -1;
    }

    //Read the next data
    num_element =fread(q, sizeof(struct emp), 1, fp);
}
  free(q);  //deallocation for extra memory

  printf("========================================\n");
  printf("Calculated Bi-weekly Pays in Order\n\n");
  printf("Last name, First name  bi-weekly pay  federal tax  state tax  insurance     net pay \n");
  print_emp_data(head_ptr);


  return 0;
}
