#include <iostream>

using namespace std;

double func(double x, double a) {
	double y;

	y = (x < 0) ? y = x : y = a;

	return y;
}

int main()
{
	double x, a, y;

	//input data
	cout << "x = "; cin >> x;
	cout << "A = "; cin >> a;

	y = func(x, a);

	printf("y = %f\n", y);

	return 0;
}