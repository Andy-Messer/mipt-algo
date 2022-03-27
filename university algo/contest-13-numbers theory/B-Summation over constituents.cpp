#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
typedef long long ll;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define pb push_back

class Sieve{
public:
    vi pr;
    vi mind;

    Sieve(const ll& n) {
        mind.resize(n + 1);
        std::generate(mind.begin(), mind.end(), []() {static ll ind = 0; return ind++; });
        for (ll k = 2; k <= n; ++k) {
            if (mind[k] == k) pr.pb(k);
            for (auto p:pr) {
                if (k * p <= n)
                    if (p <= mind[k])
                        mind[p*k] = p;
                    else
                        break;
                else
                    break;
            }
        }
    }

public:
    ll get_mind(ll ind) {
        return mind[ind];
    }

    bool get_prime(ll ind) {
        return mind[ind] == ind;
    }
};





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
    if (y < 0) y += mod - 1 ;
    ll ans = 1;
    if (!y) return ans;
    do {
        if (y & 1) (ans *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    } while (y);
    return norm<mod>(ans);
}

ll solve(const ll& n) {
    Sieve generate(n);
    ll ans = 0;
    for (ll i = 2; i <= n; ++i)
        if (!generate.get_prime(i)) ans += generate.get_mind(i);
    return ans;
}
int main() {
    ll n;
    cin >> n;
    cout << solve(n);
    return 0;
}