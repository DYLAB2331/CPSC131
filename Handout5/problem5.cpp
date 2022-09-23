#include <iostream>
#include <string>
#include "STACKPAC.h"
using namespace std;

int randNum() {
    srand(time(NULL));

    return rand() % 31;
}

char randChar() {
    srand(time(NULL));

    int n = rand() % 26;

    return char(65 + n);
}

string randMonth() {
    string months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUL", "JUN", "AUG", "SEP", "OCT", "NOV", "DEC"};

    srand(time(NULL));

    int n = rand() % 13;

    string month = months[n];

    return month;
}

int main() {

    Stack <int, 10> num;
    Stack <char, 10> alpha;
    Stack <string, 10> months;

    for (int i = 0; i < 11; i++) {
        num.push(randNum());
    }

    for (int i = 0; i < 11; i++) {
        alpha.push(randChar());
    }

    for (int i = 0; i < 11; i++) {
        months.push(randMonth());
    }

    cout << "Numbers: ";

    while(!num.empty()) {
        int x = num.pop();
        cout << x << " ";
    }

    cout << endl;
    cout << "Uppercase letters: ";

    while(!alpha.empty()) {
        char y = alpha.pop();
        cout << y << " ";
    }

    cout << endl;
    cout << "Months: ";

    while(!months.empty()) {
        string z = months.pop();
        cout << z << " ";
    }

    return 0;
}