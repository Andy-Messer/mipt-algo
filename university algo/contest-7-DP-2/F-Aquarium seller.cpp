#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<ll> vec;
typedef std::vector<vec> vec2;
const ll inf = ll(1e9);


ll GetB(ll mask, ll pos) {
    return (mask >> pos) & 1;
}

void Pr(vec2 &GR,
           vec2 &dp, ll lV, ll sz,
           ll mask) {
    std::cout << lV + 1 << ' ';
    if ((mask & ~(1 << lV)) == 0) {
        return;
    }
    for (ll i = 0; i < sz; ++i) {
        if (GetB(mask, i) && i != lV) {
            if (dp[lV][mask] ==
                (dp[i][mask & ~(1 << lV)] + GR[i][lV])) {
                Pr(GR, dp, i, sz, mask & ~(1 << lV));
                return;
            }
        }
    }
}

int main() {
    ll sz = 0;
    std::cin >> sz;

    vec2 GR(sz, vec(sz, 0));

    for (ll i = 0; i < sz; ++i) {
        for (ll j = 0; j < sz; ++j) {
            std::cin >> GR[i][j];
        }
    }

    vec2 dp(sz,
                                     vec(sz * (1 << sz), 0));
    for (ll i = 0; i < sz; ++i) {
        for (ll mask = 0; mask < (1 << sz); ++mask) {
            if (mask != (1 << i)) {
                dp[i][mask] = inf;
            }
        }
    }

    for (ll mask = 1; mask < (1 << sz); ++mask) {
        for (ll v = 0; v < sz; ++v) {
            for (ll u = 0; u < sz; ++u) {
                if (GetB(mask, u)) {
                    continue;
                }

                ll new_mask = mask | (1 << u);

                dp[u][new_mask] = std::min(dp[u][new_mask],
                                           dp[v][mask] + GR[u][v]);
            }
        }
    }

    ll ans = inf;
    ll all_v = (1 << sz) - 1;
    ll lV = 0;

    for (ll i = 0; i < sz; ++i) {
        if (ans > dp[i][all_v]) {
            ans = dp[i][all_v];
            lV = i;
        }

    }

    std::cout << ans << '\n';

    Pr(GR, dp, lV, sz, (1 << sz) - 1);


    return 0;
}