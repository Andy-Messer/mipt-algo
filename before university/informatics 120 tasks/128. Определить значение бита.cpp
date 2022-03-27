#include <iostream>
#include<math.h>
using namespace std;
int main() {
	long long n,i;
	cin >> n>>i;
	cout <<((n>>i)&1);
	return 0;
}