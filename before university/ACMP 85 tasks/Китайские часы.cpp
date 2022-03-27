#include<iostream>
#include <vector>
#include<math.h>
#include<climits>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<string>
#include<fstream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <numeric>
#include <bitset>
 
#define IOS std::ios_base::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define endl "\n";
 
typedef long long ll;
typedef long double ld;
const ll INF = 1e9 + 9;
const ll INF_bit = 1e9 - 1;
const ld EPS = 0.000000001;
typedef unsigned long long ull;
typedef std::string str;
typedef std::vector<long long> vec;
typedef std::vector<bool> vec_b;
typedef std::bitset <INF_bit> bit;
typedef std::vector < std::pair<long long, long long>> pvec;
typedef std::vector < std::vector<long long>> vec2;
 
#pragma warning(disable : 4996)
 
int main() {
    IOS;
    ll n;
    std::cin >> n;
    vec  g(n);
    for (ll i = 0; i < n; i++) {
        int h, m, s;
        std::scanf("%d:%d:%d", &h, &m, &s);
        g[i] = h * 3600 + m * 60 + s;
    }
    sort(g.begin(), g.end());
    ll ans = 0;
    vec f(n);
    for (ll i = 1; i < n; i++) {
        f[i] = g[i] - g[i - 1];
        ans += (g[i] - g[0]);
    }
    ll t = 0, s = ans;
    for (ll i = 1; i < n; i++) {
        ans += f[i] * (n - 1) - (12 * 3600 - f[i]);
        if (ans < s) {
            t = i; s = ans;
        }
    }
    ll h = g[t] / 3600; g[t] %= 3600;
    ll m = g[t] / 60; g[t] %= 60;
    s = g[t];
 
    std::cout << h << ":";
 
    if (m > 9) {
        std::cout << m << ":";
    }
    else {
        std::cout << 0 << m << ':';
    }
    if (s > 9) {
        std::cout << s;
    }
    else {
        std::cout << 0 << s;
    }
}