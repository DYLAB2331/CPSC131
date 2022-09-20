#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Declaration of struct presidents
struct presidents {
    string presName;
    string yearsServed;
    string wifeName;
};

// Function to copy data from data.txt
void copyData(string fname, presidents pres[], int n) {
    fstream f;
    f.open(fname, ios::in); // Opens file

    // Loop to iterate through file and store data in pres array
    for (int i = 0; i < n; i++) { 
        f >> pres[i].presName >> pres[i].yearsServed >> pres[i].wifeName;
    }

    f.close(); // Closes file
}

// Function to display data from data.txt
void displayAll(presidents pres[], int n) {
    // Heading
    cout << left << setw(15) << "Name" << left << setw(15) << "Years Served" << right << setw(15) << "Wife's Name" << endl;

    // Loop to output data within array; uses setw() to set width and left and right align
    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << pres[i].presName << left << setw(15) << pres[i].yearsServed << right << setw(15) << pres[i].wifeName << endl;
    }
}

// Main function
int main() {
    // Declares pres array of 6
    presidents pres[6];

    // Function calls
    copyData("data.txt", pres, 6);
    displayAll(pres, 6);

    return 0;
}


