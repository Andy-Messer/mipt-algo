#include <iostream>
#include<math.h>
using namespace std;
int main() {
	long long n,r;
	cin >> n;
	for (long long j = 7; j >=0; j--) {
		r = n;
		cout << ((r >> j) & 1);
	}
	return 0;
}