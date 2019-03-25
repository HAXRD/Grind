#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

void append(Node** head_ref, int value);
void push(Node** head_ref, int value);
void printList(Node* head);

int main() {
  Node* head = NULL;

  append(&head, 6);

  push(&head, 7);

  push(&head, 1);

  append(&head, 4);

  printList(head);
}

void append(Node** head_ref, int value) {
  // Append value at the end of the list
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = NULL;

  // When the list is empty
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  // When the list is not empty, traverse to the end of list
  Node* last = *head_ref;
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}


void push(Node** head_ref, int value) {
  // Push value at the head of the the list
  Node* new_node = new Node();
  new_node->data = value;

  // When the list is empty
  if (*head_ref == NULL) {
    new_node->next = NULL;
    *head_ref = new_node;
    return;
  }

  new_node->next = *head_ref;
  *head_ref = new_node;
  return;
}
void printList(Node* head) {
  while(head != NULL) {
    cout<<head->data<<"\n";
    head = head->next;
  }
}
