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
        result *= num;
        num--;
    }
    return result;
}

/**
* Compute e with given precision based on number of iterations
*/
double getEulerNum() {
    double result = 1;
    int i = 1;

    // until the overflow
    while (factorial(i) > 0) 
    {
        result += 1.0 / factorial(i);
        i++;
    }

    return result;
}

int main()
{
    // precision with which the result will be shown
    int prec;
    cout << "Precision (num of significant digits) = "; cin >> prec;
    
    if (prec > 51) { cout << "Sorry, but 51 is the maximum precision\n"; }

    cout << setprecision(prec) << "e = " << getEulerNum() ;

    return 0;
}
