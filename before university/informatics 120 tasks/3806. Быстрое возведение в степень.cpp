#include <iostream>
using namespace std;

long double power(long double a, long long n) {
	if (n>1)
	if (n % 2 == 0) {
		return power(a*a, n / 2);
	}
	else {
		return a * power(a, n - 1);
	}
	if (n==1)
	return a;
	if (n == 0)
		return 1;
}
int main() {
	long double a; long long b;
	cin >> a >> b;
	cout << power(a,b);
}