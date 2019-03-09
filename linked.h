/*
  Defining each node and a pointer to the nodes
  of linked list
*/

struct linked {
  struct linked* front;
  struct linked* back;
  struct emp* ptr;
};
typedef struct linked *nodeType;
