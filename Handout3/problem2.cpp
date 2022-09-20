#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    char firstLetter, secondLetter, thirdLetter, fourthLetter, fifthLetter;
    int n1, n2, n3, n4, n5;

    cout << "Enter a university name: ";

    getline(cin, name, '\n');

    while (name != "n") {
        int n = name.find("of");

        if (n != -1) {
        name.erase(n, 3);
        }

        n1 = name.find(' ');
        if (n1 == -1) { // One word
            name[0] = toupper(name[0]);

            cout << name[0] << endl;
            cout << "Enter another university name or press n to exit " << endl;
            getline(cin, name, '\n');
        } else {
            n2 = name.find(' ', n1 + 1);
            if (n2 == -1) { // Two words
                firstLetter = toupper(name[0]);
                secondLetter = toupper(name[n1 + 1]);

                cout << name << " or " << firstLetter << secondLetter << endl;
                cout << "Enter another university name or press n to exit " << endl;
                getline(cin, name, '\n');
            } else {
                n3 = name.find(' ', n2 + 1);
                if (n3 == -1) { // Three words
                    firstLetter = toupper(name[0]);
                    secondLetter = toupper(name[n1 + 1]);
                    thirdLetter = toupper(name[n2 + 1]);

                    cout << name << " or " << firstLetter << secondLetter << thirdLetter << endl;
                    cout << "Enter another university name or press n to exit " << endl;
                    getline(cin, name, '\n');
                } else {
                    n4 = name.find(' ', n3 + 1);
                    if (n4 == -1) { // Four words
                        firstLetter = toupper(name[0]);
                        secondLetter = toupper(name[n1 + 1]);
                        thirdLetter = toupper(name[n2 + 1]);
                        fourthLetter = toupper(name[n3 + 1]);

                        cout << name << " or " << firstLetter << secondLetter << thirdLetter << fourthLetter << endl;
                        cout << "Enter another university name or press n to exit " << endl;
                        getline(cin, name, '\n');
                    } else {
                        if (n5 == -1) { // Five words
                            firstLetter = toupper(name[0]);
                            secondLetter = toupper(name[n1 + 1]);
                            thirdLetter = toupper(name[n2 + 1]);
                            fourthLetter = toupper(name[n3 + 1]);
                            fifthLetter = toupper(name[n4 + 1]);

                            cout << name << " or " << firstLetter << secondLetter << thirdLetter << fourthLetter << fifthLetter << endl;
                            cout << "Enter another university name or press n to exit " << endl;
                            getline(cin, name, '\n');
                        }   
                    }
                }
            }
        }
    }
}