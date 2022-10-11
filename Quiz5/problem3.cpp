#include <iostream>
using namespace std;

int cubeSum(int n) {
    if (n < 3) {
        return 0;
    } else {
        return (n * n * n) + cubeSum(n - 1);
    }
}

int main() {
    int number;
    cout << "Enter a number" << endl;
    cin >> number;
    cout << cubeSum(number) << endl;
}