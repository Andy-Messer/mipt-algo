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

    std::vector<std::vector<std::pair<std::string, long long>>> storage;
public:
    HashTable() : storage(100000) {}

    template<class T_key, class T_element>
    void Edit(T_key key, T_element element) {
        long long new_key = GenerateKey(key);
        bool flag = 0;
        if (!storage[new_key].empty())
            for (auto &x:storage[new_key]) {
                if (x.first == key) {
                    x.second += element;
                    flag = 1;
                }
            }
        if (!flag) {
            storage[new_key].push_back({key, element});
        }
    }

    template<class T_key>
    long long Search(T_key key) {
        long long new_key = GenerateKey(key);
        for (auto x:storage[new_key]) {
            if (x.first == key) {
                return x.second;
            }
        }
    }
};

int main() {
    std::string hashable_name;
    long long value;
    HashTable hash_table;
    while (std::cin >> hashable_name) {
        std::cin >> value;
        hash_table.Edit(hashable_name, value);
        std::cout << hash_table.Search(hashable_name)<<' ';
    }
}