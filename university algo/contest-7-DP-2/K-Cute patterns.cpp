#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<ll> vec;
typedef std::vector<vec> vec2;

ll GetB(ll m, ll p) {
    return (m >> p) & 1;
}

vec2 InitDP(ll sz1, ll sz2) {
    vec2 dp(sz1, vec(sz1 * (1 << sz2), 0));
    for (ll i = 0; i < (1 << sz2); ++i)
        dp[0][i] = 1;
    return dp;
}

bool IsSqC(ll m1, ll m2, ll p) {
    return !(GetB(m1, p) == GetB(m2, p) &&
             GetB(m1, p + 1) == GetB(m2, p + 1) &&
             GetB(m1, p) == GetB(m1, p + 1));
}

bool IsC(ll m1, ll m2, ll size) {
    for (ll i = 0; i < size - 1; ++i)
        if (!IsSqC(m1, m2, i))
            return false;
    return true;
}

std::vector<std::vector<bool>> InitC(ll size) {
    ll matrix_size = 1 << size;
    std::vector<std::vector<bool>> C(matrix_size,
                                     std::vector<bool>(
                                             matrix_size * matrix_size,
                                             false));
    for (ll i = 0; i < matrix_size; ++i)
        for (ll j = 0; j < matrix_size; ++j)
            C[i][j] = IsC(i, j, size);
    return C;
}

int main() {
    ll sz1 = 0;
    ll sz2 = 0;
    std::cin >> sz1 >> sz2;
    if (sz1 < sz2) {
        std::swap(sz1, sz2);
    }
    vec2 dp = InitDP(sz1, sz2);
    std::vector<std::vector<bool>> C = InitC(sz2);
    for (ll i = 1; i < sz1; ++i)
        for (ll m = 0; m < (1 << sz2); ++m)
            for (ll m1 = 0; m1 < (1 << sz2); ++m1)
                if (C[m][m1])
                    dp[i][m1] += dp[i - 1][m];
    ll ans = 0;
    for (ll m = 0; m < (1 << sz2); ++m)
        ans += dp[sz1 - 1][m];
    std::cout << ans;
    return 0;
}