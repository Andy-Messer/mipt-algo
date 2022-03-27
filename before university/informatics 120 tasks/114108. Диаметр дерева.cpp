#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>
#include<climits>
using namespace std;
long long n, m,line,r;
vector <bool>used;
vector<vector <int>> GR;
void dfs(int v,int k) {
	used[v] = true;k=k+1;
	for (int i = 0; i < GR[v].size(); i++) {
		int to = GR[v][i];
		if (!used[to]) {
			dfs(to,k);
		}
	}
	if (k>line){
		line=k;r=v;
	}
}
int Tree_size(){
	used.assign(n,false);
	line=0;
	dfs(0,0);
	used.assign(n,false);
	line=0;
	dfs(r,0);
	return line;
}
int main() {
	cin >> n;
	GR.resize(n,vector<int>());
	used.resize(n,false);
	for (int i = 0; i < n-1; i++) {
		int a,b;
		cin >>a>>b;
		a--;b--;
		GR[a].push_back(b);
		GR[b].push_back(a);
	}
	cout<<Tree_size()-1;
}
