#include "linked.h"
#include "emp_rec.h"
#include "insert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct emp *EmpPtr;
typedef struct linked *nodeType;
void insertData(nodeType pt, EmpPtr q){
  printf("aaaa" );
  nodeType p;
  nodeType p3;
  nodeType p2;
  printf("bbbb");
  p = (nodeType) malloc(sizeof(struct linked));
  p3 = (nodeType) malloc(sizeof(struct linked));
  p2 = (nodeType) malloc(sizeof(struct linked));
  p->ptr = q;  //q+x
  if(pt == NULL){
    p->front = NULL;
    p->back = NULL;
    pt = p;
  }
  else{
    p2 = pt;
    while(strcmp((p2->ptr)->last_name, (p->ptr)->last_name)<0){
      p2 = p2->back;
    }
    while(strcmp((p2->ptr)->first_name, (p->ptr)-> first_name) < 0){
      p2 = p2->back;
    }

    p3 = p2->front;
    p3->back = p;
    p2->front = p;
    p->front = p3;
    p->back = p2;

  }

  free(p);
  free(p2);
  free(p3);
}
