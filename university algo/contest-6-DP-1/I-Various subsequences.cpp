#include <iostream>
#include <vector>

using std::string;
using std::vector;


const long long INF = INT_MAX;
namespace Tools {
    long long binSearch(std::vector<long long> &dp, long long &b) {
        long long r = dp.size();
        long long l = 0;
        long long mid;
        while (r > l) {
            mid = (l + r) / 2;
            mid > dp.size() - 1 && (mid = dp.size() - 1);
            dp[mid] >= b ? l = mid + 1 : r = mid;
        }
        return l;
    }
};

class DP {

    std::vector<long long> last_enter;
    std::vector<long long> dp;

public:
    void fill_dp(std::vector<long long> &a) {
        for (int pos = 1; pos <= a.size(); pos++) {

            dp[pos] = (dp[pos - 1] * 2) % 1000000007;

            last_enter[a[pos - 1]] != -1 && (dp[pos] = (dp[pos] - dp[last_enter[a[pos - 1]]]));

            dp[pos] < 0 && (dp[pos] += 1000000007);

            last_enter[a[pos - 1]] = pos - 1;
        }
    }

    long long get_ans() {
        return ((dp[dp.size() - 1]) - 1) % 1000000007;
    }

    ~DP() = default;

    DP(std::vector<long long> &a) : last_enter(a.size() + 1, -1), dp(a.size() + 1, -2) {
        dp[0] = 1;
        fill_dp(a);
    };
};


using namespace Tools;

int main() {

    long long N;
    std::cin >> N;

    std::vector<long long> a(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    DP solveB(a);

    std::cout << solveB.get_ans();

}