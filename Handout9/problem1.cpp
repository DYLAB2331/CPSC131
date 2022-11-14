#include <iostream>
using namespace std;

class HASH {
    private:
        struct node {
            string monthName;
            int monthDays;
            node *next;
        };

        node *H[5];
    
    public:
        void initHashTable() {
            for (int i = 0; i < 5; i++) {
                H[i] = NULL;
            }
        }

        int hashFunc(string name) {
            int x = (int(name[0]) + int(name[1]) + int(name[2])) % 5;
            return x;
        }

        void insertHash(string name, int num) {
            int index = hashFunc(name);

            node *p;
            p = new node;
            p->monthName = name;
            p->monthDays = num;
            p->next = H[index];
            H[index] = p;
        }

        void searchHash(string name) {
            int index = hashFunc(name);
            int count = 0;
            
            node *p = H[index];
            while (p != NULL && p->monthName != name) {
                p = p->next;
                count++;
            }

            if (p == NULL) {
                cout << name << " does not exist." << endl;
            } else {
                cout << "Number of days in " << name << " is " << p->monthDays << " after " << count + 1 << " comparisons!" << endl;
            }
        }

        void displayHash() {
            for (int i = 0; i < 5; i++) {
                cout << "H[" << i << "]--->";

                node *p = H[i];

                while (p != NULL) {
                    cout << p->monthName << "," << p->monthDays << "--->";
                    p = p->next;
                }
                cout << "NULL" << endl;
            }
        }
};

int main() {
    string months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUY", "AUG", "SEP", "OCT", "NOV", "DEC"};
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    HASH h;
    h.initHashTable();

    for (int i = 0; i < 12; i++) {
        h.insertHash(months[i], days[i]);
    }

    cout << "This is the hash table: " << endl;
    h.displayHash();

    string n;
    cout << "Enter a month name: ";
    cin >> n;
    h.searchHash(n);

    return 0;
}