#include <iostream>
#include <iomanip>
using namespace std;

/**
* Compute euler's number with given precision E
*/
double getEulerNum(double E) {
    double result = 0.0, term = 1.0, i = 1.0;

    while (term >= E) {
        result += term;

        term /= i; // every other term is the  previous term devided by numeral

        i++;
    }

    return result;
}

int main()
{
    double E;
    cout << "Precision E (0, 1] = "; cin >> E;

    if (E <= 0 || E > 1) {
        cout << "Invalid precision\n";
        return 0;
    }

    cout <<  setprecision(51) << "e = " << getEulerNum(E);

    return 0;
}
