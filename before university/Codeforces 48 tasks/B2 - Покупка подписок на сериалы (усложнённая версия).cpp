#include <iostream> 
 
#include <vector> 
#include <string> 
#include <map> 
 
#include <set> 
#include <unordered_set> 
#include <stack> 
#include <queue> 
#include <algorithm> 
 
#define IOS ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
#define endl "\n"; 
typedef long long ll;
typedef unsigned long long ull;
#pragma warning(disable : 4996) // ддя printf scanf 
using namespace std;
ll power(ll a, ll b)
{
	if (b == 0)
		return 1;
	if (b % 2)
		return (power(a, b - 1) * a);
	else {
		ll t = power(a, b / 2);
		return (t * t);
	}
}
bool prime(int a)
{
	if (a == 2)
		return true;
	for (int i = 2; i * i <= a; ++i)
		if (a % i == 0)
			return false;
	return true;
}
vector <bool> used;
vector < vector < int>> g;
void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < g[v].size(); ++i)
		if (!used[g[v][i]])
			dfs(g[v][i]);
}
int main()
{
	
	int t;
	cin>> t;
	while (t--) {
		int n2, k, d;
		cin>> n2>> k>> d;
		vector <int> g(n2);
		for (int i = 0; i < n2; ++i)
			cin >> g[i];
		set <int> st;
		map <int, int> cn;
		for (int i = 0; i < d; ++i)
			st.insert(g[i]), cn[g[i]]++;
		ll ans = (ll)st.size();
		for (int i = d; i < n2; ++i) {
			cn[g[i - d]]--;
			if (cn[g[i - d]] == 0)
				st.erase(g[i - d]);
			cn[g[i]]++;
			st.insert(g[i]);
			ans = min(ans, (ll)st.size());
		}
 
		cout<< ans << endl;
	}
	return 0;
}