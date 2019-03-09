#include <stdio.h>
#include <stdlib.h>
#include "emp_rec.h"
#include "linked.h"
#include "insert.h"
#include "myprint.h"
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

  //Create head pointer to the first node of the linked list
  nodeType head = NULL;
  head = (nodeType) malloc(sizeof(struct linked));
  if(head == NULL){
    printf("No more memory space available \n");
    return -1;
  }

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
  num_element =fread(q, sizeof(struct emp), 1, fp);
  if(num_element != 1){
    printf("Reading data failed \n");
    free(q);
    return -1;
  }

  //Pirnt data it reads and put data into the linked list
  //with dainamically memory allocation.
  //while successfully reading emp data, that is while end of the file
  int is_insertion_success;
  while(num_element == 1){
    print_raw_data(q);

    //Insert data with dainamically allocation
    is_insertion_success = insertData(head, q);
    if(is_insertion_success == -1)
    {
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
  free(q);

  //Print bi-weekly pay, taxes, insuarance, and net pay
  printf("========================================\n");
  printf("Calculated Bi-weekly Pays in Order\n\n");
  printf("Last name, First name  bi-weekly pay  federal tax  state tax  insurance  net pay \n");
  print_emp_data(head);

  //Delete each node of the linked list(deallocation)
  nodeType delete_ptr;
  while(head != NULL){
    delet_ptr = head;
    head = head->back;
    free(delete_ptr);
    }
  return 0;
}
