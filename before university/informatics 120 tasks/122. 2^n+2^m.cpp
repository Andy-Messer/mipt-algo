#include <iostream>
#include<math.h>
using namespace std;
int main() {
	long long n, i;
	cin >> n >> i;

	cout << ((1 << n)|(1<<i));
	return 0;
}