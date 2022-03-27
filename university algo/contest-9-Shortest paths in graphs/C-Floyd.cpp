#include <iostream>
#include <vector>

int const inf = 1e9;

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> M(N, std::vector<int>(N, inf));
    for (auto &x: M) {
        for (auto &y:x) {
            std::cin >> y;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int p = 0; p < N; p++) {
                M[j][p] = std::min(M[j][p], M[j][i] + M[i][p]);
            }
        }
    }
    for (auto &x: M) {
        for (auto &y:x) {
            std::cout << y << ' ';
        }
        std::cout << std::endl;
    }
}