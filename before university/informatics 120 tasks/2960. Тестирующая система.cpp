#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a>>b;
	if (a == 1) {
		if (a == b) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	else {
		if (b == 1) {
			cout << "NO";
		}
		else {
			cout << "YES";
		}
	}
}