#include <iostream>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
	long long n,a;
	cin >> n;
	unsigned long long f=0;
	for (long long i = 0; i < n; i++) {
		cin >> a;
		f=f^a;
	}
	cout << f;
	
	return 0;
}