#include <iostream>
using namespace std;
// A linked list node
class Node {
	public:
	int data;
	Node *next;
};


void insertBeg(Node** headRef, int newData) {
	/* 1. allocate node */
	Node* newNode = new Node();

	/* 2. put in the data */
	newNode->data = newData;

	/* 3. Make next of new node as head */
	newNode->next = (*headRef);

	/* 4. move the head to point to the new node */
	(*headRef) = newNode;
}

/* Given a node prevNode, insert a new node after the given
prevNode */
void insertAfter(Node* prevNode, int newData) {
	/*1. check if the given prevNode is NULL */
	if (prevNode == NULL)
	{
		cout<<"The given previous node cannot be NULL";
		return;
	}

	/* 2. allocate new node */
	Node* newNode = new Node();

	/* 3. put in the data */
	newNode->data = newData;

	/* 4. Make next of new node as next of prevNode */
	newNode->next = prevNode->next;

	/* 5. move the next of prevNode as newNode */
	prevNode->next = newNode;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void insertLast(Node** headRef, int newData) {
	/* 1. allocate node */
	Node* newNode = new Node();

	Node *last = *headRef; /* used in step 5*/

	/* 2. put in the data */
	newNode->data = newData;

	/* 3. This new node is going to be
	the last node, so make next of
	it as NULL*/
	newNode->next = NULL;

	/* 4. If the Linked List is empty,
	then make the new node as head */
	if (*headRef == NULL)
	{
		*headRef = newNode;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
	{
		last = last->next;
	}

	/* 6. Change the next of last node */
	last->next = newNode;
	return;
}

// This function prints contents of
// linked list starting from head
void printList(Node *node) {
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

/* Main Function*/
int main() {
	/* Start with the empty list */
	Node* head = NULL;
	
	// Insert 6. So linked list becomes 6->NULL
	insertLast(&head, 6);
	
	// Insert 7 at the beginning.
	// So linked list becomes 7->6->NULL
	insertBeg(&head, 7);
	
	// Insert 1 at the beginning.
	// So linked list becomes 1->7->6->NULL
	insertBeg(&head, 1);
	
	// Insert 4 at the end. So
	// linked list becomes 1->7->6->4->NULL
	insertLast(&head, 4);
	
	// Insert 8, after 7. So linked
	// list becomes 1->7->8->6->4->NULL
	insertAfter(head->next, 8);
	
	cout<<"Created Linked list is: ";
	printList(head);
	
	return 0;
}


