#include <iostream>
using namespace std;

int Fibonacci(int n) {

    int num1 = 0;
    int num2 = 1;
    int nextNum;

    if (n == 0) {
        return num1;
    } else if (n == 1) {
        return num2;
    } else if (n < 0) {
        return -1;
    }

    for (int i = 0; i < n - 1; i++) {
        nextNum = num1 + num2;
        num1 = num2;
        num2 = nextNum;
    }
    
    return nextNum;

}

int main() {
   int startNum;
   
   cin >> startNum;  
   cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;
   
   return 0;
}
