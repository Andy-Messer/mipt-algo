#include <iostream>
using namespace std;
int main() {
	int a,b;
	cin >> a;
	if (a % 2 == 0) {
	 b=a / 2 * 5+(a/2-1)*15+a*45;
	}
	else {
	 b = a / 2 * 5 + (a / 2) * 15 + a * 45;
	}
	cout << 9+b/60<<' '<< b%60;

	return 0;
}