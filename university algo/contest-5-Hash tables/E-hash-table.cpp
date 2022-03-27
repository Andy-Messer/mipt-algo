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
#include <string>
#include <fstream>
#include <vector>

class HashTable {
private:
    template<class T_key=std::string>
    long long GenerateKey(T_key key) {
        unsigned long long hash = 0;
        unsigned long long power_number = 71;
        long long p = 1;
        for (int i = 0; i < key.length(); ++i) {
            hash = (key[i] + hash * p) % 100000;
            p *= power_number;
        }
        return hash % 100000;
    }

    std::vector<std::vector<std::pair<std::string, std::string>>> storage;
public:
    HashTable() : storage(100000) {}

    template<class T_key, class T_element>
    void Edit(T_key key, T_element element) {
        long long new_key = GenerateKey(key);
        bool flag = 0;
        if (!storage[new_key].empty())
            for (auto &x:storage[new_key]) {
                if (x.first == key) {
                    x.second = element;
                    flag = 1;
                }
            }
        if (!flag) {
            storage[new_key].push_back({key, element});
        }
    }

    template<class T_key>
    std::string Search(T_key key) {
        long long new_key = GenerateKey(key);
        for (auto x:storage[new_key]) {
            if (x.first == key) {
                return x.second;
            }
        }
        return "none";
    }

    template<class T_key>
    void Delete(T_key key) {
        long long new_key = GenerateKey(key);
        long long k = 0;
        for (auto x:storage[new_key]) {
            if (x.first == key) {
                storage[new_key].erase(storage[new_key].begin() + k);
            }
            k++;
        }
    }
};

void solve() {
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    HashTable hashtable;
    std::string s;
    std::string x;
    std::string y;
    while (std::cin >> s) {

        if (s == "get") {
            std::cin >> x;
            std::cout << hashtable.Search(x) << "\n";
        }

        if (s == "put") {
            std::cin >> x
                >> y;
            hashtable.Edit(x, y);
        }

        if (s == "delete") {
            std::cin >> x;
            hashtable.Delete(x);
        }
    }
}
//----------------------------------------//

int main() {
    solve();
    return 0;
}