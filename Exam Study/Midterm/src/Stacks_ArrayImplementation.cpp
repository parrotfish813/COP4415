// Array implementation of stack functions
#include <iostream>

using namespace std;

#define MAX 100

class Stack {
	int top;
public:
	int a[MAX]; // Maximum size of Stack

	Stack() { top = -1; }

  // functions prototypes
	bool push(int item);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int item) {
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
    	top++;
		a[top] = item;
		cout << item << " is successfully pushed into stack\n";
		return true;
	}
}

int Stack::pop()
{
  if(top == -1)
  {
    cout<< "stack underflow";
    return 0;

  }

  else {
    int x = a[top];

    top--;

    return x;
	}

}



int Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

int main()
{
	class Stack s;
	s.push(4);
	s.push(5);
	s.push(6);
	cout << s.pop() << " is successfully popped from stack\n";

	cout<<"Elements present in stack : ";
	while(!s.isEmpty()) {
		// print top element in stack
		cout<<s.pop()<<" ";
		// remove top element in stack
		// s.pop();
	}

	return 0;
}