#include<iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

typedef long long ll;
typedef std::vector<ll> V;
typedef std::vector<V> VV;


void
DFS(ll v, VV &GR, V &used, V &color, bool &flag, ll pr, ll &vertex_to_restore) {
    used[v] = pr;
    color[v] = 1;
    for (int i = 0; i < GR[v].size() && !flag; ++i) {
        ll to = GR[v][i];
        if (used[to] != -1 && color[to] == 1) {
            flag = 1;
            used[to] = v;
            vertex_to_restore = v;
        } else {
            DFS(to, GR, used, color, flag, v, vertex_to_restore);
        }
    }
    color[v] = 2;
}

bool FindCircle(VV &GR, V &used, V &color) {
    bool flag = false;
    ll vTr = 0;
    for (int i = 0; i < used.size() && !flag; i++) {
        if (used[i] == -1) DFS(i, GR, used, color, flag, -1, vTr);
    }
    if (!flag) {
        cout << "NO";
        return false;
    } else {
        cout << "YES" << "\n";
        vector<int> ans;
        ans.push_back(vTr + 1);
        int old = vTr;
        while (used[vTr] != old) {
            ans.push_back(used[vTr] + 1);
            vTr = used[vTr];
        }
        std::reverse(ans.begin(), ans.end());
        for (auto it : ans) {
            cout << it << ' ';
        }
        return true;
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll x, y;
    VV GR(n, V());
    V used(n, -1);
    V color(n, -1);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--;
        y--;
        GR[x].push_back(y);
    }
    FindCircle(GR, used, color);
}