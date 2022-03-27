#include <iostream>
#include<math.h>
#include<vector>
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
	long long n,a;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> a;
		long long f = a,r=1,k=0;
		while (f > 0) {
			if (f & 1 == 1)k++;
			f = f >> 1; 
		}
		cout << (1 << k)<<endl;
	}
}