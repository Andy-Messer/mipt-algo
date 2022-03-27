#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int a;
	cin >> a;
	cout << (a/10)%10+a/100+a%10;
	return 0;
}