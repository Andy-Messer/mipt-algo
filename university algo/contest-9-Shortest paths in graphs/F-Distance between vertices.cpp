#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> g;
int n, a, b, f;
const long long inf = 200000003;

int main() {
    int s2, m;
    cin >> n >> m >> a >> f;
    a--;
    f--;
    g.resize(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int c, a2;
        cin >> a2 >> b >> c;
        a2--;
        b--;
        g[a2].push_back({c, b});
        g[b].push_back({c, a2});
    }
    set<pair<int, int>> s;
    vector<long long> d(n, inf);
    vector<int> pred(n, -1);
    d[a] = 0;
    s.insert({0, a});
    while (!s.empty()) {
        pair<int, int> now = *s.begin();
        int to = now.second;
        int ves = d[to];
        s.erase(s.begin());
        for (auto now_2:g[to]) {
            int ves_2 = now_2.first;
            int to_2 = now_2.second;
            if (ves + ves_2 < d[to_2]) {
                s.erase({d[to_2], to_2});
                d[to_2] = ves + ves_2;
                pred[to_2] = to;
                s.insert({d[to_2], to_2});
            }
        }
    }
    if (d[f] == inf)
        std::cout << -1;
    else
        std::cout << d[f];
}