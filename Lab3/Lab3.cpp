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
* Compute euler's number
*/
double getEulerNum() {
    double result = 1;

    // 25 iterations is enough
    for (int i = 1; i <= 25; i++) 
    {
        result += 1.0 / factorial(i);
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
