#include <iostream>
#include <vector>

const long long inf = 9223372036854775807;

std::vector<std::vector<long long>> graph;

std::vector<char> ans;

void dfs(long long v) {
    ans[v] = '-';
    for (auto to:graph[v]) {
        if (ans[to] != '-') {
            dfs(to);
        }
    }
}

int main() {
    struct Edge {
        long long x;
        long long y;
        long long cost;
    };
    long long n, m, s;
    std::vector<Edge> edges;
    std::cin >> n >> m >> s;
    s--;
    ans.assign(n, '+');
    graph.assign(n, std::vector<long long>());
    std::vector<long long> distances(n, inf);
    distances[s] = 0;
    long long x, y, cost;
    for (long long i = 0; i < m; i++) {
        std::cin >> x >> y >> cost;
        x--;
        y--;
        graph[x].push_back(y);
        edges.push_back({x, y, cost});
    }
    for (long long i = 0; i < n - 1; ++i) {
        for (long long j = 0; j < m; ++j) {
            long long &from = distances[edges[j].x];
            long long &to = distances[edges[j].y];
            long long &cost = edges[j].cost;
            if (from < inf) {
                to = std::min(to, from + cost);
            }
        }
    }
    std::vector<long long> c;
    for (long long j = 0; j < m; ++j) {
        long long &from = distances[edges[j].x];
        long long &to = distances[edges[j].y];
        long long &cost = edges[j].cost;
        if (from < inf) {
            if (to > from + cost) {
                ans[edges[j].y] = '-';
                to = from + cost;
                c.push_back(edges[j].y);
                c.push_back(edges[j].x);
            }
        }
    }
    for (auto &x:c) {
        dfs(x);
    }
    for (long long i = 0; i < n; i++) {
        if (distances[i]==inf){
        	std::cout<<"*"<<"\n";
        } else if (ans[i]=='+'){
        	std::cout <<distances[i]<<"\n";
        } else
        std::cout<<"-\n";
    }
}