#include <iostream>
#include <string>
#include <ctime>
#include "STACKPAC.h"
using namespace std;

int main() {
    srand(time(NULL));
    Stack <int, 10> num;
    Stack <char, 10> alpha;
    Stack <string, 10> months;

    num.clear(); alpha.clear(); months.clear();
    string monthsArr[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUL", "JUN", "AUG", "SEP", "OCT", "NOV", "DEC"};

    cout << "Numbers: ";
    for (int i = 0; i < 10; i++) {
        int n = (rand() % 31);
        
        num.push(n);
        int x = num.pop();
        cout << x << " ";
    }
    cout << endl;

    cout << "Uppercase letters: ";
    for (int i = 0; i < 10; i++) {
        int a = (rand() % 26);
        char c = char(65 + a);
        alpha.push(c);
        char y = alpha.pop();
        cout << y << " ";
    }
    cout << endl;

    cout << "Months: ";
    for (int i = 0; i < 10; i++) {
        int m = rand() % 13;

        string month = monthsArr[m];
        months.push(month);
        string z = months.pop();
        cout << z << " ";
    }
}