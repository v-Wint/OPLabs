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

/*
* returns the term of the progression
*/
double term(int n) {
    if (factorial(n) == 0) {
        cout << "ULLong overflow\n";
        return 0;
    }
    else {
        return 1.0 / factorial(n);
    }
}

/**
* Compute euler's number with given precision E
*/
double getEulerNum(double E) {
    double result = 1;
    double t;

    for (int i = 1; ((t = term(i)) >= E); i++) {
        result += t;
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

    cout << fixed <<  setprecision(51) << "e = " << getEulerNum(E);

    return 0;
}
