#include <iostream>

typedef long long ll;

template<ll mod>
ll norm(ll x) {
    return (x % mod + mod) % mod;
}

template<ll mod>
ll add(ll x, ll y) {
    return norm<mod>(norm<mod>(x) + norm<mod>(y));
}

template<ll mod>
ll div(ll x, ll y) {
    return norm<mod>(norm<mod>(x) / norm<mod>(y));
}

template<ll mod>
ll mul(ll x, ll y) {
    return norm<mod>(norm<mod>(x) * norm<mod>(y));
}

template<ll mod>
ll pow(ll x, ll y) {
    if (y < 0) y = mod + y - 1 ;
    ll ans = 1;
    if (!y) return ans;
    do {
        if (y & 1) (ans *= x) %= mod;
        (x *= x) %= mod;
        y>>=1;
    } while (y);
    return norm<mod>(ans);
}

int main() {
    ll a, b, c, d;
    const ll mod = 1e9 + 7;
    std::cin >> a >> b >> c >> d;
    std::cout << mul<mod>(add<mod>(mul<mod>(a, d), mul<mod>(c, b)), pow<mod>(mul<mod>(b, d), -1));
    return 0;
}