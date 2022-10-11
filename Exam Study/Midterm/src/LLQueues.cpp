#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

struct Queue {
	
	Node *front, *rear;
	Queue()
	{
		front = rear = NULL;
	}

	void enQueue(int x)
	{
    Node* newNode = new Node(x);


    if (rear == NULL)
    {
      front = rear = newNode;
      return;
    }

    rear->next = newNode;

    rear = newNode;
		
	}

	// Function to remove
	// from the front
	void deQueue()
	{
    if(front == NULL)
      return;

    Node* temp = front;
    front = front->next;

    if(front == NULL)
      rear = NULL;


    delete temp;
    
	}
};

void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data<< "->" ;
		node = node->next;
	}

  		cout<<" NULL\n" ;

}

int main()
{

	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
  printList(q.front);
	cout << "Queue Front : " << (q.front)->data << endl;
	cout << "Queue Rear : " << (q.rear)->data;
}

