#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
vector<vector<int>> GRt,GR;
vector <bool>used;
vector <int> comp, loc;
int n, m;
void dfs_first(int v) {
	used[v] = true;
	for (int i = 0; i < GR[v].size(); i++) {
		if (!used[GR[v][i]]) {
			dfs_first(GR[v][i]);
		}
		
	}loc.push_back(v);
}
void dfs_second(int v) {
	used[v] = true;comp.push_back(v);
	for (int i = 0; i < GRt[v].size(); i++) {
		if (!used[GRt[v][i]]) {
			dfs_second(GRt[v][i]);
		}
	}
	
}
int main() {
	cin >> n >> m;
	used.resize(n,false);
	GR.resize(n, vector<int>()); GRt.resize(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		GR[a].push_back(b);
		GRt[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs_first(i);
		}
	}
	used.assign(n, false); int count = 0;
	vector <int> ans(n, -1);
	for (int i = 0; i < n; i++) {
		int v = loc[n - 1 - i];
		if (!used[v]) {
			++count;
			dfs_second(v);
			for (int i = 0; i < comp.size(); i++) {
				ans[comp[i]] = count;
			}
			comp.clear();
		}
	}
	cout << count<<endl;
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}
