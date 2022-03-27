#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int a,b,c,d,e;
	cin >> a;
	b = a / 1000+10;
	c = a / 100 % 10+10;
	d = a / 10 % 10+10;
	e = a % 10+10;
	cout << b % e + e % b + c % d + d % c + 1;
	system("pause");
}