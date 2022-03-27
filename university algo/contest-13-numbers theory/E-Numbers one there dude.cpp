#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

const ll MOD = 1e9 + 7;

template<ll M>
struct mod_math {

    template<ll mod = M, ll N = static_cast<ll> (1e6 + 1)>
    struct Factorial {
        std::vector<ll> val;

        Factorial() : val(N) {
            val[0] = 1;
            std::generate(val.begin() + 1, val.end(), [&]() {
                static ll ind = 0;
                ++ind;
                return mod_math<mod>::mul(val[ind - 1], ind);
            });
        }
    };

    static ll get_factorial(ll x) {
        static Factorial<M> factorial;
        return factorial.val[x];
    }

    template<ll mod = M>
    static ll norm(ll x) {
        return (x % mod + mod) % mod;
    }

    template<ll mod = M>
    static ll add(ll x, ll y) {
        return norm<mod>(norm<mod>(x) + norm<mod>(y));
    }

    template<ll mod = M>
    static ll sub(ll x, ll y) {
        return add<mod>(x, -y);
    }

    template<ll mod = M>
    static ll div(ll x, ll y) {
        return norm<mod>(norm<mod>(x) / norm<mod>(y));
    }

    template<ll mod = M>
    static ll mul(ll x, ll y) {
        return norm<mod>(norm<mod>(x) * norm<mod>(y));
    }

    template<ll mod = M>
    static ll pow(ll x, ll y) {
        if (y < 0) y = mod + y - 1;
        ll ans = 1;
        if (!y) return ans;
        do {
            if (y & 1) (ans *= x) %= mod;
            (x *= x) %= mod;
            y >>= 1;
        } while (y);
        return norm<mod>(ans);
    }

    template<ll mod = M>
    static ll C(ll n, ll k) {
        return mul<mod>(
                mul<mod>(
                        mod_math<mod>::get_factorial(n),
                        pow<mod>(mod_math<mod>::get_factorial(sub<mod>(n, k)), -1)),
                pow<mod>(mod_math<mod>::get_factorial(k), -1));
    }

    // info about Stirling's Number: https://en.wikipedia.org/wiki/Stirling_numbers_of_the_first_kind
    //                               https://buildwiki.ru/wiki/Stirling_numbers_of_the_second_kind
    template<ll mod = M>
    static ll StirlingNumber2(ll n, ll k) {
        ll res = 0;
        for (ll i = 0; i < k; ++i)
            // Stirling's Number of the first kind
            res = add<mod>(res, pow<mod>(-1, i & 1) * mul<mod>(C<mod>(k, i), pow<mod>(k - i, n)));
        return mul<mod>(res, pow<mod>(mod_math<mod>::get_factorial(k), -1));
    }
};

int main() {

    ll n, k;
    std::cin >> n >> k;

    ll sum = 0;
    ll a;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        sum = mod_math<MOD>::add(sum, a);
    }

    ll b = mod_math<MOD>::StirlingNumber2(n, k);
    ll c = mod_math<MOD>::StirlingNumber2(n - 1, k);
    std::cout << mod_math<MOD>::mul(sum, mod_math<MOD>::add(b, mod_math<MOD>::mul((n - 1), c)));
    return 0;
}