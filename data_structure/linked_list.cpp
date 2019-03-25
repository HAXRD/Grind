#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

void traversal(Node* head) {
  while(head!= NULL) {
    cout<<head->data<<"\n";
    head = head->next;
  }
  cout<<"\n";
}

struct Node* insert(Node* head, int pos, int value) {
  // Position counting starts from 0
  Node* target = NULL;
  target = new Node();
  target->data = value;
  
  if (pos == 0) {
    target->next = head;
    head = target;
  }
  else {
    Node* curr = head;
    for (int i = 0; i < pos; i++) {
      curr = curr->next;
in    }
    target->next = curr->next;
    curr->next = target;
  }
  return head;
}


int main() {
  Node* head = NULL;
  Node* second = NULL;
  Node* third = NULL;

  // allocate 3 Nodes in the heap
  head = new Node();
  second = new Node();
  third = new Node();

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  traversal(head);

  head = insert(head, 0, 10);
  traversal(head);

  head = insert(head, 2, 11);
  traversal(head);

  head = insert(head, 4, 12);
  traversal(head);
  
  return 0;
}
  
