#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define IOS std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

int partition(std::vector<int> *anArrayItem, int left_glob, int right_glob) {
    int left = left_glob, right = right_glob;
    int middle = (right_glob + left_glob) / 2;
    do {
        int count = 0;
        while ((*anArrayItem)[left] < (*anArrayItem)[middle] && middle > left) ++left;
        while ((*anArrayItem)[right] >= (*anArrayItem)[middle] && middle < right) {
            (*anArrayItem)[right] == (*anArrayItem)[middle] ? count++ : NULL;
            --right;
        }
        if (left <= right) {
            int t = (*anArrayItem)[left];
            (*anArrayItem)[left] = (*anArrayItem)[right];
            (*anArrayItem)[right] = t;
            if (right == middle) {
                middle = left;
                right--;
            }
            else {
                if (left == middle) {
                    middle = right;
                    left++;
                }
            }
        }
    } while (left < right);
    return middle;
}

int kSmall(int kSmallIndex, std::vector<int> *anArrayItem, int first, int last) {
    int pivotIndex = partition(anArrayItem, first, last);
    while ((kSmallIndex != pivotIndex - first + 1)) {
        if (kSmallIndex < pivotIndex - first + 1) {
            last = pivotIndex - 1;
        } else {
            if (kSmallIndex > pivotIndex - first + 1) {
                kSmallIndex -= (pivotIndex - first + 1);
                first = pivotIndex + 1;
            }
        }
        pivotIndex = partition(anArrayItem, first, last);
    }
    return (*anArrayItem)[pivotIndex];
}

void solve() {
    int sizeArray, kSmallIndex;
    std::cin >> sizeArray;
    std::cin >> kSmallIndex;
    kSmallIndex++;
    std::vector<int> anArray;
    for (int index_i = 0; index_i < sizeArray; index_i++) {
        int local;
        std::cin >> local;
        anArray.push_back(local);
    }
    int ans = kSmall(kSmallIndex, &anArray, 0, sizeArray - 1);
    std::cout << ans;
}

int main() {
    IOS;
    solve();
}