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
	long long n;
	cin >> n;
	long long c=1,k=0;long long c_2 = 1, k_2 = 0;
	while (c < n) {
		c = c << 1; k++;
	}
	
	c = c - 1; k--;
	if (k % 2 == 1) {
		k--; c = c >> 1;
	}
	k = k / 2;
	bool flag = 0;
	while (!pr((1<<(k+1))-1)|| (c & (~((1 << k) - 1)))>=n){
		k--; c = c >> 2;
	}
	c=(c & (~((1 << k) - 1)));
	
	while (c_2 < c) {
		c_2 = c_2 << 1; k_2++;
	}
	c_2--; k_2--;
	long long r;
	for (long long j = k_2; j >= 0; j--) {
		r = c;
		cout << ((r >> j) & 1);
	}
}