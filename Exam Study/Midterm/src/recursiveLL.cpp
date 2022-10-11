//This code shows performing various operations on linked list recursively.
// insert, delete, display,
#include<stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

class Node {
  public:
  int data;
  Node  *next; 

  Node* insert(Node* list,int d );
  Node* del(Node* list,int d );
  void print(Node *list);
};


// Recursively inserts item into the LL pointed to by list.
Node* insert(Node* head, int item) {

    // Node is at front, insert and return.
    if (head == NULL || item <= head->data) {
        Node* newNode = new Node();
        newNode->data = item;
        newNode->next = head;
        return newNode;
    }

    // Recursively insert and return the front of the list.
    head->next = insert(head->next, item);
    return head;
}

// Recursively deletes the first node storing item in the list pointed to
// by list. If no such node exists, no changes are made. a pointer to the front
// of the resulting list is returned.
Node* del(Node *head, int item) {

    // Simple case.
    if (head == NULL)
        return NULL;

    // delete this node and return a pointer to the rest of the list.
    if (head->data == item) {
        Node* rest = head->next;
        delete head;
        return rest;
    }

    // Recursively delete and return the front of the list.
    head->next = del(head->next, item);
    return head;
}

void print(Node *list) {

    // Iterate through each item and print it!
    if(list!=NULL) {
        cout<<"->"<<list->data;
        print(list->next);
    }
}


// Testing the functions
int main( ) {

    int number = 0, choice=0;
    Node *myList = NULL;

    // Let the user add values until they enter -1.
    while(choice!= 3)
    {
        // Get the operation.
        cout<<"\nDo you want to (1)insert, (2)delete,  (3)quit.\n";
        cin>>choice;

        cout<<"Your choice is "<< choice<< endl;

        // Execute the operation.
        if (choice == 1)
        {
           // Get the number.
            cout<<"Enter the value to insert\n";
            cin>> number;
            myList = insert(myList, number);
                    // Look at the list.
            cout<<"Items in linked list: ";
            print(myList);
        }
        else if (choice == 2)
        {    // Get the number.
            cout<<"Enter the value to delete.\n";
            cin>>number;
            myList = del(myList, number);
                    // Look at the list.
            cout<<"Items in linked list: ";
            print(myList);
        }
        
        else
        {
              break;

        }

    }
   
     cout<<"\nBye..\n";
    return 0;
}

