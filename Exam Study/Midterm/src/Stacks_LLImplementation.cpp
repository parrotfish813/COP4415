// C++ program to Implement a stack
//using singly linked list
#include <iostream>
using namespace std;

// Declare linked list node

struct Node
{
	int data;
	Node* next;
};

Node* top;

// Utility function to add an element
// data in the stack insert at the beginning
void push(int data)
{
	
	// Create new node temp and allocate memory in heap
	Node* temp = new Node();

	if (!temp)
	{
		cout << "\nStack Overflow";
		exit(1);
	}

	// Initialize data into temp data field
	temp->data = data;

	// Put top pointer reference into temp next
	temp->next = top;

	// Make temp as top of Stack
	top = temp;
}

// Utility function to check if
// the stack is empty or not
int isEmpty()
{
	//If top is NULL it means that
	//there are no elements are in stack
	return top == NULL;
}

// Utility function to return top element in a stack
int peek()
{
	
	// If stack is not empty , return the top element
	if (!isEmpty())
		return top->data;
	else
		exit(1);
}

// Utility function to pop top
// element from the stack
void pop()
{
	Node* temp;

	// Check for stack underflow
	if (top == NULL)
	{
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else {
		
		temp = top;

		top = top->next;

		free(temp);
	}
}

void printList()
{
	Node* temp;


	// Check for stack underflow
	if (top == NULL)
	{
		cout << "\nStack Underflow";
		exit(1);
	}
	else
	{
		temp = top;
		while (temp != NULL)
		{

			// Print node data
			cout << temp->data << "-> ";

			// Assign temp link to temp
			temp = temp->next;
		}
	}
}

// Driver Code
int main()
{
	
	// Push the elements of stack
	push(11);
	push(22);
	push(33);
	push(44);

	// Display stack elements
	printList();

	// Print top element of stack
	cout << "\nTop element is "
		<< peek() << endl;

	// Delete top elements of stack
	pop();
	pop();

	// Display stack elements
	printList();

	// Print top element of stack
	cout << "\nTop element is "
		<< peek() << endl;
		
	return 0;
}
