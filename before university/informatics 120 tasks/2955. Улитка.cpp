#include <iostream>
#include <math.h>
using namespace std;
int main() {
	float h, a,b,c;
	cin >> h >> a>>b;
	c = ceil((h - a) / (a - b));
	cout << c+1;
	system("pause");
}