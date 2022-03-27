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
vector <int> color;
bool flag = true;
void dfs(int v, int p) {
	used[v] = true;
	color[v] = 0;
	comp.push_back(v);
	tin[v] = fup[v] = timer++;
	for (int i = 0; i < GR[v].size(); i++) {
		int to = GR[v][i];
		if (color[to] == 0) {
			flag = false;
		}
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
	color[v] = 1;
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
			dfs(i, -1);
		}
}
int main() {
	cin >> n; counter = 0;
	for (int i = 0; i < n; i++) {
		used.push_back(false);
		tin.push_back(0);
		fup.push_back(0);
		GR.push_back(vector <int>());
	}
	color.resize(n, -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1)
				GR[i].push_back(j);
		}
	}
	find_comps();
	if (flag == false) {
		cout << 1;
	}
	else { cout << 0; }
}