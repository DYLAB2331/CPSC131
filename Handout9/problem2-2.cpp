#include <iostream>
#include <vector>
using namespace std;

class HASH {
    private:
        struct node {
            int info;
            node *next;
        };

        node *H[10];

    public:

        void initHashTable() {
            for (int i = 0; i < 10; i++) {
                H[i] = nullptr;
            }
        }

        void insert(int x) {
            int index = hashUnit(x);

            node *p;
            node *q;
            q = H[index];
            p = new node;
            p->info = x;
            p->next = nullptr;

            if (H[index] == nullptr) {
                H[index] = p;
                return;
            }

            while (q->next != nullptr) {
                q = q->next;
            }

            q->next = p;
        }

        void insert2(int x) {
            int index = hashTenth(x);

            node *p;
            node *q;
            q = H[index];
            p = new node;
            p->info = x;
            p->next = nullptr;

            if (H[index] == nullptr) {
                H[index] = p;
                return;
            }

            while (q->next != nullptr) {
                q = q->next;
            }

            q->next = p;
        }

        void insert3(int x) {
            int index = hashHundredth(x);

            node *p;
            node *q;
            q = H[index];
            p = new node;
            p->info = x;
            p->next = nullptr;

            if (H[index] == nullptr) {
                H[index] = p;
                return;
            }

            while (q->next != nullptr) {
                q = q->next;
            }

            q->next = p;
        }

        int hashUnit(int x) {
            int index = x % 100 % 10;
            return index;
        }

        int hashTenth(int x) {
            int index = x % 100 / 10;
            return index;
        }

        int hashHundredth(int x) {
            int index = x / 100;
            return index;
        }

        void display() {
            for (int i = 0; i < 10; i++) {
                cout << "H[" << i << "]--->";

                node *p = H[i];
                while (p != NULL) {
                    cout << p->info << "--->";
                    p = p->next;
                }

                cout << "NULL" << endl;
            }
        }

        int extract(int i) {
            vector <int> c;
            node *p = H[i];
            while (p != nullptr) {
                c.push_back(p->info);
                p = p->next;
            }

            if (!c.empty()) {
                for (int i = 0; i < c.size(); i++) {
                    return c.at(i);
                }
            }
        
            return 0;
        }

};

int main() {
    int a[9] = {199, 200, 77, 45, 15, 278, 66, 9, 100};

    HASH h;
    h.initHashTable();

    for (int i = 0; i < 10; i++) {
        h.insert(a[i]);
    }

    vector <int> b;
    for (int i = 0; i < 10; i++) {
        int c = h.extract(i);
        b.push_back(c);
    }

    for (int i = 0; i < 10; i++) {
        h.insert2(b.at(i));
    }

    vector <int> d;
    for (int i = 0; i < 10; i++) {
        int e = h.extract(i);
        d.push_back(e);
    }

    for (int i = 0; i < 10; i++) {
        h.insert3(d.at(i));
    }

    vector <int> f;
    for (int i = 0; i < 10; i++) {
        int g = h.extract(i);
        f.push_back(g);
    }

    for (int i = 0; i < f.size(); i++) {
        cout << f.at(i) << " ";
    }

    return 0;
}