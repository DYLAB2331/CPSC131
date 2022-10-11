#include <iostream>
#include <ctime>
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

long Fib(int n) {
    long f0 = 0;
    long f1 = 1;
    long fn;

    for (int i = 2; i <= n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }

    return fn;
}

int main() {
   int startNum, start, end;
   cin >> startNum;  

   start = clock();
   cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;
   end = clock();

   cout << "Runtime: " << (end - start) / 1000 << endl;

   start = clock();
   cout << Fib(43) << endl;
   end = clock();

   cout << "Runtime: " << (end - start) / 1000 << endl;

   return 0;
}
