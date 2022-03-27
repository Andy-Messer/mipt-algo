#include<iostream>
#include<vector>
using namespace std;
long long n;

vector <long long> matrix_and(vector<long long>e, long long d) {
	vector<long long>f(n, 0);
	for (long long i = 0; i < n; i++) {
		f[i] = e[i] & d;
	}
	return f;
}
vector<long long> search_point(vector<long long>e, long long d) {
	for (long long i = 0; i < n; i++) {
		if (e[i] != 0) {
			for (long long j = 0; j < n; j++) {
				if (((e[i] >> j) & 1) == 1) {
					if (((d >> i) & 1) == 1) {
						vector <long long>loc(2); loc[0] = i; loc[1] = j;
						return loc;
					}
				}
			}
		}
	}
	vector <long long>loc(2); loc[0] = -1; loc[1] = -1;
	return loc;
}
int main() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (a ^ b) << endl;
	cout << (c ^ d);
}