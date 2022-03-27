#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<long long> vec;
typedef std::vector<std::vector<long long>> vec2;

void dfs(long long vertex, long long pr, long long &timer, vec2 &graph, vec &t_in, vec &t_out, vec &used) {
    t_in[vertex] = timer++;
    used[vertex] = 1;
    for (auto &x:graph[vertex]) {
        if (!used[x]) {
            dfs(x, vertex, timer, graph, t_in, t_out, used);
        }
    }
    used[vertex] = 0;
    t_out[vertex] = ++timer;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<long long>> graph(n, std::vector<long long>());
    std::vector<long long> t_in(n, 0);
    std::vector<long long> t_out(n, 0);
    std::vector<long long> used(n, 0);
    long long root_vertex = 0;
    long long timer = 0;

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;

        if (a == 0) {
            root_vertex = i;
            continue;
        }
        a--;
        graph[i].push_back(a);
        graph[a].push_back(i);
    }
    long long m;
    std::cin >> m;
    dfs(root_vertex, -1, timer, graph, t_in, t_out, used);

    for (int i = 0; i < m; i++) {
        long long pr, v;
        std::cin >> pr >> v;
        pr--;
        v--;
        std::cout << ((t_in[pr] < t_in[v] && t_out[pr] > t_out[v]) ? 1 : 0) << "\n";
    }
}