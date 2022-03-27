#include <iostream>
#include <math.h>
#include <climits>
#include <limits.h>
using namespace std;
int main() {
	int n,m,k,q;
	cin >> n>>m;
	k = 1 ^ ((n - m) >> (sizeof(int) * CHAR_BIT - 1)) & 0x1;
	q = 1 ^ k;
	cout << n * k + m * q;
	system("pause");
}