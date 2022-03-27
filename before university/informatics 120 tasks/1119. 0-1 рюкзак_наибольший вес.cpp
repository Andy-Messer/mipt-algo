#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
vector<long long> a;
bitset<10001>dp;
int main() {
	long long n, m;
	cin >> n >> m;
	dp.reset();
	vector<long long>a(n);
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = 1;
	for (long long j = 0; j < n; j++) {
		dp |= dp << a[j];
	}
	bool flag = 1;
	for (long long i = m; (i >= 0) && flag == 1; i--) {
		if (dp[i]==1) {
			cout << i; flag = 0;
		}
	}
}