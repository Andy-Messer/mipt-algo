#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;
bool proverka(int a) {
	int sum = 0;
	while (a > 0) {
		sum += a % 10;
		a = a / 10;
	}
	if (sum % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int sum,a,b;
	cin >> a;
	while (!proverka(a))a++;
	cout << a;
}