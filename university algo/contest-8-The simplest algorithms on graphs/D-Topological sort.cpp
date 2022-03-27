#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::vector;
using std::cin;
using std::cout;
using std::stack;

typedef long long ll;
typedef vector<ll> V;
typedef vector<V> VV;
typedef stack<ll> S;

void DFS(ll v, bool &flag, VV &gr, V &used, V &color, S &top_sort) {
    used[v] = 1;
    color[v] = 1;
    for (int i = 0; i < gr[v].size(); i++) {
        ll x = gr[v][i];
        if (color[x] == 1) {
            flag = 1;
        } else {
            if (!used[x]) {
                DFS(x, flag, gr, used, color, top_sort);
            }
        }
    }
    top_sort.push(v);
    color[v] = 2;
}

int main() {
    ll n, m, a, b;
    cin >> n >> m;
    VV gr(n, V());
    V used(n, 0);
    V color(n, 0);
    S top_sort;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        gr[a].push_back(b);
    }
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i])
            DFS(i, flag, gr, used, color, top_sort);
    }
    if (!flag) {
        V ans;
        while (!top_sort.empty()) {
            ans.push_back(top_sort.top());
            top_sort.pop();
        }
        for (auto &x: ans) {
            cout << x + 1 << " ";
        }
    } else {
        cout << -1;
    }
}