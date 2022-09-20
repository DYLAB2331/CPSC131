#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

bool isvowel(char c) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        } else {
            return false;
        }
}

int main() {
    char c;
    int words = 0;
    int upperCount = 0;
    int lowerCount = 0;
    int vowels = 0;
    int my = 0;

    cout << "Enter a sentence: ";

    while (cin.get(c), c != '\n') {
        if (isupper(c)) {
            upperCount++;
        }

        if (islower(c)) {
            lowerCount++;
        }

        if (isspace(c)) {
            words++;
        }

        if (isvowel(c) == true) {
            vowels++;
        }

        if (c == 'M' || c == 'm') {
            if (c+1 == 'Y' || c+1 == 'y') {
                my++;
            }
        }
    }

    cout << left << "Number of words" << setfill('.') << setw(10) << right << words + 1 << endl;
    cout << left << "Number of uppercase letters" << setfill('.') << setw(10) << right << upperCount << endl;
    cout << left << "Number of lowercase letters" << setfill('.') << setw(10) << right << lowerCount << endl;
    cout << left << "Number of vowels" << setfill('.') << setw(10) << right << vowels << endl;
    cout << left << "Number of substring MY" << setfill('.') << setw(10) << right << my << endl;

    system("Pause");
    return 0;
}