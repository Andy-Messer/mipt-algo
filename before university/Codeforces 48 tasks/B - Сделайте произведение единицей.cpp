#include <iostream>
#include <vector>
using namespace std;
int main() {
	long long n;
	cin >> n; vector<long long>a(n, 0);
	long long k1 = 0, k3 = 0, k2 = 0, k4 = 0, k5 = 0; long long count = 0,count2=0;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			k3++;
		}
		if (a[i] >= 1) {
			count2 = count2 + (abs(a[i]) - 1);
			k4++;
		}
		if (a[i] <= -1) {
			count = count + (abs(a[i]) - 1);
			k5++;
		}
	}
	if (k5 % 2 == 1) {
		if (k3 > 0) {
			cout << count + count2 + k3;
		}
		else {
			cout << count + count2 + 2 + k3;
		}
	}
	else {
		cout << count + count2+k3;
	}
}