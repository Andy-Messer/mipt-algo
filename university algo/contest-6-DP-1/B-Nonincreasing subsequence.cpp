#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

const long long INF = INT_MAX;
namespace Tools {
    long long binSearch(std::vector<long long> &dp, long long &b) {
        long long r = dp.size();
        long long l = 0;
        long long mid;
        while (r > l) {
            mid = (l + r) / 2;
            (mid > dp.size() - 1) && (mid = dp.size() - 1);
            dp[mid] >= b ? l = mid + 1 : r = mid;
        }
        return l;
    }
};

std::vector<long long> Recover(std::vector<long long> &pos, std::vector<long long> &prev, long long &length) {
    
    std::vector<long long> ans;
    
    if (length > pos.size() - 1) {
        length = pos.size() - 1;
    }
    
    long long p = pos[length];
    while (p != -1) {
        ans.push_back(p + 1);
        p = prev[p];
    }
    
    std::reverse(ans.begin(), ans.end());
    
    return ans;
}

std::vector<long long> SearchLIS(std::vector<long long> &a) {

    size_t size = a.size();
    std::vector<long long> dp(size + 1, -INF);
    std::vector<long long> pos(size + 1, -1);
    std::vector<long long> prev(size, -1);

    long long length = 0;
    
    dp[0] = INF;
    for (long long i = 0; i < size; i++) {
        
        long long posB = Tools::binSearch(dp, a[i]);

        if (posB > size && size > 1) {
            posB = size - 1;
        }

        dp[posB] = a[i];
        pos[posB] = i;
        prev[i] = pos[posB - 1];

        length = std::max(length, posB);

        if (length > size && size > 1) {
            length = size - 1;
        }

    }

    return Recover(pos, prev, length);
}

int main() {
    
    long long N;
    std::cin >> N;
    
    std::vector<long long> b(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> b[i];
    }
    
    std::vector<long long> ans = SearchLIS(b);
    
    std::cout << ans.size() << "\n";
    
    for (auto &x:ans) {
        std::cout << x << " ";
    }
}