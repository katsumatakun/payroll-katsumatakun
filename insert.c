#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked.h"
#include "emp_rec.h"
#include "insert.h"

/*
  This function will accept the head pointer pointing to
  to the pointer to th first node of the linked list
  and a pointer to EmpPtr that points to an employee's information.
  Then the information being pointed by q is going to be stored in a new node
  of the linked List so that the list can have employee's information in decending
  alphabetical order.
*/

nodeType insertData(nodeType head_ptr, EmpPtr q){
  nodeType p;  //points to new node
  nodeType p3; //points to one front node of new node
  nodeType p2; //points to one behind node of new node
  nodeType newHead = head_ptr;



  //dainamically allocation
  //allocation failure will finish function execution
  p = (nodeType) malloc(sizeof(struct linked));
  p->ptr = q;
  if(head_ptr ->ptr == NULL){
      head_ptr ->ptr = p->ptr;
      head_ptr ->front = NULL;
      head_ptr ->back = NULL;
      
    }
  else{
  p2 = head_ptr;
  p3 = NULL;

  //Finding insertion point
  //1. last name 2. if laste name is the same, compare first name.
  while(p2 != NULL && strcmp((p2->ptr)->last_name, (p->ptr)->last_name)<0){
    p3 = p2;
    p2 = p2->back;
  }
  while( p2 != NULL && strcmp((p2->ptr)->last_name, (p->ptr)->last_name) == 0 && strcmp((p2->ptr)->first_name, (p->ptr)-> first_name) < 0){
    p3 = p2;
    p2 = p2->back;
  }

 //insert very first of the linked list
 if (p3 == NULL){
   printf("insert first\n" );
    p2 -> front = p;
    p->front = NULL;
    p->back  = p2;
    newHead = p;
  }
  //insert between node pointed to by p3 and one pointed to by p2
  //(or very end if p2 == NULL)
  else{
    printf("insert somewhere between\n" );
    p3-> back = p;
    p->front = p3;
    p->back = p2;
    if(p2 != NULL){
      p2-> front = p;
    }
  }
}

  return newHead;
}
