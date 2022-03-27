#include <iostream>
#include<math.h>
using namespace std;
bool pr(long long a) {
	for (long long i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	long long a,b,c;
	cin >> a>>b>>c;
	
	if (a % 2 == 1) {
		a++;
	}
	if (b % 2 == 1) {
		b++;
	}
	if (c % 2 == 1) {
		c++;
	}a = a + b + c;
	a = a / 2;
	cout << a;
}