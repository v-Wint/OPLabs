#include <iostream>

using namespace std;

/**
* Gets the length of a segment based on coords
*/
double getLength(double x1, double x2, double y1, double y2) {
    double length = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return length;
}

int main()
{
    double x1, x2, x3, y1, y2, y3;

    // input data
    cout << "x1= "; cin >> x1;
    cout << "y1= "; cin >> y1;
    cout << "x2= "; cin >> x2;
    cout << "y2= "; cin >> y2;
    cout << "x3= "; cin >> x3;
    cout << "y3= "; cin >> y3;

    // declare length of the sides
    double a = getLength(x1, x2, y1, y2), b = getLength(x2, x3, y2, y3), c = getLength(x3, x1, y3, y1);

    double per, halfPer, area;

    per = a + b + c;
    halfPer = per / 2;

    // using Heron's formula
    area = sqrt(halfPer * (halfPer - a) * (halfPer - b) * (halfPer - c));

    printf("Perimeter = %5.3f\nArea = %5.3f\n", per, area);

    return 0;
}