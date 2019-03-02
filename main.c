#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emp_rec.h"
#include "linked.h"
#include "insert.h"
typedef struct emp *EmpPtr;
typedef struct linked *nodeType;

int main(int argc, char* argv[]) {
  int num = 1;

  nodeType pt = NULL;
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

  for (int x = 0; x < num; x++){
    insertData(pt, (q+x));
  }
  free(q);
  nodeType iterator = (nodeType) malloc(sizeof(struct linked));
  iterator = pt;
  for (int i = 0; i < num; i++)
    {
      printf("fread: %s %s %s \n", (iterator->ptr)-> first_name, (iterator->ptr)->last_name, (iterator->ptr)->addr);
    }
  return 0;
}



/*p = (nodeType) malloc(sizeof(struct linked)*100);
num =fread(p, sizeof(struct linked), 100, fp);
for (int i = 0; i < num; i++)
printf("fread: %s %s %s \n", ((p+i)->ptr)->first_name, ((p+i)->ptr)->last_name, ((p+i)->ptr)->addr);*/



//printf("%d\n",strcmp(q -> first_name, (q+1) -> first_name));
