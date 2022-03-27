#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1000000000;
long long n, m2;vector<long long>a;
bool check(long long d) {
	long long f = 0,b;
	b = a[0]; f++;
	for (long long i = 1; i < n; i++) {
		if (a[i] - b>=d) {
			f++; b = a[i];
		}
	}
	if (f >= m2)return true;
	return false;
}
int main() {
	long long r,l;
	cin >> n >> m2;
	
	a.resize(n, 0);
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	l = 0; r = INF; long long m;
	while (l+1< r) {
		m = (l + r) / 2;
		if (check(m)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	if (check(r)) {
		cout << r;
	}
	else {
		cout << l;
	}
}