#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"
#include "emp_rec.h"
#include "insert.h"
//typedef struct emp *EmpPtr;
//typedef struct linked *nodeType;

/*
  This function will accept a pointer of nodeType that is the head of a linked list
  and a pointer of EmpPtr that points to an employee's information.
  Then the information being pointed by q is going to be stored in a node
  of the linked List so that the list can have employee's information in decending
  alphabetical order.
*/
void insertData(nodeType head, EmpPtr q){
  //printf("aaaa %s\n", q->first_name);
  nodeType p;
  nodeType p3;
  nodeType p2;
  if((head->ptr) == NULL){
    head->front = NULL;
    head->back = NULL;
    head->ptr = q;
    //printf("insert first item %s\n", (head->ptr)->last_name);
  }

  else{
    p = (nodeType) malloc(sizeof(struct linked));
    p->ptr = q;
    p2 = head;
    while(p2 != NULL && strcmp((p2->ptr)->last_name, (p->ptr)->last_name)<0){
      p3 = p2;
      p2 = p2->back;
    }
    while( p2 != NULL && strcmp((p2->ptr)->last_name, (p->ptr)->last_name) == 0 && strcmp((p2->ptr)->first_name, (p->ptr)-> first_name) < 0){
      p3 = p2;
      p2 = p2->back;
    }
    if(p2 == NULL){
      //printf("insert %s after %s\n", p->ptr->last_name, p3->ptr->last_name);
      p3-> back = p;
      p-> back = NULL;
      p-> front = p3;
    }

    else if (p3 == NULL){
      //printf("inset %s before %s\n", p->ptr->last_name, p2->ptr->last_name);
      p2-> front = p;
      p->front = NULL;
      p->back  = p2;
    }

    else{
      //printf("insert %s between %s and %s\n",p->ptr->last_name, p3->ptr->last_name, p2->ptr->last_name );
      p3-> back = p;
      p2-> front = p;
      p->front = p3;
      p->back = p2;
    }
  }
}
