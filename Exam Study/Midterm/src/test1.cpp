#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define MAX 100

class Stack {
  public:
    int top;
    char exp[MAX];
    
  Stack(){
      top = -1;
    }
  bool push(char item);
  char pop();
};

bool Stack::push(char item) {
  if(top >= MAX - 1) {
    cout << "Stack Overflow" << endl;
    return false;
  }

  else {
    top++;
    exp[top] = item;
    return true;
  }
}

char Stack::pop() {
  if(top == MAX -1){
    cout << "Stack Overflow" << endl;
    return 0;
  }
   else {
     char x = exp[top];
    top--;
    return x;
  }
}

int isMatchingPair(char character1, char charecter2) {
  if(character1 == '(' && charecter2 == ')') {
      return 1;
  }
  else if(character1 == '[' && charecter2 == ']') {
      return 1;
  }
  else if(character1 == '{' && charecter2 == '}') {
      return 1;
  }
  else {
    return 0;
  }
}

int areParenthesisBalended(char exp[]) {
  Stack* s = new Stack();
  int i = 0;

  while(exp[i]) {
    if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
      s-> push(exp[i]);
    }
    if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
      if(s->top == -1) {
        return 0;
      }
      else if(!isMatchingPair(s->pop(), exp[i])) {
        return 0;
      }
    }
    i++;
  }

  if(s->top == -1) {
    return 1;
  }
  else {
    return 0;
  }
}

int main() {
  char exp[MAX];

  cout << "Enter the expresion: ";
  cin >> exp;

  if(areParenthesisBalended(exp)) {
    cout << "Balenced" << endl;
  }
  else {
    cout << "Not balenced" << endl;
  }

  return 0;
}