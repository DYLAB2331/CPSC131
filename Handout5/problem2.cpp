#include <iostream>
#include <string>
#include "STACKPAC.h"
using namespace std;

void isPal(string line) {

    Stack <char, 80> LR;
    Stack <char, 80> RL;
    Stack <char, 80> temp;

    LR.clear();
    RL.clear();
    temp.clear();

    for (int i = 0; i < line.length(); i++) {
        if (isalpha(line.at(i))) {
            LR.push(line.at(i));
            temp.push(line.at(i));
        }
    }

    while (!temp.empty()) {
        char c = temp.pop();
        RL.push(c);
    }

    bool isPal = true;

    while (!LR.empty() && isPal) {
        char x = LR.pop();
        char y = RL.pop();

        x = tolower(x);
        y = tolower(y);

        if (x != y) {
            isPal = false;
        }
    }

    if (isPal == true) {
        cout << "The phrase is a palindrome" << endl;
    } else if (isPal == false) {
        cout << "The phrase is not a palindrome" << endl;
    }
}

int main() {

    string num;
    string phrase;

    cout << "How many phrases would you like to try? ";

    getline(cin, num);
    int n = stoi(num);

    for (int i = 0; i < n; i++) {
        cout << "Enter a phrase: ";

        getline(cin, phrase);
        isPal(phrase);
    }

    return 0;

}