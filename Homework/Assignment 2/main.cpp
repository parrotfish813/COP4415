#include <iostream>
using namespace std;

/*
File Name: main.cpp 
Name: Brandon Townes
Course: COP4415.01
Date: 10/05/2022
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
Node *removeAll(Node *head, int val) {

    Node *prevNode = NULL;

    //Loops through the list and removes all elements with a given value from the list
    while (head->next != NULL) {

        // Checks if the data at his point is equal to the designated value 
        if (head->data == val) {
            if (prevNode != NULL) {
                prevNode->next = head->next;
            } 
            else {
                head = head->next;
            }
        } 
        
        else {
            prevNode = head;
        }
        head = head->next;
    }

    if (head->data == val) {
        prevNode->next = NULL;
    }

    return head;
}

/* Inserts an element at a designated position */
Node *insertToPlace(Node *head, int val, int place) {

    // If the place is to small it just returns the head 
    if (place <= 1) {
        return head;
    }

    Node *temp = new Node();
    temp->data = val;

    // Loops through the list and inserts when it reaches the place designated
    for (int i = 2; i < place; i++) {
        if (head->next == NULL) {
            head->next = temp;
            return head;
        }
        head = head->next;
    }

    temp->next = head->next;
    head->next = temp;
    return head;

}

/* This function prints contents of the list */
void printList(Node *node) {
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {

    // Start with the empty list 
    Node* head = NULL;

    // Insert 7 at the beginning.
    insertBeg(&head, 7);

    // Insert 1 at the beginning.
    insertBeg(&head, 1);

    // Insert 1 at the beginning.
    insertBeg(&head, 6);

    // Insert 10 at the beginning.
    insertBeg(&head, 10);

    // Insert 5 at index 2
    insertToPlace(head, 5, 2);

    // Prints the list
    cout << "Link List: ";
    printList(head);
    cout << " " << endl;

    // Removes all 10's from the list'
    removeAll(head, 1);

    // Prints the list
    cout << "Link List: ";
    printList(head);

}