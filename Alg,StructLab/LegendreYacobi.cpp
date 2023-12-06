#include <iostream>
using namespace std;

int calculateJacobiSymbol(long long a, long long n) {
	if (!a)
		/* 0/n= 0 */
		return 0;

	int res = 1;
	if (a < 0) {
		/*a/n= -(a/n) * -(1/n) */
		a = -a;
		if (n % 4 == 3)
			/* -(1n)=-1 if n= 3 (mod 4) */
			res = -res;
	}

	if (a == 1)
		/* (1/n) = 1 */
		return res;

	while (a) {
		if (a < 0) {
			/*a/n= -(a/n) * -(1/n) */
			a = -a;
			if (n % 4 == 3)
				/* -(1/n)=-1 if n= 3 (mod 4) */
				res = -res;
		}

		while (a % 2 == 0) {
			a = a / 2;
			if (n % 8 == 3 || n % 8 == 5)
				res = -res;
		}
		swap(a, n);

		if (a % 4 == 3 && n % 4 == 3)
			res = -res;
		a = a % n;

		if (a > n / 2)
			a = a - n;
	}

	if (n == 1)
		return res;

	return 0;
}

int main() {
	int a = 1235;
	int n = 10007;

	cout << calculateJacobiSymbol(a, n);
}