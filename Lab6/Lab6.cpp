#include <iostream> 
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
double term(double x, int n) {
    double res;

    if (factorial(2*n) == 0) {
        cout << "ULLong overflow\n";
        return 0;
    }
    else {
        res = pow(x, 2 * n) / factorial(2 * n);
        return (n % 2) ? -res : res;
    }
    
}
/**
* Computes approximal cos of a given number with given precision E using Taylor series
*/
double cosFunc(double x, double E) {
    double result = 1.0;
    double t;

    for (int i = 1; (fabs(t = term(x, i)) >= E); i++) {
        result += t;
    }
    
    return result;
}

int main()
{
    double a, b, E, y;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "Precision E (>0) = "; cin >> E;

    if (E <= 0) {
        cout << "E must be greater than 0";
        return 0;
    }

    y = cosFunc(a, E) + pow(cosFunc(b, E), 2) + cosFunc(a + b, E);

    printf("y = %5.9f\n", y);
    
    return 0;
}
