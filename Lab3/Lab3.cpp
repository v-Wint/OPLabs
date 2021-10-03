#include <iostream>
#include <iomanip>
using namespace std;

/** 
* Compute the factorial of a given number
*/
unsigned long long int factorial(int num) {
    unsigned long long int result = 1;
    while (num)
    {
        // to prevent ullong overflow
        if (result < ULLONG_MAX / num) {
            result *= num;
            num--;
        }
        else {
            return 0;
        }
    }
    return result;
}

/**
* Compute euler's number with given precision E
*/
double getEulerNum(double E) {
    double result = 1;
    int i = 1;

    while (1.0 / factorial(i) >= E)
    {
        if (factorial(i) == 0) {
            cout << "ULLong overflow\n";
            break;
        }
        else {
            result += 1.0 / factorial(i);
            i++;
        }
        
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

    cout << setprecision(51) << "e = " << getEulerNum(E);

    return 0;
}
