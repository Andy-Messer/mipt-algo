/*
─────────▀▀▀▀▀▀──────────▀▀▀▀▀▀▀
──────▀▀▀▀▀▀▀▀▀▀▀▀▀───▀▀▀▀▀▀▀▀▀▀▀▀▀
────▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀──────────▀▀▀
───▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀──────────────▀▀
──▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀──────────────▀▀
─▀▀▀▀▀▀▀▀▀▀▀▀───▀▀▀▀▀▀▀───────────────▀▀
─▀▀▀▀▀▀▀▀▀▀▀─────▀▀▀▀▀▀▀──────────────▀▀
─▀▀▀▀▀▀▀▀▀▀▀▀───▀▀▀▀▀▀▀▀──────────────▀▀
─▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀───────────────▀▀
─▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀───────────────▀▀
─▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀───────────────▀▀
──▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀───────────────▀▀
───▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀───────────────▀▀▀
─────▀▀▀▀▀▀▀▀▀▀▀▀▀───────────────▀▀▀
──────▀▀▀▀▀▀▀▀▀▀▀───▀▀▀────────▀▀▀
────────▀▀▀▀▀▀▀▀▀──▀▀▀▀▀────▀▀▀▀
───────────▀▀▀▀▀▀───▀▀▀───▀▀▀▀
─────────────▀▀▀▀▀─────▀▀▀▀
────────────────▀▀▀──▀▀▀▀
──────────────────▀▀▀▀
───────────────────▀▀
*/

#include <iostream>
#include <vector>

class Hashtable {
private:

    unsigned long long Generation(long long key) {

        unsigned long long w = 1;
        for (int i = 0; i < 32; ++i) w << 1;

        unsigned long long
                hash = (((long long) ((key * 13) / w)) * 2048 * 2048) % 100031;

        return hash;
    }

    std::vector<std::vector<std::pair<long long, long long>>> storage;

public:

    Hashtable() : storage(100031) {}

    long long Swap(long long x, long long y) {

        long long firstKey = Generation(x);
        long long secondKey = Generation(y);
        long long position1 = 0;
        long long position2 = 0;
        bool flag = 0;

        for (auto i: storage[firstKey]) {
            if (i.first == x) {
                flag = 1;
                break;
            }
            ++position1;
        }

        if (!flag)
            storage[firstKey].push_back({x, x});

        flag = 0;
        for (auto i: storage[secondKey]) {
            if (i.first == y) {
                flag = 1;
                break;
            }
            ++position2;
        }

        if (!flag)
            storage[secondKey].push_back({y, y});

        std::swap(storage[firstKey][position1].second, storage[secondKey][position2].second);
        return abs(storage[firstKey][position1].second - storage[secondKey][position2].second);
    }
};

int main() {
    long long n;
    std::cin >> n;
    long long a, b;
    Hashtable hashtable;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        std::cout << hashtable.Swap(a, b) << '\n';
    }
}