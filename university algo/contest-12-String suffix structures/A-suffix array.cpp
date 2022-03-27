#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

std::vector<int> SuffArray(std::string text) {
    std::vector<int> suf(text.length());
    std::generate(suf.begin(), suf.end(), []() {static int ind = 0; return ind++; });
    std::vector<int> classes(text.length());
    std::generate(classes.begin(), classes.end(), [&text]() {static int ind2 = 0; return text[ind2++]; });
    auto cmp1 {
        [&text](int a, int b) -> bool {
            if (text[a] < text[b]) return 1; else return 0;
        }
    };
    std::sort(suf.begin(), suf.end(), cmp1);
    std::vector<int> cl_copy(text.length());
    for (size_t i = 1; i < text.length(); i <<= 1) {
        auto cmp2 {
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


int main() {
    std::string str;
    std::cin >> str;
    str += "#";
    std::vector<int> ans = SuffArray(str);
    for (size_t i = 1; i < ans.size(); ++i) {
        std::cout << ans[i] + 1 << ' ';
    }
}