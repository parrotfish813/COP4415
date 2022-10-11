#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
#define MAX 100

// structure of a stack node
class Stack {
public:
	int top;
	char exp[MAX]; // Maximum size of Stack

	Stack() { top = -1; }

  // functions prototypes
	bool push(char item);
	char pop();
};

bool Stack::push(char item)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
    top++;
		exp[top] = item;
		return true;
	}
}

char Stack::pop()
{
  if(top == -1)
  {
    cout<< "stack underflow";
    return 0;

  }

  else
  {
    char x = exp[top];

    top--;

    return x;
  }

}





// Returns 1 if character1 and character2 are matching left
// and right Brackets
int isMatchingPair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}

// Return 1 if expression has balanced Brackets
int areParenthesisBalanced(char exp[])
{
	int i = 0;

	// Declare an empty character stack
  Stack* s =new Stack() ;

	// Traverse the given expression to check matching
	// brackets
	while (exp[i])
	{
		
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
		  s-> push(exp[i]);

		
		if (exp[i] == '}' || exp[i] == ')'
			|| exp[i] == ']') {

			if (s->top == -1)
				return 0;

		
			else if (!isMatchingPair(s->pop(), exp[i]))
				return 0;
		}
		i++;
	}

	// If there is something left in the stack
	// it means there is a starting bracket without a closing
	// bracket -> not balanced
	if (s->top == -1)
		return 1; 
	else
		return 0;
}




int main()
{
  char exp[100];
  cout<<"enter the expression:\n";
  cin>>exp;

	// Function call
	if (areParenthesisBalanced(exp))
		cout<<"Balanced";
	else
		cout<<"Not Balanced";
	return 0;
}

