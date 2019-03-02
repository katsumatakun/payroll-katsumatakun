#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emp_rec.h"
typedef struct emp *EmpPtr;
struct linked {
  struct linked* front;
  struct linked* back;
  EmpPtr ptr;
};
typedef struct linked *nodeType;

int main(int argc, char* argv[]) {
  int num = 1;
  nodeType p;
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
  printf("%d\n", num);
  for (int i = 0; i < num; i++)
  printf("fread: %s %s %s \n", (q+i) -> first_name, (q+i)->last_name, (q+i)-> addr);

  //printf("%d\n",strcmp(q -> first_name, (q+1) -> first_name));

  p = (nodeType) malloc(sizeof(struct linked));
  p->ptr = q;
  (p->front) = NULL;
  (p->back) = NULL;
  for (int i = 0; i < num-1; i++){
  nodeType pt = (nodeType) malloc(sizeof(struct linked));
  (p->back) = pt;
  (pt->front) = p;
  q = q+1;
  (pt->ptr) = q;
  printf("%s\n", (pt->ptr)->first_name);
  (pt->back) = NULL;
  free(pt);
}
  free(q);
  free(p);
  return 0;
}
