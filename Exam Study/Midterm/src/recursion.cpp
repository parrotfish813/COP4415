#include <iostream>

using namespace std;

void countUp(int x) {
    if(x == 0) {
        return;
    }

    countUp(x - 1);

    cout << x << " ";
}

void countDown(int x) {
    if(x == 0) {
        return;
    }

    cout << x << " ";

    countDown(x - 1);

}

int totalSum(int x) {
    if(x == 0) {
        return 0;
    }
    else {
        return (x + totalSum(x - 1));
    }
}

void printReverse(char string[], int n) {
    if(n == 1) {
        cout << string[0];
    }

    else {
        cout << string[n - 1];

        printReverse(string, n - 1);
    }
}

int main() {

    countUp(10);

    cout << "" << endl;

    countDown(10);

    cout << "" << endl;

    cout << totalSum(5) << endl;

    char string[10] = "Hello";
    printReverse(string, 10); 

}