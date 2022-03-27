#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n,m,bridges,timer;
vector <vector<pair<int,int>>>g;vector <bool> used;vector<pair<int,int>> f;
vector <int> fup,tin,ans;map <pair<int,int>,int>cr;
void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i].first;
		if (to == p)  continue;
		if (used[to]) {
			fup[v] = min(fup[v], tin[to]);
		}else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v]){
				if (cr[{to,v}]<2){
				bridges++;
				ans.push_back(g[v][i].second);
				}
			}
		}
	}
}
int main(){
	cin >>n>>m;bridges=0;
	g.resize(n,vector<pair<int,int>>());
	used.resize(n,false);
	fup.resize(n,0);
	tin.resize(n,0);
	f.resize(m,pair<int,int>());
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;a--;b--;
		f[i].first=a;f[i].second=b;
		cr[{a,b}]=0;
		cr[{b,a}]=0;
		g[a].push_back({b,i});
		g[b].push_back({a,i});
	}
	for (int i=0;i<m;i++){
		cr[{f[i].first,f[i].second}]++;
		cr[{f[i].second,f[i].first}]++;
	}
	timer=0;
	for (int i=0; i<n; ++i){
		if (!used[i]){
			dfs (i);
		}
	}
	cout <<bridges<<endl;
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout << ++ans[i]<<' ';
	}
}