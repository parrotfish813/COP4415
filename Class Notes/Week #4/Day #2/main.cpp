#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

void insertAfter(Node* prevNode, int newData) {
    if(prevNode == NULL) {
        std::cout << "The given previous node cannot be NULL" << std::endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;

    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if(newNode->next != NULL){
        newNode->next->prev = newNode;
    }

}

// This function prints contents of
// linked list starting from head
void printList(Node *node)
{
    while (node != NULL)
    {
        std::cout<<" "<<node->data;
        node = node->next;
    }
}

/* Main Function*/
int main() {
    /* Start with the empty list */
    Node* head = NULL;

    insertAfter(head->next, 8);
    std::cout<<"Created Linked list is: ";
    printList(head);

    return 0;
}
