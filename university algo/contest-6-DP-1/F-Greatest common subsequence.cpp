#include <iostream>
#include <algorithm>
#include <vector>

int main() {

    long long N;
    long long M;
    long long x;

    std::cin >> N;

    std::vector<long long> s1(1);
    std::vector<long long> s2(1);

    for (int i = 0; i < N; ++i) {
        std::cin >> x;
        s1.push_back(x);
    }

    std::cin >> M;

    for (int i = 0; i < M; ++i) {
        std::cin >> x;
        s2.push_back(x);
    }
    long long sz1 = s1.size() + 1;
    long long sz2 = s2.size() + 1;

    int *data = new int[sz1 * sz2];
    for (int i = 0; i < sz1; ++i) {
        for (int j = 0; j < sz2; ++j) {
            data[i * (sz2) + j] = 0;
        }
    }

    for (int i = 1; i < sz1; ++i) {
        for (int j = 1; j < sz2; ++j) {
            if (s1[i] != s2[j]) {
                data[i * sz2 + j] = std::max(data[(i - 1) * sz2 + j],
                                             data[i * sz2 + (j - 1)]);
            } else {
                data[i * sz2 + j] = data[(i - 1) * sz2 + (j - 1)] + 1;
            }
        }
    }

    std::vector<long long> ans;
    long long i = sz1 - 2;
    long long j = sz2 - 2;
    while (data[i * sz2 + j] > 0 && (i != 0 && j != 0)) {
        if (data[i * sz2 + j] == data[(i - 1) * sz2 + (j - 1)]) {
            j--, i--;
        } else {
            if (data[i * sz2 + j] == data[i * sz2 + (j - 1)]) {
                j--;
            } else {
                if (data[i * sz2 + j] == data[(i - 1) * sz2 + j]) {
                    i--;
                } else {
                    ans.push_back(s2[j]), i--, j--;
                }
            }
        }

    }

    std::reverse(ans.begin(), ans.end());

    std::cout << ans.size();
}