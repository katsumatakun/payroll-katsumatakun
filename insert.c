#include <stdlib.h>
#include <string.h>
#include "linked.h"
#include "emp_rec.h"
#include "insert.h"

/*
  This function will accept the head pointer pointing to
  the first node of the linked list
  and a pointer to EmpPtr that points to an employee's information.
  Then the information being pointed by q is going to be stored in a new node
  of the linked List so that the list can have employee's information in decending
  alphabetical order.
  Finally return the pointer to the new head node after sorting.
*/

nodeType insertData(nodeType head_ptr, EmpPtr q){
  nodeType p;  //points to new node
  nodeType p3; //points to one front node of new node
  nodeType p2; //points to one behind node of new node
  nodeType newHead = head_ptr; //pointer to be returned

  //dainamically allocation
  //allocation failure will finish function execution with null return
  p = (nodeType) malloc(sizeof(struct linked));
  if(p == NULL){
    newHead = NULL;
    return newHead;
  }

  p->ptr = q;
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
    p->front = NULL;
    p->back  = p2;
    newHead = p;
    if(p2 != NULL){
      p2 -> front = p;
    }
  }

  //insert between node pointed to by p3 and one pointed to by p2
  //(or very end if p2 == NULL)
  else{
    p3-> back = p;
    p->front = p3;
    p->back = p2;
    if(p2 != NULL){
      p2-> front = p;
    }
}

  return newHead;
}
