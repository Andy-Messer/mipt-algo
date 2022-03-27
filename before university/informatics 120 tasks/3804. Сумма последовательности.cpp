#include <iostream>
using namespace std;

int sum(int n) {
	int x;
	cin >> x;
	if (x != 0) {
		return sum(n - 1) + x;
	}
	return 0;
}
int main() {

	cout << sum(0);
}