#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

const std::vector<std::string> OPERATIONS =
        {
                "ADD", "DELETE", "CLEAR", "LISTSET", "LISTSETSOF"
        };

void acceleeration() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
}

int NUM_Operations(std::string &x) {
    int counter = 0;
    for (const auto &y:OPERATIONS) {
        if (y == x) return counter;
        counter++;
    }

    return -1;
}

struct Multiple {
    
    std::map<long long, std::set<long long>> ch;
    std::map<long long, std::set<long long>> mn;

    void Insert(long long e, long long s) {
        mn[s].insert(e);
        ch[e].insert(s);
    }

    void Clear(long long e) {
        for (auto i = mn[e].begin(); i != mn[e].end(); ++i) {
            ch[*i].erase(e);
        }
        mn[e].clear();
    }

    void Delete(long long e, long long s) {
        mn[s].erase(e);
        ch[e].erase(s);
    }

    void Listset(bool &flag, long long e) {
        flag = 0;
        for (auto i = mn[e].begin(); i != mn[e].end(); ++i) {
            std::cout << *i << " ";
            flag = 1;
        }
        if (!flag) std::cout << "-1" << std::endl;
        else std::cout << std::endl;
    }

    void Listsetsof(bool &flag, long long e) {
        flag = 0;
        for (auto i = ch[e].begin(); i != ch[e].end(); ++i) {
            std::cout << *i << " ";
            flag = 1;
        }
        if (!flag) std::cout << "-1" << std::endl;
        else std::cout << std::endl;
    }
};

void solve() {
    long long n, m, k;
    std::cin >> n >> m >> k;
    std::string str;
    Multiple multiple;
    while (k--) {
        std::cin >> str;
        long long e, s, index;
        bool flag = 0;
        std::cin >> e;
        switch (NUM_Operations(str)) {
            case 0:
                std::cin >> s;
                multiple.Insert(e, s);
                break;
            case 1:
                std::cin >> s;
                multiple.Delete(e, s);
                break;
            case 2:
                multiple.Clear(e);
                break;
            case 3:
                multiple.Listset(flag, e);
                break;
            case 4:
                multiple.Listsetsof(flag, e);
                break;
            default:
                std::cout << "You have some problems..." << std::endl;
                break;
        }
    }
}

int main() {
    acceleeration();
    solve();
    return 0;
}