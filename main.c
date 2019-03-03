#include <stdio.h>
#include <stdlib.h>
#include "emp_rec.h"
#include "linked.h"
#include "insert.h"
#include "myprint.h"
#include "delete_list.h"
typedef struct emp *EmpPtr;
typedef struct linked *nodeType;

/*
  This program reads a structured binary file of eployee records
  that is unsorted and print out each employee's bi-weekly net pay
  and total payment in descending alphabetical order.
*/
int main(int argc, char* argv[]) {
  int num;
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


  while(num != 0){
  q = (EmpPtr) malloc(sizeof(struct emp));
  num =fread(q, sizeof(struct emp), 1, fp);
  //printf("%d\n", num);
  insertData(head, (q));
}


  print_emp_data(head);
  free(q);
  delete_list(head);
  return 0;
}
