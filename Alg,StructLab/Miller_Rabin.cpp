#include <execution>
#include <iostream>
#include <math.h>
using namespace std;

int power(unsigned long int x, unsigned long y, unsigned long p) {
	int res = 1;
	x = x % p;
	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

bool millerTest(unsigned long d, unsigned long n) {
	unsigned long a = 2 + rand() % (n - 4);

	unsigned long x = power(a, d, n);

	if (x == 1 || x == n - 1)
		return true;

	while (d != n - 1) {
		x = (x * x) % n;
		d *= 2;
		if (x == 1) return false;
		if (x == n - 1) return true;

	}
	return false;
}

bool isPrime(unsigned long n, int k) {
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;

	unsigned long int d = n - 1;
	while (d % 2 == 0)
		d /= 2;
	for (int i = 0; i < k; i++) {
		if (!millerTest(d, n))
			return false;
	}
	return true;
}




int main()
{
	int n = 10000000;
	int k = 200;
	vector<unsigned long> primeN(n);
	iota(primeN.begin(), primeN.end(), 1);

	vector<bool> isPrimeV(n);



	transform(execution::par,
		primeN.begin(), primeN.end(),
		isPrimeV.begin(),
		[k](unsigned long x) -> bool {
			return isPrime(x, k);
		});

	int count = accumulate(isPrimeV.begin(), isPrimeV.end(), 0, [](int d, bool v) {
		if (v == true) return d += 1; else return d;
		});
	cout << count << endl;

	return 0;
}