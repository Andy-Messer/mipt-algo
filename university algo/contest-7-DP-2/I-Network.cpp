#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<ll> vec;
typedef std::vector<vec> vec2;

ll GetB(ll m, ll pos) {
    return (m >> pos) & 1;
}

int main() {
    ll sz = 0;
    std::cin >> sz;
    std::vector<std::vector<bool>> matrix(sz, std::vector<bool>(sz, 1));

    char a = 0;

    for (ll i = 0; i < sz; ++i)
        for (ll j = 0; j < sz; ++j) {
            std::cin >> a;
            a == 'Y' ? matrix[i][j] = true : matrix[i][j] = false;
        }

    vec dp(1 << sz, 0);
    ll new_m = 0;
    ll prm = 0;

    for (ll m = 0; m < (1 << sz); ++m) {
        for (ll i = 0; i < sz; ++i) {
            if (GetB(m, i) == 0) {
                continue;
            }

            prm = m xor (1 << i);

            for (ll j = 0; j < sz; ++j) {
                if (j == i || !matrix[i][j] || GetB(m, j)) {
                    continue;
                }

                new_m = m | (1 << j);
                dp[new_m] = std::max(dp[prm] + 2, dp[new_m]);
            }
        }
    }

    std::cout << dp[(1 << sz) - 1];

    return 0;
}