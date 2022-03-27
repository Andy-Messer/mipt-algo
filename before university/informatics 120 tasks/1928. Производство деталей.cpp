#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;
long long n, m, timer, counter;
vector <bool>used;
//vector <int>tin;
//vector <int>fup;
vector<vector <int>> GR;
vector <int> comp;
vector <long long> mass;
void dfs(int v, int p) {
	used[v] = true;
	
	/*tin[v] = fup[v] = timer++;*/
	for (int i = 0; i < GR[v].size(); i++) {
		int to = GR[v][i];
		/*if (p == to) {
			continue;
		}
		if (used[to])
			fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v])
				counter++;
		}*/
		if (!used[to]) {
			dfs(to, v);
		}
	}
	comp.push_back(v);
}
//void find_bridg() {
//	timer = 0;
//	for (int i = 0; i < n; i++) {
//		used[i] = false;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (!used[i]) {
//			dfs(i, -1);
//		}
//	}
//}
long long find_mass_of_comp(int v) {
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		used[i] = false;
	dfs(v, -1);
	for (int i = 0; i < n; ++i)
		if (used[i]) {
			ans += mass[i]; counter++;
		}
	return ans;
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
void find_comps(int v) {
	for (int i = 0; i < n; ++i)
		used[i] = false;
	
			comp.clear();
			dfs(v, -1);

			
			for (size_t j = 0; j < comp.size(); ++j)
				cout << ++comp[j] << ' ';
			cout << endl;
}
int main() {
	cin >> n; counter = 0;
	//////////////////////////////////////////
	for (int i = 0; i < n; i++) {
		used.push_back(false);
		/*tin.push_back(0);
		fup.push_back(0);*/
		GR.push_back(vector <int>());
	}
	////////////////////////////////////////////////
	for (int i = 0; i < n; i++) {
		long long b; cin >> b;
		mass.push_back(b);
	}
	///////////////////////////////////////////////////
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			a--;
			GR[i].push_back(a);
		}
	}
	cout << find_mass_of_comp(0); 
	cout<< ' ' << counter << endl;
	find_comps(0);
}