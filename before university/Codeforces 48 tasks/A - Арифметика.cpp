#include<iostream>
using namespace std;
int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if (a * b == c || a * c == b || b * c == a) {
		if (a * b == c) {
			cout << "Yes" << endl;
			cout << a << ' ' << b << ' ' << c; return 0;
		}
		if (a * c == b) {
			cout << "Yes" << endl;
			cout << a << ' ' << c << ' ' << b; return 0;
		}
		if (b * c == a) {
			cout << "Yes" << endl;
			cout << b << ' ' << c << ' ' << a; return 0;
		}
	}
	else {
		cout << "No";
	}
}