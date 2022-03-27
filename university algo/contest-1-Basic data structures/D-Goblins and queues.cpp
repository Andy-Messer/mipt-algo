#include <iostream>
#include <vector>
#include <deque>

void decision(char &type, long long &val, std::deque<long long> &left, std::deque<long long> &right) {
    switch (type) {
        case '+':
            std::cin >> val;
            right.push_back(val);
            break;
        case '-':
            std::cout << left.front() << '\n';
            left.pop_front();
            break;
        case '*':
            std::cin >> val;
            right.push_front(val);
            break;
    }
    if (right.size() > left.size()) {
        long long loc_val = right.front();
        right.pop_front();
        left.push_back(loc_val);
    }
}

int main() {
    long long N;
    std::deque<long long> left;
    std::deque<long long> right;
    
    std::cin >> N;
    
    for (int i = 1; i <= N; i++) {
        long long val;
        char type;

        std::cin >> type;

        decision(type, val, left, right);
    }

    return 0;
}