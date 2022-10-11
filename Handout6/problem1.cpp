#include <iostream>
using namespace std;

long f(int n) {
    if (n == 1) {
        return 2;
    } else {
        return 2 * f(n-1);
    }
}

int main() {
    
}