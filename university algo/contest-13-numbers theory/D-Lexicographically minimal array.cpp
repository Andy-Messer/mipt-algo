#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

const long long sz = 1e7;

std::vector<long long> mind(sz + 1);
std::vector<long long> primes;


long long get_next_prime() {
    static long long ind = 0;
    while(mind[primes[ind]] == -1) ++ind;
    return primes[ind];
}


long long get_next(long long x) {
    return x / mind[x];
}


std::set<long long> decompose(long long x) {
    std::set<long long> ans;

    while (mind[x] != x && mind[x] != -1) {
        if (mind[mind[x]] == -1) {
            break;
        }
        ans.insert(mind[x]);
        x = get_next(x);
    }

    if (mind[x] == x)
        ans.insert(x);
    else
        ans.clear();

    return ans;
}


typedef enum {
    prefix,
    suffix,
    prefix_end
} State;


int main() {

// ----------------------------------------- //

    mind.resize(sz + 1);

    for (int i = 0; i <= sz; ++i)
        mind[i] = i;

    for (int k = 2; k <= sz; ++k) {
        if (mind[k] == k) primes.push_back(k);
        for (auto &p : primes)
            if (k * p <= sz)
                if (p <= mind[k])
                    mind[p * k] = p;
                else
                    break;
            else
                break;
    }

// ----------------------------------------- //

    long long n;
    std::cin >> n;

    std::vector<long long> input_array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> input_array[i];
    }

    State state = prefix;
    std::vector<long long> output_array;

    std::set<long long> d;
    long long sz_out = 0;
    for (int i = 0; i < n; ++i) {
        if (state == suffix) {
            sz_out++;
            output_array.push_back(get_next_prime());
            mind[output_array.back()] = -1;
        } else {
            d = decompose(input_array[i]);
            if (d.empty())
                state = prefix_end;
            while(state == prefix_end) {
                ++input_array[i];
                d = decompose(input_array[i]);
                if (!d.empty()) {
                    state = suffix;
                }
            }
            for (auto &u : d) {
                mind[u] = -1;
            }
            sz_out++;
            output_array.push_back(input_array[i]);
        }
    }

    for (auto &x : output_array) {
        std::cout << x << ' ';
    }

// ----------------------------------------- //
}