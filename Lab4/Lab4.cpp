#include <iostream>

using namespace std;

double getH(double a, double b, int n) {
	return (b - a) / n;
}

int main()
{
	double a, b, h;
	int n;

	// data input
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "n = "; cin >> n;
	
	if (n == 0) {
		cout << "Sorry, but n cannot equal 0";
		return 0;
	}

	h = getH(a, b, n);

	for (int i = 1; i <= n; i++) {
		printf("%i - %.3f\n", i, a + i * h);
	}

	return 0;
}