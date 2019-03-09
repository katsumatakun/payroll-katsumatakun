#include <stdio.h>
#include <stdlib.h>
#include "emp_rec.h"
#include "linked.h"
#include "insert.h"
#include "myprint.h"
#include "print_rawdata.h"
//typedef struct emp *EmpPtr;
//typedef struct linked *nodeType;

/*
  This program reads a structured binary file of eployee records
  that is unsorted and first print out all of the data for
  each employee and then print out employee's bi-weekly net pay
  and total payment in descending alphabetical order.
*/
int main(int argc, char* argv[]) {
  nodeType head = NULL;
  head = (nodeType) malloc(sizeof(struct linked));
  if(head == NULL){
    return -1;
  }

  EmpPtr q;
  FILE *fp;
	if (argc != 2) {
		printf("usage: progam name, binary file name\n");
		return -1;
	}

	if((fp = fopen(argv[1], "rb")) == NULL ) {
		printf("Input file not open\n");
		return -1;
	}
  int num_element;
  q = (EmpPtr) malloc(sizeof(struct emp));
  num_element =fread(q, sizeof(struct emp), 1, fp);

  while(num_element == 1){
    print_raw_data(q);
    insertData(head, q);
    q = (EmpPtr) malloc(sizeof(struct emp));
    num_element =fread(q, sizeof(struct emp), 1, fp);
}
  free(q);

  printf("========================================\n");
  printf("Calculated Bi-weekly Pays in Order\n\n");
  print_emp_data(head);

  nodeType iterator;
  while(head != NULL){
    iterator = head;
    head = head->back;
    free(iterator);
    }
  return 0;
}
