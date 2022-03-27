#include <iostream>
using namespace std;
int main() {
	int n, k;
	cin >> k >> n;
	if (n%k == 0) {
		cout << 0;
	}
	else {
		cout << k - n % k;
	}
}