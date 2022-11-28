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

        void child(node *p) {
            if (p == NULL) {
                return;
            }

            if ((p->left != NULL && p->right == NULL) || (p->left == NULL && p->right != NULL)) {
                cout << p->info << " ";
            }

            child(p->left);
            child(p->right);
        }

        void child() {
            child(root);
        }

        int height(node *p) {
            if (p == NULL) {
                return -1;
            } else {
                return 1 + max(height(p->left), height(p->right));
            }
        }

        int height() {
            height(root);
        }

        void search(node *p, T x) {
            if (p == NULL) {
                cout << x << " does not exist" << endl;
            } else if (x == p->info) {
                cout << x << " is found" << endl;
            } else {
                if (x < p->info) {
                    search(p->left, x);
                }

                if (x > p->info) {
                    search(p->right, x);
                }
            }
        }

        void search(string x) {
            search(root, x);
        }

        int count(node *p) {
            if (p == NULL) {
                return 0;
            } else {
                return 1 + count(p->left) + count(p->right);
            }
        }

        int count() {
            count(root);
        }

};

int main() {

    string days[7] = {"MON", "TUE", "WED", "THR", "FRI", "SAT", "SUN"};

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

    cout << endl;
    cout << "Nodes with 1 child: ";
    d.child();

    cout << endl;
    cout << "Height: " << d.height();

    cout << endl;
    d.search("Mon");
    d.search("THR");

    cout << "Number of nodes: " << d.count();
    
}