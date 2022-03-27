#include <iostream>
#include <vector>

int main() {

    long long N;
    std::cin >> N;
    std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(N + 1));
    std::vector<long long> b(N + 1);


    dp[0][0] = 1;
    for (long long Sum = 0; Sum <= N; Sum++) {
        for (long long new_el = 0; (Sum + new_el) <= N; new_el++) {
            long long p = 0;
            for (long long i = new_el / 2; i >= 0; i--) {
                p += dp[Sum][i];
            }
            dp[Sum + new_el][new_el] = p;
        }
        /*
        std::cout << "\n";
        for (auto &x:dp) {
            for (auto &p:x) {
                std::cout << p << ' ';
            }
            std::cout << "\n";
        }*/
    }

    long long p = 0;
    for (long long i = N; i >= 0; i--) {
        p += dp[N][i];
    }
    std::cout << p;

}