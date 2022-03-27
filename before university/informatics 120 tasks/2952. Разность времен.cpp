#include <iostream>
using namespace std;
int main() {
	int a, b, c, a2, b2, c2;
	cin >> a >> b >> c;
	cin >> a2 >> b2 >> c2;
	c = c + b * 60 + a * 3600;
	c2 = c2 + b2 * 60 + a2 * 3600;
	cout << c2 - c;
	return 0;
}