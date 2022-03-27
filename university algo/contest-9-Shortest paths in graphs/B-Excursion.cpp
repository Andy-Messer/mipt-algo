#include <iostream>
#include <vector>
#include <queue>
#include <map>

typedef long long ll;
typedef std::pair<ll, ll> p_ll;
typedef std::vector<ll> v_ll;
typedef std::vector<p_ll> v_pll;
using std::vector, std::cin, std::cout, std::queue;

vector<v_ll> graph;
ll n, m, a, b, c;

void DropEdge(ll a, ll b, ll c) {
    ll sz = graph.size();
    graph[a].push_back(graph.size());
    for (int i = 0; i < c - 1; i++) {
        graph.push_back(v_ll());
        if (i < c - 2)
            graph.back().push_back(graph.size());
        if (i > 0) {
            graph.back().push_back(graph.size() - 2);
        }
    }
    graph[sz].push_back(a);
    graph[b].push_back(graph.size() - 1);
    graph.back().push_back(b);
}

ll BFS(ll v) {
    queue<p_ll> q;
    q.push({-1, v});
    v_ll used(graph.size(), -1);
    used[v] = 0;
    while (!q.empty()) {
        ll now = q.front().second;
        ll pr = q.front().first;
        if (pr != -1)
            used[now] = used[pr] + 1;
        q.pop();
        for (auto &to:graph[now]) {
            if (used[to] == -1) {
                q.push({now, to});
            } else {
                if (pr != to)
                    return used[now] + used[to] + 1;
            }
        }
    }
    return 1000000000000000;
}

int main() {
    std::cin >> n >> m;
    graph.assign(n, v_ll());
    std::map<p_ll, int> f;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b >> c;
        a--;
        b--;
        if (c > 1) {
            DropEdge(a, b, c);
        } else {
            graph[a].push_back(b);
            graph[b].push_back(a);
            f[{a, b}] += 1;
            f[{b, a}] += 1;
        }
    }
    bool flag = 0;
    for (auto &x:f) {
        if (x.second > 1) {
            flag = 1;
        }
    }
    if (flag)std::cout << 2;
    else {
        ll ans = 123124123214;
        for (int i = 0; i < n; i++) {
            ans = std::min(ans, BFS(i));
        }
        std::cout << ans;
    }
}