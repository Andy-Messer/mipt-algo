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
int a[1000][1000],m[1000];
int main() {
	long long n;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		long long f = 0;
		for (long long j = 0; j < n; j++) {
			cin >> a[i][j]; f = f | a[i][j];
		}
		m[i] = f;
	}
	for (long long i = 0; i < n; i++) {
		cout << m[i] << ' ';
	}
	
}