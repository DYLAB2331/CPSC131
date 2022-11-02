#include <iostream>
using namespace std;

class HASH {
    private:
        struct node {
            int info;
            node *next;
        };

        node *H1[10];
        node *H2[10];
        node *H3[10];

    public:
        void initHashTable() {
            for (int i = 0; i < 10; i++) {
                H1[i] = NULL;
                H2[i] = NULL;
                H3[i] = NULL;
            }
        }

        int hashFuncUnit(int x) {
            int index = x % 100 % 10;
            return index;
        }

        int hashFuncTenth(int x) {
            int index = x % 100 / 10;
            return index;
        }

        int hashFuncHundred(int x) {
            int index = x / 100;
            return index;
        }

        void insertHashH1(int x) {
            int index = hashFuncUnit(x);

            node *p;
            p = new node;
            p->info = x;
            p->next = H1[index];
            H1[index] = p;
        }

        void insertHashH2(int x) {
            int index = hashFuncTenth(x);

            node *p;
            p = new node;
            p->info = x;
            p->next = H2[index];
            H2[index] = p;
        }

        void insertHashH3(int x) {
            int index = hashFuncHundred(x);

            node *p;
            p = new node;
            p->info = x;
            p->next = H3[index];
            H3[index] = p;
        }

        void displayHashH1() {
            for (int i = 0; i < 10; i++) {
                cout << "H1[" << i << "]--->";

                node *p = H1[i];
                while (p != NULL) {
                    cout << p->info << "--->";
                    p = p->next;
                }

                cout << "NULL" << endl;
            }
        }

        void displayHashH2() {
            for (int i = 0; i < 10; i++) {
                cout << "H2[" << i << "]--->";

                node *p = H2[i];
                while (p != NULL) {
                    cout << p->info << "--->";
                    p = p->next;
                }

                cout << "NULL" << endl;
            }
        }

        void displayHashH3() {
            for (int i = 0; i < 10; i++) {
                cout << "H3[" << i << "]--->";

                node *p = H3[i];
                while (p != NULL) {
                    cout << p->info << "--->";
                    p = p->next;
                }

                cout << "NULL" << endl;
            }
        }

};

int main() {
    int a[9] = {199, 200, 077, 045, 015, 278, 066, 9, 100};

    HASH h;
    h.initHashTable();

    for (int i = 0; i < 10; i++) {
        h.insertHashH1(a[i]);
    }

    h.displayHashH1();

    for (int i = 0; i < 10; i++) {
        h.insertHashH2(a[i]);
    }

    h.displayHashH2();

    for (int i = 0; i < 10; i++) {
        h.insertHashH3(a[i]);
    }

    h.displayHashH3();
}