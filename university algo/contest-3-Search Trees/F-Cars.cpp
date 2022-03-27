#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>

void acceleeration() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
}

int main() {
    acceleeration();
    long long n, k, p, car;
    std::cin >> n >> k >> p;
    std::vector<long long> order(p);
    std::vector <std::queue<long long>> next_similar_car(100001);
    std::set<long long> on_the_floor;
    std::set<long long> multitude_cars;
    std::queue<long long> q;
    std::set<std::pair<long long, long long>, std::greater<std::pair<long long, long long>>> order_to_lift;
    long long first_number_cars = 0, ans = 0, last;
    for (long long i = 0; i < p; i++) {
        std::cin >> car;
        order[i] = car;
        if (on_the_floor.size() < k) {
            last = i;
            long long prev = on_the_floor.size();
            on_the_floor.insert(car);
            if (prev != on_the_floor.size()) {
                first_number_cars++;
            }
        } else {
            next_similar_car[car].push(i);
        }
        multitude_cars.insert(car);
    }
    ans = first_number_cars;
    if (multitude_cars.size() > k) {


        for (auto x:on_the_floor) {
            if (!next_similar_car[x].empty()) {
                order_to_lift.insert({(next_similar_car[x].front()), x});
                next_similar_car[x].pop();
            } else {
                order_to_lift.insert({1e9, x});
            }
        }

        for (int i = last + 1; i < p; i++) {
            if (on_the_floor.find(order[i]) == on_the_floor.end()) {
                //берем первую в очереди на поднимание
                std::pair<long long, long long> it = *order_to_lift.begin();
                //std::cout << it.second << ' ' << order[i] << std::endl;
                //поднимаем
                order_to_lift.erase(it);
                on_the_floor.erase(it.second);
                //добавляем новую
                on_the_floor.insert(order[i]);
                if (next_similar_car[order[i]].front() == i)next_similar_car[order[i]].pop();
                if (!next_similar_car[order[i]].empty()) {
                    order_to_lift.insert({next_similar_car[order[i]].front(), order[i]});
                    next_similar_car[order[i]].pop();
                } else
                    order_to_lift.insert({1e9, order[i]});
                ans++;
            } else {
                order_to_lift.erase({i, order[i]});
                if (!next_similar_car[order[i]].empty()) {
                    order_to_lift.insert({next_similar_car[order[i]].front(), order[i]});
                    next_similar_car[order[i]].pop();
                } else
                    order_to_lift.insert({1e9, order[i]});
            }
        }
        std::cout << ans;
    } else {
        std::cout << multitude_cars.size();
    }
}