/*
  Defining each node and a pointer to the nodes
  of Linked list
*/

struct node {
  struct node* front;
  struct node* back;
  struct emp* ptr;
};
typedef struct node *nodePtr;
