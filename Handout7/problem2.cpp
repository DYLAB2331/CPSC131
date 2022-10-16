#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class LinkedList {
    private:
        struct node {
            string name;
            int age;
            node *next;
        };

        node *list;
    
    public:
        LinkedList() {
            list = NULL;
        }

        void insert(string name, int age) {
            node *p;
            p = new(node);

            p->name = name;
            p->age = age;
            p->next = NULL;

            if (list == NULL) {
                list = p;
            } else {
                p->next = list;
                list = p;
            }
        }

        void displayList() {
            node *p;
            p = list;

            while (p != NULL) {
                cout << p->name << "\t" << p->age << endl;

                p = p->next;
            }
        }

        int findMax() {
            node *p;
            p = list;

            int max = p->age;
            p = p->next;

            while (p != NULL) {
                if (p->age > max) {
                    max = p->age;
                }
                p = p->next;
            }

            cout << "The oldest person is "
        }
};

int main() {
    LinkedList L;
    fstream f;
    string fname;
    int fage;

    f.open("pro7.txt");

    while (!f.eof()) {
        f >> fname;
        f >> fage;

        L.insert(fname, fage);
    }

    L.displayList();
}
