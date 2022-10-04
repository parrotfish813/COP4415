#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

void printList(Node *node) {
    while(node != NULL) {
        std::cout << " " << node->data;
        node = node->next;
    }
}

void insertBeg(Node** headRef, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

void insertAfter(Node* prevNode, int newData) {
    if(prevNode == NULL) {
        std::cout<<"The spot is NULL" << std::endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;

}

void insertLast(Node** headRef, int newData) {
    Node* newNode = new Node();

    Node *last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;

    if(*headRef == NULL) {
        last->next = newNode;
        return;
    }

    while(last->next != NULL) {
        last = last->next;
    }


}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
