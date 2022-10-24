#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class order {
    private:
        struct node {
            T info;
            node *next;
        };

        node* oList;
    
    public:
        order() {
            oList = nullptr;
        }

        bool empty() {
            if (oList == nullptr) {
                return true;
            } else {
                return false;
            }
        }

        void push(T x) {
            node* r = new node;
            r->info = x;
            r->next = nullptr;

            node* p = oList;
            node* q = oList;
            
            if (oList == nullptr) {
                oList = r;
            } else {
                while (p != nullptr && x > p->info) {
                    q = p;
                    p = p->next;
                }

                if (p == q) { // Inserts in front
                    r->next = p;
                    oList = r;
                } else { // Inserts in rear
                    r->next = p;
                    q->next = r;
                }
            }
        }

        void display() {
            node* p = oList;
            while (p != nullptr) {
                cout << p->info << " -> ";
                p = p->next;
            }
        }

        T pop() {
            T poppedElement;
            node* p = oList;
            poppedElement = p->info;
            oList = p->next;
            delete p;

            return poppedElement;
        }
};

int main() {
    order <string> list;
    string s;

    fstream f;
    f.open("file.txt");

    while(!f.eof()) {
        f >> s;
        list.push(s);
    }

    list.display();
}