#include <iostream>
using namespace std;

int gdc(int a,int b) {
	if (b == 0) 
		return a;
	return gdc(b, a % b);
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << gdc(a,b);
}