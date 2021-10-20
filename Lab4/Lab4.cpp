#include <iostream>

using namespace std;

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
	if (a == b) {
		cout << "Sorry, but a cannot equal b\n";
		return 0;
	}

	h = (b - a) / n;

	for (int i = 1; i <= n; i++) {
		printf("r%i - %.3f\n", i, a + i * h);
	}

	return 0;
}