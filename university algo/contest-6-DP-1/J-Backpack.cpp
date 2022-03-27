#include <iostream>
#include <vector>

int main() {
    long long S, N;
    std::cin >> S >> N;
    std::vector<long long> a(N + 1);
    std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(S + 1, 0));
    for (int elem = 1; elem <= N; elem++) {
        std::cin >> a[elem];
    }
    for (int elem = 1; elem <= N; elem++) {
        for (int weight = 1; weight <= S; weight++) {
            if (weight >= a[elem]) {
                dp[elem][weight] = std::max(dp[elem - 1][weight], dp[elem - 1][weight - a[elem]] + a[elem]);
            } else {
                dp[elem][weight] = dp[elem - 1][weight];
            }
        }
    }
   std::cout<<dp[N][S];
}