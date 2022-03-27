#include<iostream>
#include<vector>
#define IOS std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
long long check_A_B(std::vector<long long> &A, std::vector<long long> &B, int length_Array) {
    long long left = 0, right = length_Array - 1;
    long long left_minimum = A[0] - B[0];
    long long right_minimum = A[length_Array - 1] - B[length_Array - 1];
    while (left < right - 1) {
        long long middle = (left + right) / 2;
        long long delta = A[middle] - B[middle];
        if (delta > 0) {
            right = middle;right_minimum = delta;
        }        
    else {
            left = middle;left_minimum = delta;
        }
    }
    long long max_right = std::max(A[right], B[right]);
    long long max_left = std::max(A[left], B[left]);
    if (max_right<max_left){
        return right + 1;
    }else{
        return left + 1;
    }
}
int main(){
    IOS;
    long long N,M;
    std::cin >> N;
    std::cin >> M;
    long long L;
    std::cin >> L;
    std::vector<std::vector<long long>> A(N,std::vector<long long>(L,0)),B(M,std::vector<long long>(L,0));
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < L;j++) {
            std::cin >> A[i][j];
        }
    }
    for (int i = 0;i < M;i++) {
        for (int j = 0;j < L;j++) {
            std::cin >> B[i][j];
        }
    }
    long long q;
    std::cin >> q;
    while (q--){
        long long first, second;
        std::cin >> first >> second;first--;second--;
        std::cout << check_A_B(A[first], B[second], L)<<'\n';
    }
    return 0;
}