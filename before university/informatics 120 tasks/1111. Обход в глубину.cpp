#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
vector <int> b; int n, m;
map<int, pair<int, int>> f;
vector <int> used_f; vector<int>count_list;
vector <vector <int>>gr;
vector <int> comp;
void rev_dfs(int v) {
	comp.push_back(v); used_f[v] = 1;
	for (int i = f[v].first; i < f[v].second; i++) {
		if (used_f[b[i]] == 0) {
			rev_dfs(b[i]);
		}
	}
	if (comp.size() > 1) {
		for (int i = comp.size() - 2; i >= 0; i--) {
			if (comp[i+1]<=v)
			gr[comp[i]].push_back(v);
		}
	}
	comp.pop_back();
}
int main() {


	cin >> n >> m;
	count_list.resize(n + 1, 0);
	used_f.resize(n + 1, 0);
	gr.resize(n + 1, vector<int>());
	b.push_back(0);
	for (int i = 1; i <= n; i++) {
		f[i] = { -1,-1 };
	}
	for (int i = 1; i <= m; i++) {
		int c;
		cin >> c;
		b.push_back(c);
		count_list[c]++;
		if (f[c].first == -1) {
			f[c].first = i;
		}
		else {
			f[c].second = i;
		}
	}

	for (int i = 1; i <= f.size(); i++) {
		if (used_f[i] == 0) {

			rev_dfs(b[f[i].first]);

		}
	}
	int sum = 0;
	for (int i = 0; i < n + 1; i++) {
		sum += gr[i].size();
	}
	cout << sum << '\n';
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < gr[i].size(); j++) {
			cout << i << ' ' << gr[i][j] << endl;
		}
	}

	return 0;
}