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
 
#define IOS ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl "\n";
 
typedef long long ll;
typedef long double ld;
const ll INF = 1e9 + 7;
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
 
ll count = 0;
void build(ll a, ll b) {
    for (ll i = a; i <= b; i++) {
        build(i + 1, b - i);
    }
    if (b == 0)count++;
}
 
int main() {
    ll n;
    std::cin >> n;
    build(1, n);
    std::cout << count;
}