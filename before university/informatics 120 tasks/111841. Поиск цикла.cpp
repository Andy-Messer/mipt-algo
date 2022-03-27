#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm> 
#include <stdlib.h> 
#include <stack> 
#include <queue> 
/*-----------------------*/
using namespace std;
/*---------VAR-----------*/
vector <vector<int>> g;
vector<int>used;
int n, flag = 1, num;
/*--------FUNCTIONS------*/
void DFS(int v, int pr) {
	used[v] = pr;
	for (int i = 0; i < n && flag; i++) {
		if (g[v][i] == 1 && i != pr) {
			if (used[i] != -1) {
				flag = 0;
				used[i] = v;
				num = v;
			}
			else {
				DFS(i, v);
			}
		}
	}
}
/*------------MAIN-------*/
int main() {
	cin >> n;
	g.resize(n, vector<int>(n));
	used.resize(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < n && flag; i++) {
		if (used[i] == -1) DFS(i, i);
	}
	if (flag) { cout << "NO"; }
	else {
		cout << "YES" << endl;
		vector<int> ans;
		ans.push_back(num + 1);
		int old = num;
		while (used[num] != old) {
			ans.push_back(used[num] + 1);
			num = used[num];
		}
		cout << ans.size() << endl;
		for (auto it : ans) {
			cout << it << ' ';
		}
	}
}