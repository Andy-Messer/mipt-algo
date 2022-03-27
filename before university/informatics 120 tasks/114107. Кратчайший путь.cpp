#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
#include<climits>
using namespace std;
long long n, m,s,t;
vector <bool>used;
vector<vector <pair <int,int>>> GR;
vector <int> comp;
vector <long long> dp;
void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < GR[v].size(); i++) {
		int to = GR[v][i].first;
		if (!used[to]) {
			dfs(to);
		}

	}
	for (int i = 0; i < GR[v].size(); i++) {
		int to = GR[v][i].first;
		if (dp[to]!=LLONG_MAX){
			dp[v] = min(dp[v], dp[to] + GR[v][i].second);
		}
	}
}

int main() {
	cin >> n >> m >> s >> t;
	s--;
	t--;


	GR.resize(n, vector<pair<int, int>>());
	used.resize(n, false);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		GR[a].push_back({b, c});
	}
	dp.resize(n, LLONG_MAX);
	dp[t] = 0;
	used[t] = 1;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}
	if (dp[s] != LLONG_MAX){
		cout << dp[s];
	}else {
		cout << "Unreachable";
	}
}
