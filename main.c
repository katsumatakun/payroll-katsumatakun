#include <stdio.h>
#include <stdlib.h>
#include "emp_rec.h"
#include "linked.h"
#include "insert.h"
#include "myprint.h"
#include "delete_list.h"
typedef struct emp *EmpPtr;
typedef struct linked *nodeType;

int main(int argc, char* argv[]) {
  int num = 1;
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

  q = (EmpPtr) malloc(sizeof(struct emp) * 100);
  num =fread(q, sizeof(struct emp), 100, fp);
  for (int x = 0; x < num; x++){
    insertData(head, (q+x));
  }
  print_emp_data(head);
  free(q);
  delete_list(head);
  return 0;
}
