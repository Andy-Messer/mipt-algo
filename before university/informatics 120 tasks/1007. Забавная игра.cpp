#include <iostream>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
	long long n,a;
	cin >> n;
	a = n;
	long long j = 0;
	while (a > 0) {
		a = (a >> 1); j++;
	}
	long long b = (1 << j)-1;
	n = (n<<j)|n;
	long long max = 0;
	for (int i = 0; i < j; i++) {
		long long f = (n >> i) & b;
		if (f > max) {
			max = f;
		}
	}
	cout << max;
	return 0;
}