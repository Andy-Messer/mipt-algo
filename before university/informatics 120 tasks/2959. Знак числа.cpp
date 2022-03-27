#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	if (a < 0) {
		cout << -1;
	}
	else {
		if (a == 0) {
			cout << 0;
		}
		else {
			cout << 1;
		}
	}
}