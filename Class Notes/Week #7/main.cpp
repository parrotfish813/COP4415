#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Node {
  public:
    int data;
    Node * next;
    Node * item;
};

Node* insert(Node* head, int item) {
  if (head == NULL || item <= head -> data) {
    Node* newNode = new Node();
    newNode -> item;
    newNode -> next = head;
    return newNode;
  }

  head -> next = insert(head -> next, item);
  return head;
}

void del(Node head, int item) {

}

void print(Node *list) {
  if (list != NULL) {
    cout << list -> data;
    print (list -> next);
  }
}

int main() {
  std::cout << "Hello World!\n";
}