#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
const long long INF = 1000000000;
vector<long long> a;
vector <long long>dp;
int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long>a(n);
	vector <long long>dp(m+1, INF);
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = 0;
	for (long long j = 0; j < n; j++) {
		for (long long i = m; i >= 0; i--) {
			if (i - a[j] >= 0) {
				dp[i] = min(dp[i - a[j]] + 1, dp[i]);
			}
		}
	}
	if (dp[m] == INF) {
		cout << 0;
	}
	else {
		cout << dp[m];
	}
}