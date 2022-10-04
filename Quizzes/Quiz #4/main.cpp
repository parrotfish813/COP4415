#include <iostream>

using namespace std;

int power(int base, int exponent) {

    if(exponent == 0) {
        return 1;
    }
    else {
        return (base * power(base, exponent - 1));
    }
}

int crazySum(int n) {

    if(n == 1) {
        return 1;
    }
    else {
        return crazySum(n-1) + power(n, n);
    }

}

int main() {

    int n;

    cout << "Please enter a number: " << endl;
    cin >> n;

    cout << crazySum(n) << endl;
    
}