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
	vector <long long>c(n);
	vector <vector<long long>>dp(m+1,vector<long long>(n+1,0));
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (long long i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (long long j = 0; j < n; j++) {
		for (long long i = 0; i<=m; i++) {
			if (i - a[j] >= 0) {
				dp[i][j+1] = max(dp[i - a[j]][j]+c[j], dp[i][j]);
			}
			else {
				dp[i][j + 1] = dp[i][j];
			}
		}
	}
	
	cout << dp[m][n];
}