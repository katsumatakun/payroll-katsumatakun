#include "linked.h"
#include "emp_rec.h"
#include "insert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct emp *EmpPtr;
typedef struct linked *nodeType;
void insertData(nodeType head, EmpPtr q){
  //printf("aaaa %s\n", q->first_name);
  nodeType p;
  nodeType p3;
  nodeType p2;
  if((head->ptr) == NULL){
    /*head = (nodeType) malloc(sizeof(struct linked));
    if(head == NULL){
      return;
    }*/
    head->front = NULL;
    head->back = NULL;
    head->ptr = q;
    printf("aaaa %s\n", (head->ptr)->last_name);

  }
  else{
    p = (nodeType) malloc(sizeof(struct linked));
    //p3 = (nodeType) malloc(sizeof(struct linked));
    //p2 = (nodeType) malloc(sizeof(struct linked));
    p->ptr = q;  //q+x
    p2 = head;
    while(p2 != NULL && strcmp((p2->ptr)->last_name, (p->ptr)->last_name)<0){
      //printf("%s vs %s\n", (p2->ptr)->last_name, (p->ptr)->last_name);
      p3 = p2;
      p2 = p2->back;
    }
      while( p2 != NULL && strcmp((p2->ptr)->last_name, (p->ptr)->last_name) == 0 && strcmp((p2->ptr)->first_name, (p->ptr)-> first_name) < 0){
        p3 = p2;
        p2 = p2->back;
    }
    if(p2 == NULL){
      printf("insert %s after %s\n", p->ptr->last_name, p3->ptr->last_name);
      //p3-> back = (nodeType) malloc(sizeof(struct linked));
      p3-> back = p;
      p-> back = NULL;
      //p-> front = (nodeType) malloc(sizeof(struct linked));
      p-> front = p3;
    }

    else if (p3 == NULL){
      printf("inset %s before %s\n", p->ptr->last_name, p2->ptr->last_name);
      //p2->front = (nodeType) malloc(sizeof(struct linked));
      p2-> front = p;
      p->front = NULL;
      //p->back = (nodeType) malloc(sizeof(struct linked));
      p->back  = p2;
    }

    else{
      printf("insert %s between %s and %s\n",p->ptr->last_name, p3->ptr->last_name, p2->ptr->last_name );
      p3-> back = p;
      p2-> front = p;
      p->front = p3;
      p->back = p2;
    }
  }
}
  
