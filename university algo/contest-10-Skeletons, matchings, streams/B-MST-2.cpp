#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int gl(int &v, vector<int> &f) {
    if (v == f[v]) {
        return v;
    } else {
        return f[v] = gl(f[v], f);
    }
}

void DSU(int a, int b, vector<int> &f) {
    a = gl(a, f);
    b = gl(b, f);
    if (rand() & 1) {
        swap(a, b);
    }
    if (a != b) {
        f[a] = b;
    }
}

void Find_min_tree(
        vector<int> &f,
        vector<pair<int, pair<int, int>>> &a,
        int &n, int &m, int &ans) {

    sort(a.begin(), a.end());
    for (auto &i:a) {
        if (gl(i.second.first, f) != gl(i.second.second, f)) {
            ans += i.first;
            DSU(i.second.first, i.second.second, f);
        }
    }
}

int main() {

    int n, k = 0, m, ans = 0;
    cin >> n >> m;
    vector<int> f;
    vector<pair<int, pair<int, int>>> a;
    for (int i = 0; i < n; i++) {
        f.push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int b, c, d;
        cin >> b >> c >> d;
        b--;
        c--;
        a.push_back({d, {b, c}});
    }
    Find_min_tree(f, a, n, m, ans);
    cout << ans;
    return 0;
}