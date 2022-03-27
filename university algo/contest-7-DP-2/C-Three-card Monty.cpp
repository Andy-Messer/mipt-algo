#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<ll> vec;

const ll MOD = 1000000007;

long long mod(long long base, long long p) {
    if (p == 1) {
        return base;
    }

    if (p % 2 == 0) {
        long long t = mod(base, p / 2);
        return t * t % MOD;
    } else {
        return mod(base, p - 1) * base % MOD;
    }
}

void solve() {
    ll k;
    std::cin >> k;
    vec a(k);
    bool even = 0;
    ll d = 2;
    for (ll i = 0; i < k; i++) {
        std::cin >> a[i];
        !(a[i] % 2) && (even = true);
        d = mod(d, a[i]);
    }
    (d *= mod(2, MOD - 2)) %= MOD;
    ll n = ((((d + even + (!even) * (-1)) + MOD) % MOD) *
            mod(3, MOD - 2)) % MOD;
    std::cout << n << "/" << d;
}

int main() {
    solve();
    return 0;
}