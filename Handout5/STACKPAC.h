#ifndef STACKPAC
#define STACKPAC

template <class T, int n>

class Stack {
    private:
        T element[n];
        int counter;
    
    public:
        void clear() {
            counter = 0;
        }

        bool empty() {
            if (counter == 0) {
                return true;
            } else {
                return false;
            }
        }

        bool full() {
            if (counter != 0) {
                return true;
            } else {
                return false;
            }
        }

        void push(T x) {
            element[counter] = x;
            counter++;
        }

        T pop() {
            counter--;
            return element[counter];
        }
};

#endif