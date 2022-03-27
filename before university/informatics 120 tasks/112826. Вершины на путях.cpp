#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
int n, m, timer, counter;
vector <bool>used;
vector <int>tin;
vector <int>fup;
vector <int>CUTPOINT;
vector<vector <int>> GR;
vector<int>maper; vector<int>answer;
void dfs_second(int v, int b) {
	
		used[v] = true; maper.push_back(v);
		for (int i = 0; i < GR[v].size(); i++) {
			if (!used[GR[v][i]]) {
				dfs_second(GR[v][i], b);
			}
		}
		maper.pop_back();
	if(v==b)
		answer = maper;
}
void dfs(int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;
	for (size_t i = 0; i < GR[v].size(); ++i) {
		int to = GR[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] >= tin[v] && p != -1)
				CUTPOINT[v] = 1;
			++children;
		}
	}
	if (p == -1 && children > 1)
		CUTPOINT[v] = 1;
}


int main() {
	cin >> n >> m; counter = 0;
	for (int i = 0; i < n; i++) {
		used.push_back(false);
		tin.push_back(0);
		fup.push_back(0);
		GR.push_back(vector <int>());
	}
	CUTPOINT.resize(n, -1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		GR[a].push_back(b);
		GR[b].push_back(a);
	}
	int q, a, b;
	cin >> q;
	timer = 0;
	used.assign(n, false);
	dfs(0);
	vector<int>ans;
	for (int i = 0; i < q; i++) {
		cin >> a >> b; a--; b--;
		maper.clear(); answer.clear();
		used.assign(n, false);
		dfs_second(a, b);
		counter = 0; int d = 0;
		


		if (used[b] == true) {
			for (int i2 = 0; i2 < n; i2++) {
				if (used[i2] == true) {
					d++;
				}
			}
			counter = d;
		}
		ans.push_back(counter);
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}