#include <iostream>
#include <vector>
using namespace std;
vector <long long> a(50,0);

void han(int n, int a, int b) {
	if (n != 1) {
		han(n - 1, a, 6 - (a + b));
		cout << n << ' ' << a << ' ' << b << endl;
		han(n - 1, 6 - (a + b), b);
	}
	else {
		cout << 1 << ' ' << a << ' ' << b << endl;
	}
}
int main() {
	long n;
	cin >> n;
	han(n,1,3);
}