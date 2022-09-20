#include <iostream>
#include <fstream>
using namespace std;

void copyData(string fname, int x[2][4][2]) {
    fstream f;
    f.open(fname, ios::in);

    for (int status = 0; status < 2; status++) {
        for (int campus = 0; campus < 4; campus++) {
            for (int gender = 0; gender < 2; gender++) {
                f >> x[status][campus][gender];
            }
        }
    }

    f.close();
}

int findTotalStud(int x[2][4][2]) {
    int total = 0;

    for (int status = 0; status < 2; status++) {
        for (int campus = 0; campus < 4; campus++) {
            for (int gender = 0; gender < 2; gender++) {
                total += x[status][campus][gender];
            }
        }
    }

    return total;
}

int findFemales(int x[2][4][2]) {
    int total = 0;

    for (int status = 0; status < 2; status++) {
        for (int campus = 0; campus < 4; campus++) {
            int gender = 0; {
                total += x[status][campus][gender];
            }
        }
    }

    return total;
}

int findGrads(int x[2][4][2]) {
    int total = 0;

    int status = 1; {
        for (int campus = 0; campus < 4; campus++) {
            for (int gender = 0; gender < 2; gender++) {
                total += x[status][campus][gender];
            }
        }
    }

    return total;
}

int findUnderGradOrange(int x[2][4][2]) {
    int total = 0;

    int status = 0; {
        int campus = 1; {
            for (int gender = 0; gender < 2; gender++) {
                total += x[status][campus][gender];
            }
        }
    }

    return total;
}

int main() {
    int stud[2][4][2];

    copyData("file.txt", stud);

    int totalStud = findTotalStud(stud);
    cout << totalStud << endl;

    int totalFemales = findFemales(stud);
    cout << totalFemales << endl;

    int totalGrads = findGrads(stud);
    cout << totalGrads << endl;

    int underGradOrange = findUnderGradOrange(stud);
    cout << underGradOrange << endl;

    return 0;
}