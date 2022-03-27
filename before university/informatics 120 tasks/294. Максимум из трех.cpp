#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) {
		if (c > a) {
			cout << c;
		}
		else {
			cout << a;
		}
	}
	else {
		if (c > b) {
			cout << c;
		}
		else {
			cout << b;
		}
	}
}