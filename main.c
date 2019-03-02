#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emp_rec.h"
#include "linked.h"
#include "insert.h"
#include "myprint.h"
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
		printf("オープンファイル名を指定してください\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[1], "rb")) == NULL ) {
		printf("ファイルオープンエラー\n");
		exit(EXIT_FAILURE);
	}

  q = (EmpPtr) malloc(sizeof(struct emp) * 100);
  num =fread(q, sizeof(struct emp), 100, fp);
  printf("num=%d\n", num);
  //printf("%s\n", q->first_name);

  for (int x = 0; x < num; x++){
    insertData(head, (q+x));
  }
  print_emp_data(head);
  free(q);
  free(head);
  return 0;
}
