#include <iostream>
#include <vector>
using namespace std;
vector <long long> a(50,0);

void han(int n, int a, int b) {
	if (a == 1 && b == 3) {
		han(n, 1, 2);
		han(n, 2, 3);
	}
	else {
		if (a == 3 && b == 1) {
			han(n, 3, 2);
			han(n, 2, 1);
		}
		else {
			if (n != 1) {
				han(n - 1, a, 6 - (a + b));
				cout << n << ' ' << a << ' ' << b << endl;
				han(n - 1, 6 - (a + b), b);
			}
			else {
				cout << 1 << ' ' << a << ' ' << b << endl;
			}
		}
	}
}
int main() {
	long n;
	cin >> n;
	han(n,1,3);
}