#include<iostream>
#include<bitset>
#include <string>
#include<sstream>
using namespace std;
const long long N = 100000;
bitset<N>b, a;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n; cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);
	b.reset();
	for (long long i = 1; i <= n; i++) {
		b[i] = 1;
	}
	a.reset(); 
	while (s != "HELP") {
		istringstream S(s);
		int j;
		while (S >> j) {
			a[j] = 1;
		}
		getline(cin, s);
		if (s == "YES") {
			b = b & a;
		}
		else {
			b = b & (~a);
		}a.reset();
		getline(cin, s);
	}
	for (long long i = 0; i < N; i++) {
		if (b[i] == 1) {
			cout << i<<' ';
		}
	}
}