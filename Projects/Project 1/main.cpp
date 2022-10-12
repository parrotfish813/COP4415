#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

#define MAX 100

class Stack {
    public:
        int top;
        char exp[MAX]; // Maximum s i z e of Stack
    Stack () {
        top = -1;
    }
    // functions prototypes
    bool push(char item);
    char pop();
    char peek();
    bool isEmpty();
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

char Stack::peek() {
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		char x = exp[top];
		return x;
	}
}

// return precedence of operators
int prec(char c) {

}

// convert i n f i x expression to p o s t f i x expression
string infixToPostfix(string s) {

}

// evaluate p o s t f i x expression
int evaluatePostfix (string exp) {

}


int main () {
    string exp;
    string postfix;
    int evaluation;

    cin >> exp;

    postfix = infixToPostfix(exp);
    cout << postfix << "\n";

    evaluation = evaluatePostfix (postfix);
    cout << evaluation << "\n";

    return 0;
}