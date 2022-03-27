#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
int n, m, timer, counter;
vector <bool>used;
vector <int>tin;
vector <int>fup;
vector<vector <int>> GR;
vector <int> comp;
void dfs(int v, int p) {
	used[v] = true;
	comp.push_back(v);
	tin[v] = fup[v] = timer++;
	for (int i = 0; i < GR[v].size(); i++) {
		int to = GR[v][i];
		if (p == to) {
			continue;
		}
		if (used[to])
			fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v])
				counter++;
		}
	}
}
void find_bridg() {
	timer = 0;
	for (int i = 0; i < n; i++) {
		used[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		if (!used[i]) {
			dfs(i, -1);
		}
	}
}
int find_kol_comps() {
	int counter2 = 0;
	for (int i = 0; i < n; ++i)
		used[i] = false;
	for (int i = 0; i < n; ++i)
		if (!used[i]) {
			
			dfs(i, -1);

			counter2++;
		}
	return counter2;
}
void find_comps() {
	for (int i = 0; i < n; ++i)
		used[i] = false;
	for (int i = 0; i < n; ++i)
		if (!used[i]) {
			comp.clear();
			dfs(i,-1);

			cout << comp.size()<<endl;
			for (size_t j = 0; j < comp.size(); ++j)
				cout << ' ' << ++comp[j];
			cout << endl;
		}
}
int main() {
	cin >> n >> m; counter = 0;
	for (int i = 0; i < n; i++) {
		used.push_back(false);
		tin.push_back(0);
		fup.push_back(0);
		GR.push_back(vector <int>());
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		GR[a].push_back(b);
		GR[b].push_back(a);
	}
	cout <<find_kol_comps()<<endl;
	find_comps();
}