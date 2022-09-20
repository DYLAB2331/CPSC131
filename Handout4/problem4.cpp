#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

template <class T, int n>

class Stack {

    private:
        int counter = 0;
        T element[n];

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

        T popStack() {
            counter--;
            return element[counter];
        }
};

int main() {
    Stack <string, 10> lowStack;
    Stack <string, 10> highStack;

    string name;
    float gpa;

    fstream f;
    f.open("data.txt");

    while (!f.eof()) {
        f >> name;
        f >> gpa;

        if (gpa <= 3.0) {
            lowStack.pushStack(name);
        } else if (gpa > 3.0) {
            highStack.pushStack(name);
        }
    }

    cout << "GPA <= 3.0          GPA > 3.0" << endl;
    cout << "_____________________________" << endl;

    while (!lowStack.emptyStack() || !highStack.emptyStack()) {
        string l = lowStack.popStack();
        cout << setw(10) << left << l;

        string h = highStack.popStack();
        cout << setw(10) << right << h << endl;
    }

    f.close();


}