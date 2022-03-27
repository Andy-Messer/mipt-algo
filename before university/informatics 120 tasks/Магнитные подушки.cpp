
#include<iostream>
#include <vector>
#include<math.h>
#include<climits>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<string>
#include<fstream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <numeric>
#include <bitset>

#define IOS ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl "\n";

typedef long long ll;
typedef long double ld;
const ll INF = 1e9 + 7;
const ll INF_bit = 1e9 - 1;
const ld EPS = 0.000000001;
typedef unsigned long long ull;
typedef std::string str;
typedef std::vector<long long> vec;
typedef std::vector<bool> vec_b;
typedef std::bitset <INF_bit> bit;
typedef std::vector<std::pair<long long, long long>> pvec;
typedef std::vector<std::vector<long long>> vec2;

#pragma warning(disable : 4996)
vec used,f,r,CUTPOINT;
ll timer,n,m;
vec2 GR;

void dfs(ll v,ll p=-1) {
	used[v] = 1;
	f[v] = r[v] = timer++;
	ll child = 0;
	for (ll i = 0; i < GR[v].size(); i++){
		ll to = GR[v][i];
		if (to == p)  continue;
		if (used[to]) {
			r[v] = std::min(r[v], f[to]);
		}
		else{
			dfs(to, v);
			r[v] = std::min(r[v], r[to]);
			if ((r[to] >= f[v]) && (p != -1)) CUTPOINT[v] = 1;
			child++;
		}

	}

	if ((p == -1) && (child > 1)) CUTPOINT[v] = 1;
}
int main() {
	std::cin >> n >> m;
	
	GR.resize(n+m + 1, std::vector<ll>());
	r.resize(n+m + 1, 0);
	f.resize(n+m + 1, 0);
	used.resize(n+m + 1, 0);
	CUTPOINT.resize(n+m+1, 0);

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
	
		GR[n+i].push_back(b);
		GR[a].push_back(n+i);
		GR[b].push_back(n+i);
		GR[n+i].push_back(c);
		GR[n+i].push_back(a);
		GR[c].push_back(n+i);
	}

	for (ll i = 1; i <= n + m; i++) {
		if (!used[i])dfs(i);
	}

	ll c_CUTPOINT = 0;
	for (ll i = n + 1; i <= n + m; i++) {
		if (CUTPOINT[i])c_CUTPOINT++;
	}
	std::cout << c_CUTPOINT<<endl;
	if (c_CUTPOINT) {
		for  (ll i=n+1;i<=n+m;i++)
		{
			if (CUTPOINT[i]) {
				std::cout << i - n<<' ';
			}
		}
		std::cout << endl;
	}

	timer = 0;
}