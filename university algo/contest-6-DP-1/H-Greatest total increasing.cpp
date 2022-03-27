#include <iostream>
#include <vector>

size_t Get_LCIS(std::vector<long long> a, std::vector<long long> b) {

    size_t sz_a = a.size();
    size_t sz_b = b.size();

    std::vector<long long> dp(sz_b, 0);

    long long c;

    for (long long i = 0; i < sz_a; i++) {

        c = 0;

        for (long long j = 0; j < sz_b; j++) {
            (a[i] == b[j]) && (c + 1 > dp[j]) && (dp[j] = c + 1);
            (a[i] > b[j] && dp[j] > c) && (c = dp[j]);
        }

    }
    
    size_t len = 0;
    
    for (auto &x:dp)
        x > len && (len = x);

    return len;
    
}

int main() {

    long long N;
    long long M;
    long long x;

    std::cin >> N;
    std::cin >> M;

    std::vector<long long> a;
    std::vector<long long> b;

    for (long long i = 0; i < N; ++i) {
        std::cin >> x;
        a.push_back(x);
    }

    for (long long i = 0; i < M; ++i) {
        std::cin >> x;
        b.push_back(x);
    }

    std::cout << Get_LCIS(a, b);

}