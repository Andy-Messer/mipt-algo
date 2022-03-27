#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

vector<vector<long long>> GR_t, GR;
long long n, m;
vector<long long> used;
vector<long long> ord;
vector<long long> comp;

void dfs_top_sort(long long v) {
    used[v] = 1;
    for (auto &x:GR[v]) {
        if (!used[x]) {
            dfs_top_sort(x);
        }
    }
    ord.push_back(v);
}

void dfs_find_comp(long long v) {
    used[v] = 1;
    comp.push_back(v);
    for (auto &x:GR_t[v]) {
        if (!used[x]) {
            dfs_find_comp(x);
        }
    }
}

int main() {
    cin >> n >> m;
    long long a, b;
    GR.resize(n);
    GR_t.resize(n);
    used.resize(n, 0);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        GR[a].push_back(b);
        GR_t[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs_top_sort(i);
        }
    }

    std::reverse(ord.begin(), ord.end());
    used.assign(n, 0);

    vector<long long> ans(n, -1);
    long long count = 0;
    for (int i = 0; i < n; i++) {
        long long v = ord[i];
        if (!used[v]) {
            dfs_find_comp(v);
        }
        for (auto &x:comp) {
            ans[x] = count;
        }
        count++;
        comp.clear();
    }
    std::set<std::pair<long long, long long>> d;
    for (long long index_pr = 0; index_pr < n; ++index_pr) {
        for (auto &x:GR[index_pr]) {
            if (ans[index_pr] != ans[x] && ans[x] != -1 &&
                ans[index_pr] != -1) {
                d.insert({ans[index_pr], ans[x]});
            }
        }
    }
    std::cout << d.size();
}