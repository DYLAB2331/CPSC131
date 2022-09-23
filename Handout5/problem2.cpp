#include <iostream>
#include <string>
#include "STACKPAC.h"
using namespace std;

int main() {

    Stack <char, 100> LR;
    Stack <char, 100> RL;
    Stack <char, 100> temp;

    int numPhrases;
    string phrase;
    char c;

    cout << "How many phrases would you like to try? ";

    cin >> numPhrases;

    for (int i = 0; i < numPhrases; i++) {
        cout << "Enter a phrase: ";
        getline(cin, phrase);

        while (cin.get(c), c != '\n') {
            if(isalpha(c)) {
                LR.push(c);
                temp.push(c);
            }
        }

        while (!temp.empty()) {
            char a = temp.pop();
            RL.push(a);
        }
        
        bool isPalindrome = true;

        while (!LR.empty() && isPalindrome) {
            char x = RL.pop();
            char y = LR.pop();

            x = tolower(x);
            y = tolower(y);

            if (x != y) {
                isPalindrome = false;
            }
        }

        if (isPalindrome == true) {
            cout << "The phrase is a palindrome" << endl;
        } else {
            cout << "The phrase is not a palindrome" << endl;
        }
    }
}
