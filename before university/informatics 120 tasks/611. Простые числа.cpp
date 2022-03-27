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
	long long n, m;
	cin >> n>>m;
	bool flag = 0;
	for (long long i = n; i <= m; i++) {
		if (pr(i)) {
			cout << i << endl; flag = 1;
		}
	}
	if (!flag) {
		cout << "Absent";
	}
}