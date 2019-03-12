#include <stdlib.h>
#include <string.h>
#include "node.h"
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

nodePtr insertData(nodePtr head_ptr, EmpPtr q){
  nodePtr new_node_p;
  nodePtr front_node_p;
  nodePtr behind_node_p;
  nodePtr new_Head_p = head_ptr;

  //allocation failure will finish function execution with null return
  new_node_p = (nodePtr) malloc(sizeof(struct node));
  if(new_node_p == NULL){
    new_Head_p = NULL;
    return new_Head_p;
  }

  new_node_p->ptr = q;
  behind_node_p = head_ptr;
  front_node_p = NULL;

  //Finding insertion point
  //1. last name 2. if laste name is the same, compare first name.
  while(behind_node_p != NULL && strcmp((behind_node_p->ptr)->last_name, (new_node_p->ptr)->last_name)<0){
    front_node_p = behind_node_p;
    behind_node_p = behind_node_p->back;
  }
  while( behind_node_p != NULL && strcmp((behind_node_p->ptr)->last_name, (new_node_p->ptr)->last_name) == 0 && strcmp((behind_node_p->ptr)->first_name, (new_node_p->ptr)-> first_name) < 0){
    front_node_p = behind_node_p;
    behind_node_p = behind_node_p->back;
  }

 //insert very first of the linked list
 if (front_node_p == NULL){
    new_node_p->front = NULL;
    new_node_p->back  = behind_node_p;
    new_Head_p = new_node_p;
    if(behind_node_p != NULL){
      behind_node_p -> front = new_node_p;
    }
  }

  //insert between node pointed to by front_node_p and one pointed to by behind_node_p
  //(or very end if behind_node_p == NULL)
  else{
    front_node_p-> back = new_node_p;
    new_node_p->front = front_node_p;
    new_node_p->back = behind_node_p;
    if(behind_node_p != NULL){
      behind_node_p-> front = new_node_p;
    }
}

  return new_Head_p;
}
