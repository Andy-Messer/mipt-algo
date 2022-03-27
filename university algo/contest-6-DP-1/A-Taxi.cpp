#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int const INF = 1e9;

struct Dude {
    std::string name;
    long long km;
    std::string sex;

    Dude() : km(0), sex(""), name("") {};

    Dude(std::string new_name, std::string new_sex, long long new_km) : name(new_name), sex(new_sex), km(new_km) {};
};

struct Taxi {
    Dude boy;
    std::vector<Dude> dudes;

    Taxi(Dude &new_boy, Dude &man_1, Dude &man_2, Dude &man_3)

            :

            boy(new_boy), dudes({man_1, man_2, man_3}

    ) {}

    void push(Dude &x) {
        if (x.sex == "Man") {
            Dude empty;
            if (boy.name == empty.name) {
                boy = x;
            } else {
                dudes.push_back(x);
            }
        } else {
            dudes.push_back(x);
        }
    }

    long long cost() {
        long long cost = 0;
        cost += boy.km;
        for (auto &x:dudes) {
            cost = std::max(cost, x.km);
        }
        return cost;
    }

    Taxi() {};
};

struct Info_pair {
    long long man;
    long long woman;

    Info_pair() : man(0), woman(0) {};

    Info_pair(long long new_man, long long new_woman) : man(new_man), woman(new_woman) {};
};


bool cmp(Dude &a, Dude &b) {
    return a.km <= b.km ? true : false;
}

int main() {
    long long N;
    Dude man;
    std::cin >> N;

    std::vector<Dude> boys;
    std::vector<Dude> girls;
    for (int i = 0; i < N; ++i) {
        std::cin >> man.name >> man.km;
        man.sex = "Man";
        boys.push_back(man);
    }
    long long M;
    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> man.name >> man.km;
        man.sex = "Woman";
        girls.push_back(man);
    }

    std::vector<std::vector<long long>> dp;
    std::vector<std::vector<Info_pair>> info;
    Dude empty;
    girls.push_back(empty);
    boys.push_back(empty);
    std::sort(girls.begin(), girls.end(), cmp);
    std::sort(boys.begin(), boys.end(), cmp);

    dp.resize(M + 1, std::vector<long long>(N + 1, INF));
    info.resize(M + 1, std::vector<Info_pair>(N + 1, {0, 0}));
    dp[0][0] = 0;

    for (int j = 0; j < M + 1; ++j) {
        for (int i = 1; i < N + 1; ++i) {
            for (int k = 1; k <= 4; ++k) {
                for (int l = 0; l <= 4 - k; ++l) {
                    if (i - k < 0 || j - l < 0) {
                        continue;
                    }
                    if (dp[j][i] > dp[j - l][i - k] + std::max(girls[j].km, boys[i].km)) {
                        dp[j][i] = dp[j - l][i - k] + std::max(girls[j].km, boys[i].km);
                        info[j][i] = {k, l};
                    } else {
                        continue;
                    }
                }
            }
        }
    }
    long long n_boys = N;
    long long m_girls = M;
    std::vector<Taxi> taxi;
    long long ans_cost = 0;

    while (!(n_boys == 0 && m_girls == 0)) {
        Taxi new_taxi;
        long long k = info[m_girls][n_boys].man;
        long long l = info[m_girls][n_boys].woman;
        for (int i = 0; i < k; ++i) {
            new_taxi.push(boys[n_boys - i]);
        }
        for (int i = 0; i < l; ++i) {
            new_taxi.push(girls[m_girls - i]);
        }
        n_boys -= k;
        m_girls -= l;
        ans_cost += new_taxi.cost();
        taxi.push_back(new_taxi);
    }
    std::cout << "\n";
    std::cout << ans_cost << std::endl;
    std::cout << taxi.size() << std::endl;

    for (int i = 0; i < taxi.size(); ++i) {
        std::cout << "Taxi " << i + 1 << ": " << taxi[i].boy.name;
        if (taxi[i].dudes.size() > 1) {
            std::cout << ", ";
        } else{ if (!taxi[i].dudes.empty())
            std::cout << " ";
        }
        long long size = taxi[i].dudes.size();
        for (int j = 0; j < size - 1; ++j) {
            std::cout << taxi[i].dudes[j].name;
            if (j < size - 2) std::cout << ", ";
            else if (!taxi[i].dudes.empty())
                std::cout << " ";
        }
        if (!taxi[i].dudes.empty()) {
            std::cout << "and ";

            std::cout << taxi[i].dudes.back().name;
        }
        std::cout << ".";
        std::cout << "\n";

    }
}