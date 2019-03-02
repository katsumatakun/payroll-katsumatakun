#include <stdio.h>
#include <stdlib.h>
#include "emp_rec.h"
typedef struct emp *EmpPtr;
int main(int argc, char* argv[]) {

  EmpPtr ptr;
  FILE *fp;
	if (argc != 2) {
		printf("オープンファイル名を指定してください\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[1], "rb")) == NULL ) {
		printf("ファイルオープンエラー\n");
		exit(EXIT_FAILURE);
	}

  ptr = (EmpPtr) malloc(sizeof(struct emp) * 10);

  int num =fread(ptr, sizeof(struct emp), 10, fp);


  ptr[num] = '\0';
  printf("fread:%d - %s\n", num, ptr);

  




  return 0;
}
