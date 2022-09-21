#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <class T, int n>

class Stack {
    private:
    
        T element[n];
        int counter;

    public:

        void clearStack() {
            counter = 0;
        }

        bool emptyStack() {
            if (counter == 0) {
                return true;
            } else {
                return false;
            }
        }

        bool fullStack() {
            if (counter == n) {
                return true;
            } else {
                return false;
            }
        }

        void pushStack(T x) {
            element[counter] = x;
            counter++;
        }

        char popStack() {
            counter--;
            return element[counter];
        }
};

int main() {
    Stack <char, 100> sChar;
    char c;
    string fname = "file.txt";

    sChar.clearStack();

    fstream f;
    f.open(fname, ios::in);

    while (!f.eof()) {
        f.get(c);
        if (c != '\n') {
            cout << c;
            sChar.pushStack(c);
        } else {
            cout << "........";
            while (!sChar.emptyStack()) {
                c = sChar.popStack();
                cout << c;
            }
            cout << endl;
        }
    }
    return 0;
}
