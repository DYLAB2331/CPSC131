#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class orderedList {
    private:
        struct node {
            int acctNo;
            string name;
            float balance;
            node *next;
        };

        node *oList;

    public:
        orderedList() {
            oList = NULL;
        }

        void push(int x, string y, float z) {
            node *curr = new node;
            curr->acctNo = x;
            curr->name = y;
            curr->balance = z;
            curr->next = NULL;

            node *p = oList;
            node *q = oList;

            if (oList == NULL) {
                oList = curr;
            } else {
                while (p != NULL && x > p->acctNo) {
                    q = p;
                    p = p->next;
                }

                if (p == q) {
                    curr->next = p;
                    oList = curr;
                } else {
                    curr->next = p;
                    q->next = curr;
                }
            }   
        }

        void showBalance() {
            int acct;
            cout << "Enter your account number: ";
            cin >> acct;

            node *curr = oList;
            while (curr->acctNo != acct) {
                curr = curr->next;
            }

            cout << curr->name << ", your balance is " << curr->balance << endl;
        }

        void deposit() {
            int acct;
            cout << "Enter your account number: ";
            cin >> acct;

            node *curr = oList;
            while (curr->acctNo != acct) {
                curr = curr->next;
            }

            float depositAmount;
            cout << curr->name << ", how much would you like to deposit? ";
            cin >> depositAmount;

            curr->balance += depositAmount;

            cout << curr->name << ", your new balance is " << curr->balance << endl;
        }

        void withdraw() {
            int acct;
            cout << "Enter your account number: ";
            cin >> acct;

            node *curr = oList;
            while (curr->acctNo != acct) {
                curr = curr->next;
            }

            float withdrawAmount;
            cout << curr->name << ", how much would you like to withdraw? ";
            cin >> withdrawAmount;

            if (withdrawAmount > curr->balance) {
                cout << "Not enough funds available" << endl;
                return;
            }

            curr->balance -= withdrawAmount;

            cout << curr->name << ", your new balance is " << curr->balance << endl;
        }

        void showAll() {
            node *curr = oList;
            while (curr != NULL) {
                cout << curr->acctNo << "\t" << curr->name << "\t" << curr->balance << endl;
                curr = curr->next;
            }
        }

        void close() {
            int acct;
            cout << "Enter your account number: ";
            cin >> acct;

            node *curr = oList;
            node *temp = oList;

            if (curr->acctNo == acct) {
                oList = curr->next;
                cout << curr->name << ", we have closed your account" << endl;
                delete curr;
                return;
            }

            while (curr->acctNo != acct) {
                temp = curr;
                curr = curr->next;
            }

            temp->next = curr->next;
            cout << curr->name << ", we have closed your account" << endl;
            delete curr;
            
            return;
        }
};

int main() {
    int acct;
    string names;
    float bal;

    orderedList <int> list;

    fstream f;
    f.open("file.txt");

    while (!f.eof()) {
        f >> acct >> names >> bal;
        list.push(acct, names, bal);
    }

    char c;

    while (c != 'n') {
        int input;
        cout << "1. Show my balance\n2. Deposit\n3. Withdraw\n4. Show all\n5. Close my account\n";
        cin >> input;

        switch(input) {
            case 1:
                list.showBalance();
                break;
            case 2:
                list.deposit();
                break;
            case 3: 
                list.withdraw();
                break;
            case 4: 
                list.showAll();
                break;
            case 5:
                list.close();
                break;
            
        }

        cout << "Continue? (y/n) ";
        cin >> c;
    }
}