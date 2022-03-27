#include <iostream>
#include <math.h>
#include<vector>
#include<string>
using namespace std;
int main() {
	long long n;
	cin >> n;
	string s;
	cin >> s;
	long long k = 0, k2 = 0;
	for (long long i = 0; i < s.size(); i++) {
		if (s[i] == 'n') {
			k++;
		}
		if (s[i] == 'z') {
			k2++;
		}
	}
	for (long long i = 0; i < k; i++) {
		cout << 1 << ' ';
	}
	for (long long i = 0; i < k2; i++) {
		cout << 0 << ' ';
	}
}