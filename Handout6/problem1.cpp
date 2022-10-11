#include <iostream>
#include <ctime>
using namespace std;

// Runtime is O()

long f(int n) {
    if (n == 1) {
        return 2;
    } else {
        return 2 * f(n-1);
    }
}

int main() {
    double start, end;

    start = clock();

    cout << f(15) << endl;

    end = clock();

    cout << "Runtime: " << (end - start) / 1000 << endl;

    system("pause");

    return 0;

}