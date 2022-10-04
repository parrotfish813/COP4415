#include <iostream>
using namespace std;

/*
File Name: main.cpp 
Name: Brandon Townes
Course: COP4415.01
Date: 09/26/2022
*/

/* Creation of the Node object */
class Node {
    public:
        int data;
        Node *next;
        Node* prev; 
};

/* Inserts an element at the beginning */
void insertBeg(Node** headRef, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

/* Removes all elements with a given value from a linked list with the given head */
Node* removeAll(Node* head, int val) {

       // In Linked List is empty Just return it
    if(!head) {
        return head;
    }

    while (head && head->data == val) {
        head = head->next;
    }

    Node *curr = head, *prev = nullptr;
        
    while (curr) {
        
        if (curr->data == val) {
            prev->next = curr->next;
        }
        else {
            prev = curr;
        }
        
        curr = curr->next;
    }
    return head;

}

/* Inserts an element at a designated position */
Node* insertToPlace(Node* head, int val, int place) {

    if(head == NULL || place <= 1) {
        return head;
    }

    else {
        Node *temp = head;

        for(int i = 0; i <= place; i++) {
            
        }
        return head;
    }
}

/* This function prints contents of the list */
void printList(Node *node) {
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {

    /* Start with the empty list */
    Node* head = NULL;

    // Insert 7 at the beginning.
    insertBeg(&head, 7);

    // Insert 1 at the beginning.
    insertBeg(&head, 1);
    insertBeg(&head, 10);

    // Insert 10 at index 2
    insertToPlace(head, 10, 2);

    // Removes all 10's from the list'
    removeAll(head, 10);

    // Prints the list
    cout << "Link List: ";
    printList(head);

}