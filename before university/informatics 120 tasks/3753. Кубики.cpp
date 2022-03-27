#include <iostream>
#include <set>
#include<iterator>
#include <algorithm>
using namespace std;
set <long long> a, b, c, d;
int main() {
	long long n, m;
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		long long now;
		cin >> now;
		a.insert(now);
	}
	for (long long i = 0; i < m; i++) {
		long long now;
		cin >> now;
		b.insert(now);
	}
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(d, d.begin()));
	set_difference(a.begin(), a.end(), d.begin(), d.end(), inserter(c, c.begin()));
	a.clear();
	set_difference( b.begin(), b.end(),d.begin(), d.end(), inserter(a, a.begin()));
	cout << d.size() << endl;
	for (auto x:d) {
		cout << x<<' ';
	}
	cout << endl;
	cout << c.size() << endl;
	for (auto x : c) {
		cout << x<<' ';
	}
	cout << endl;
	cout << a.size() << endl;
	for (auto x : a) {
		cout << x<<' ';
	}
	return 0;
}