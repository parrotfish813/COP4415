#include <iostream>
using namespace std;

#define MAX 100
class Stack {
    public:
        int top;
        char exp[MAX];

    Stack() { top = -1; }
// functions prototypes
    bool push(char item);
    char pop();
};

bool Stack::push(char item) {
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

char Stack::pop() {
    if(top == -1) {
        cout<< "stack underflow";
        return 0;
    }

    else {
        int x = exp[top];

        top--;

        return x;
	}

}

int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') {
		return 1;
    }

	else if (character1 == '{' && character2 == '}') {
		return 1;
    }

	else if (character1 == '[' && character2 == ']') {
		return 1;
    }

	else {
		return 0;
    }
}

int areParenthesisBalanced(char exp[]) {
	int i = 0;

    Stack* s = new Stack();

	while (exp[i]) {
		
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
		    s-> push(exp[i]);

		
		if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {

			if (s->top == -1)
				return 0;

		
		else if (!isMatchingPair(s->pop(), exp[i]))
		    return 0;
		}
		i++;
    }
    return 1;
}

int main() {

    char exp[MAX];

    cout << "enter the expression:\n";
    cin >> exp;

    if (areParenthesisBalanced(exp)){
        cout << "Balanced" << endl;
    }

    else {
        cout << "Not Balanced" << endl;
    }
    
    return 0;

}
