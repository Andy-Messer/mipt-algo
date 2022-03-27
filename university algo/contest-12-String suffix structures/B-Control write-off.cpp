#include <iostream>
#include <map>
#include <vector>
#include <string>

#define IOS std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

#include <algorithm>

class StrAlgo {
public:
    static std::vector<size_t> LcpArray(const std::vector<size_t> &suffix_array, const std::string &str) {
        std::vector<size_t> pos(str.size());
        for (size_t i = 0; i < str.size(); ++i) {
            pos[suffix_array[i]] = i;
        }
        std::vector<size_t> lcp(str.size());
        long long l = 0;
        for (size_t p = 0; p < str.size(); ++p) {
            if (pos[p] == 0) {
                l = 0;
                continue;
            }
            l = std::max(0ll, l - 1);
            while (p + l < str.size() && suffix_array[pos[p] - 1] + l < str.size() &&
                   str[p + l] == str[suffix_array[pos[p] - 1] + l])
                ++l;
            lcp[pos[p]] = l;
        }
        return lcp;
    }

    static std::vector<size_t> SuffArray(std::string text) {
        std::vector<size_t> suf(text.length());
        std::generate(suf.begin(), suf.end(), []() {
            static int ind = 0;
            return ind++;
        });
        std::vector<int> classes(text.length());
        std::generate(classes.begin(), classes.end(), [&text]() {
            static int ind2 = 0;
            return text[ind2++];
        });
        auto cmp1{
                [&text](int a, int b) -> bool {
                    if (text[a] < text[b]) return 1; else return 0;
                }
        };
        std::sort(suf.begin(), suf.end(), cmp1);
        std::vector<int> cl_copy(text.length());
        for (size_t i = 1; i < text.length(); i <<= 1) {
            auto cmp2{
                    [&classes, &i](int a, int b) -> bool {
                        if (classes[a] != classes[b]) return classes[a] < classes[b];
                        else return classes[a + i] < classes[b + i];
                    }
            };
            std::sort(suf.begin(), suf.end(), cmp2);
            cl_copy[suf[0]] = 0;
            for (size_t j = 1; j < text.length(); ++j) {
                int l1 = suf[j - 1];
                int r1 = suf[j - 1] + i;
                int l2 = suf[j];
                int r2 = suf[j] + i;
                if (classes[l1] != classes[l2] || classes[r1] != classes[r2]) {
                    cl_copy[suf[j]] = cl_copy[suf[j - 1]] + 1;
                } else {
                    cl_copy[suf[j]] = cl_copy[suf[j - 1]];
                }
            }
            classes = cl_copy;
        }
        return suf;
    }
};

int main() {
    IOS;
    std::string str;
    long long k;
    std::cin >> str >> k;
    std::string str2 = str + "#";
    std::vector<size_t> suffArray = StrAlgo::SuffArray(str2);
    suffArray.erase(suffArray.cbegin());
    std::vector<size_t> lcpArray = StrAlgo::LcpArray(suffArray, str);
    long long j = 0, c_w = 0;
    for (; c_w < k && j != suffArray.size(); ++j)
        c_w += (long long) (str.size() - suffArray[j] - lcpArray[j]);
    if (c_w < k && j == suffArray.size()) {
        for (size_t i = suffArray[suffArray.size() - 1]; i < str.size(); ++i)
            std::cout << str[i];
        return 0;
    }
    --j;
    for (long long i = suffArray[j]; i < str.size() - c_w + k; ++i) {
        std::cout << str[i];
    }
    return 0;
}