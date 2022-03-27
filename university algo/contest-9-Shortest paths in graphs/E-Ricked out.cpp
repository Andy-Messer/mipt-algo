#include <iostream>
#include <vector>

const long long inf = 9223372036854775800;
typedef long long ll;
typedef long double ld;

struct Edge {
    long long x;
    long long y;
    long double r;
    long double c;

    Edge(ll X, ll Y, ld R, ld C) : x(X), y(Y), r(R), c(C) {};
};

int main() {
    ll N, M, S;
    ld V;
    std::cin >> N >> M >> S >> V;
    S--;
    std::vector<Edge> edges;
    std::vector<long double> distances(N, -inf);
    distances[S] = V;
    long long x, y;
    ld RAB, CAB, CBA, RBA;
    for (long long i = 0; i < M; i++) {
        std::cin >> x >> y >> RAB >> CAB >> RBA >> CBA;
        x--;
        y--;
        edges.push_back({x, y, RAB, CAB});
        edges.push_back({y, x, RBA, CBA});
    }
    for (long long i = 0; i < N - 1; ++i) {
        for (long long j = 0; j < 2 * M; ++j) {
            long double &from = distances[edges[j].x];
            long double &to = distances[edges[j].y];
            long double cost = (from - edges[j].c) * edges[j].r;
            if (from > -inf) {
                to = std::max(to, cost);
            }
        }
    }
    std::vector<long long> c;
    for (long long j = 0; j < 2 * M; ++j) {
        long double &from = distances[edges[j].x];
        long double &to = distances[edges[j].y];
        long double cost = (from - edges[j].c) * edges[j].r;
        if (from > -inf) {
            if (to < cost) {
                std::cout << "YES";
                return 0;
            }
        }
    }
    std::cout << "NO";
    return 0;
}