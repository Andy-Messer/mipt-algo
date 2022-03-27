#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<int> viz;
    std::vector<std::pair<int, std::pair<int, int>>> edges;
    int n, m;
    std::cin >> n;
    std::cin >> m;
    int v, u, x;
    viz.resize(n, 0);
    for (int i = 0; i < m; ++i) {
        std::cin >> v >> u >> x;
        v--;
        u--;
        edges.push_back({x, {v, u}});
    }
    std::sort(edges.begin(), edges.end());
    viz[0] = 1;
    long long count = 1;
    long long ans = 0;
    while (count < n) {
        for (auto &edge:edges) {
            if (viz[edge.second.first] == 1 && viz[edge.second.second] == 0) {
                ans += edge.first;
                count++;
                viz[edge.second.second] = 1;
                break;
            }
            if (viz[edge.second.second] == 1 && viz[edge.second.first] == 0) {
                ans += edge.first;
                count++;
                viz[edge.second.first] = 1;
                break;
            }
        }
    }
    std::cout << ans;
}