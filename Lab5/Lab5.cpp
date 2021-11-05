#include <iostream>

using namespace std;

int reversedNumber(int);

int main() {
	for (int num = 1000000; num <= 1000000000; num++)
	{
		if (num == reversedNumber(num))
		{
			cout << num << "\n";
		}
	}

	return 0;
}

/*
* returns reversed integer
*/
int reversedNumber(int num) {
	int revNum = 0, rem;
	while (num > 0)
	{
		rem = num % 10;
		revNum = revNum * 10 + rem;
		num = num / 10;
	}
	return revNum;
}