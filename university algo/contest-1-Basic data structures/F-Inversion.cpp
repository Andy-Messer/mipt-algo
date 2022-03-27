#include<iostream>
#include<vector>
#include<fstream>


void mergesort(std::vector<long long> &Item, long long first, long long second, long long &ans);

void merge(std::vector<long long> &Item, long long first, long long middle, long long second, long long &ans);


void mergesort(std::vector<long long> &Item, long long first, long long second, long long &ans) {
    if (first < second) {
        long long middle = (second + first) / 2;
        mergesort(Item, first, middle, ans);
        mergesort(Item, middle + 1, second, ans);

        merge(Item, first, middle, second, ans);
    }
}


void merge(std::vector<long long> &Item, long long first, long long middle, long long second, long long &ans) {
    std::vector<long long> locItem(second - first + 1, 0);
    long long index = 0;
    long long first_1 = first, first_2 = middle + 1;
    long long second_1 = middle, second_2 = second;


    for (; (first_1 <= second_1) && (first_2 <= second_2); index++) {
        if (Item[first_1] < Item[first_2]) {
            locItem[index] = Item[first_1];
            first_1++;
            ans += first_2 - middle - 1;
        } else {
            locItem[index] = Item[first_2];
            first_2++;
        }
    }

    for (; first_1 <= second_1; index++) {
        locItem[index] = Item[first_1];
        first_1++;
        ans += second_2 - middle;
    }
    for (; first_2 <= second_2; index++) {
        locItem[index] = Item[first_2];
        first_2++;
    }
    for (index = first; index <= second; index++) {
        Item[index] = locItem[index - first];
    }
}


int main() {
    int N;
    std::ifstream in;
    std::ofstream out;
    in.open("inverse.in");
    out.open("inverse.out");
    in >> N;
    long long ans = 0;//Глобальная переменная? Зачем?
    //std::cin >> N;
    std::vector<long long> A(N, 0);
    for (int i = 0; i < N; i++) {
        in >> A[i];
        //std::cin >> A[i];
    }
    mergesort(A, 0, N - 1, ans);
    //std::cout << ans;
    out << ans;

    in.close();
    out.close();
}