#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

struct Node* newNode(int data) {
  Node* node = new Node();

  node->data = data;

  node->left = NULL;
  node->right = NULL;

  return node;
}

int main() {
  Node* root = newNode(1);

  root->left = newNode(2);
  root->right = newNode(3);

  root->left->left = newNode(4);

  return 0;
}
