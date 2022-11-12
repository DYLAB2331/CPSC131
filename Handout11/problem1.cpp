#include <iostream>
using namespace std;

template <class T>
class BST {
    
    private:
        struct node {
            T info;
            node *left;
            node *right;
        };

        node *root;

    public:

        BST() {
            root = NULL;
        }

        void insert(node *&p, T x) {
            node *curr = new node;
            curr->info = x;

            curr->right = NULL;
            curr->left = NULL;

            if (p == NULL) {
                p = curr;
            } else {
                if (x > p->info) {
                    insert(p->right, x);
                }

                if (x < p->info) {
                    insert(p->left, x);
                }
            }
        }

        void insert(T x) {
            insert(root, x);
        }

        void inOrder(node *p) {
            if (p != NULL) {
                inOrder(p->left);
                cout << p->info << " ";
                inOrder(p->right);
            }
        }

        void inOrder() {
            inOrder(root);
        }

        void postOrder(node *p) {
            if (p != NULL) {
                postOrder(p->left);
                postOrder(p->right);
                cout << p->info << " ";
            }
        }

        void postOrder() {
            postOrder(root);
        }

        void preOrder(node *p) {
            if (p != NULL) {
                cout << p->info << " ";
                preOrder(p->left);
                preOrder(p->right);
            }
        }

        void preOrder() {
            preOrder(root);
        }

        void leaves(node *p) {
            if (p != NULL) {
                leaves(p->left);
                if (p->left == NULL && p->right == NULL) {
                    cout << p->info << " ";
                }

                leaves(p->right);
            }
        }

        void leaves() {
            leaves(root);
        }

};

int main() {

    string days[7] = {"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"};

    BST <string> d;

    for (int i = 0; i < 7; i++) {
        d.insert(days[i]);
    }

    cout << "In-order tree: ";
    d.inOrder();

    cout << endl;
    cout << "Post-order tree: ";
    d.postOrder();

    cout << endl;
    cout << "Pre-order tree: ";
    d.preOrder();

    cout << endl;
    cout << "Leaves: ";
    d.leaves();
}