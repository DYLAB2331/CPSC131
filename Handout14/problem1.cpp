#include <iostream>
using namespace std;

class FRACT {
    private:
        int num, den;

    public:
        void readFraction() {
            cout << "Enter a fraction: ";
            cin >> num; cin.ignore(); cin >> den;
        }

        FRACT friend operator+(FRACT f1, FRACT f2) {
            FRACT sum;
            sum.num = (f1.num * f2.den + f1.den * f2.num);
            sum.den = (f1.den * f2.den);
            return sum;
        }
        
        FRACT friend operator-(FRACT f1, FRACT f2) {
            FRACT diff;
            diff.num = (f1.num * f2.den - f1.den * f2.num);
            diff.den = (f1.den * f2.den);
            return diff;
        }

        FRACT friend operator*(FRACT f1, FRACT f2) {
            FRACT prod;
            prod.num = (f1.num * f2.num);
            prod.den = (f1.den * f2.den);
            return prod;
        }

        FRACT friend operator/(FRACT f1, FRACT f2) {
            FRACT recip;
            recip.num = f2.den;
            recip.den = f2.num;
            return f1 * recip;

        }

        void friend displayFract(FRACT f) {
            cout << f.num << "/" << f.den;
        }
};

int main() {
    FRACT frac1, frac2, fracSum, fracDiff, fracProd, fracDiv;
    frac1.readFraction();
    frac2.readFraction();

    fracSum = frac1 + frac2;
    fracDiff = frac1 - frac2;
    fracProd = frac1 * frac2;
    fracDiv = frac1 / frac2;

    displayFract(frac1); cout << " + ";
    displayFract(frac2); cout << " = ";
    displayFract(fracSum);
    cout << endl;

    displayFract(frac1); cout << " - ";
    displayFract(frac2); cout << " = ";
    displayFract(fracDiff);
    cout << endl;

    displayFract(frac1); cout << " * ";
    displayFract(frac2); cout << " = ";
    displayFract(fracProd);
    cout << endl;

    displayFract(frac1); cout << " / ";
    displayFract(frac2); cout << " = ";
    displayFract(fracDiv);
    cout << endl;

    return 0;
}