
 #include <iostream>
#include <string>
#include<math.h>
using namespace std;
int main() {
	long long a, b;
	cin >> a >> b;
	if (abs(a - b) == 0) {
		cout << a << 1 << 0 << ' ' << b << 1 << 1;
	}
	else {
		if (b - a == 1) {
			cout << a << 9 << 9 << ' ' << b << 0 << 0;
		}else{
			if (a - b == 8) {
				cout << a << 9 << 9 << ' ' << b << 0 << 0<<0;
			}else{
				cout << -1;
			}
		}
	}
	return 0;
}