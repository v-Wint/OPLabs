#include <iostream> 
using namespace std;

/**
* Computes approximal cos of a given number with given precision E using Taylor series
*/
double cosFunc(double x, double E) {
    double result = 0.0, term = 1.0, i = 1.0;
    
    while (fabs(term) >= E) {
        result += term;

        //every other term equals the previous term multiplied by -x^2/(2n*(2n-1)
        term = -term * pow(x, 2) / (2 * i * (2 * i - 1)); 
        i++;
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
