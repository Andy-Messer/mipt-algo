#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
int n, m, counter; bool flag = false;
vector <bool>used;
vector <int>color;

vector<vector <int>> GR;

int invert(int c) {
	if (c == 0)return 1;
	return 0;
}

void dfs(int v, int p,int c) {
	used[v] = true;
	color[v] = c;
	for (int i = 0; i < GR[v].size(); i++) {
		int to = GR[v][i];
		if (color[to] == color[v])flag = true;
		if (!used[to])
			dfs(to, v,invert(c));
		}
	}

void pokraska() {
	used.resize(n, false);
	for (int i = 0; i < n; i++) {
		if (used[i]==false)
		dfs(i,-1, 1);
	}
}
int main() {
	cin >> n >> m; counter = 0;
	GR.resize(n, vector<int>());
	used.resize(n, false);
	color.resize(n, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		GR[b].push_back(a);
		GR[a].push_back(b);
	}
	pokraska();
	if (!flag) {
		for (int i = 0; i < n; i++) {
			int f = i;
			if (color[i] == 1) cout << ++f << ' ';
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			int f = i;
			if (color[i] == 0) cout << ++f << ' ';
		}
		cout << endl;
	}
	else {
		cout << 0;
	}

}