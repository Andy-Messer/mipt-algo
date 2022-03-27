#include <iostream>
#include<queue>
#include<vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::min;
typedef long long ll;

ll n, m, timer, counter;
vector <bool>used;
vector <ll>tin;
vector <ll>fup;
vector <ll>CUTPOINT;
vector<vector <ll>> GR;

void dfs(ll v, ll p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    ll children = 0;
    for (size_t i = 0; i < GR[v].size(); ++i) {
        ll to = GR[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1)
                CUTPOINT[v] = 1;
            ++children;
        }
    }
    if (p == -1 && children > 1)
        CUTPOINT[v] = 1;

}


int main() {
    cin >> n >> m; counter = 0;
    for (ll i = 0; i < n; i++) {
        used.push_back(false);
        tin.push_back(0);
        fup.push_back(0);
        GR.push_back(vector <ll>());
    }
    CUTPOINT.resize(n, -1);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        GR[a].push_back(b);
        GR[b].push_back(a);
    }
    ll q,a,b;
    cin >> q;
    timer = 0;
    used.assign(n, false);
    for(ll i=0;i<n;i++){
        if (!used[i])
            dfs(i);
    }
    std::vector <long long> ans;
    for (ll i=0;i<n;++i){
        if (CUTPOINT[i]!=-1){
            ans.push_back(i+1);
        }
    }
    std::cout<<ans.size()<<'\n';
    for(auto &x:ans)
        std::cout<<x<<' ';
}