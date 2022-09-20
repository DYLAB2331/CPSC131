#include <iostream>
#include <fstream>
#include <string>
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
            counter++
        }

        T popStack() {
            counter--;
            return element[counter];
        }
};



int main() {

}