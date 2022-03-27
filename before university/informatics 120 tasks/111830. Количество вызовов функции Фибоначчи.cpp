#include <iostream>
#include <vector>
using namespace std;
vector <long long> a(50,0);

long long f(int n) {
	if (n > 2) {
		if (a[n-1]==0)
		a[n - 1] = f(n - 1);
		if (a[n - 2] == 0)
		a[n - 2] = f(n - 2);
		return a[n-1]+a[n-2]+1;
	}
	if (n == 1) {
		a[n] = 1;
		return 1;
	}
	if (n == 2) {
		a[n] = 1;
		return 1;
	}
}
int main() {
	long n;
	cin >> n;
	cout << f(n);
}