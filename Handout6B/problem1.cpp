#include <iostream>
#include <string>
#include "STACKPAC.h"
using namespace std;

int main() {

    int tom, jerry, mickey;
    int tomVal, jerryVal, mickeyVal;
    int x, y, z;
    int value;
    string id;
    Stack <int, 10> s;
    s.clear();

    cout << "Enter the value of tom: " << endl;
    cin >> tomVal;

    cout << "Enter the value of jerry: " << endl;
    cin >> jerryVal;

    cout << "Enter the value of mickey: " << endl;
    cin >> mickeyVal;

    cout << "Enter a postfix expression: ";

    while (cin >> id, id!="$") {
        if (isdigit(id[0])) {
            value = stoi(id);
            s.push(value);
        }

        if (id == "tom") {
            s.push(tomVal);
        } else if (id == "jerry") {
            s.push(jerryVal);
        } else if (id == "mickey") {
            s.push(mickeyVal);
        } else if (id == "+") {
            x = s.pop();
            y = s.pop();
            z = x + y;
            s.push(z);
        } else if (id == "-") {
            x = s.pop();
            y = s.pop();
            z = y - x;
            s.push(z);
        } else if (id == "*") {
            x = s.pop();
            y = s.pop();
            z = x * y;
            s.push(z);
        }
    }

    cout << "Value of postfix expression is " << s.pop() << endl;
} 