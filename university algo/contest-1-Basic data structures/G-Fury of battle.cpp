#include<iostream>
#include<vector>
bool check
(long long num_of_attacks, std::vector<long long> health_loc, long long num_of_monsters, long long post_damage, long long main_damage) {
    long long delta = 0;
    bool flag = 0;
    for (int i = 0;i < num_of_monsters&&!flag;i++) {
        health_loc[i] -= post_damage * num_of_attacks;
        long long loc_delta = 0;
        if (main_damage != post_damage&&health_loc[i]>0) {
            if (health_loc[i] % (main_damage - post_damage) != 0) {
                delta += health_loc[i] / (main_damage - post_damage) + 1;
                loc_delta=health_loc[i] / (main_damage - post_damage) + 1;
            }
            else {
                delta += health_loc[i] / (main_damage - post_damage);
                loc_delta=health_loc[i] / (main_damage - post_damage);
            }
        }
        else {
            if (health_loc[i] > 0)
            delta++;
        }
        if (health_loc[i] - loc_delta * (main_damage - post_damage) > 0) flag = 1;
    }
    if (delta <= num_of_attacks && !flag) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    long long num_of_monsters;
    std::cin >> num_of_monsters;
    long long main_damage, post_damage;
    std::cin >> main_damage >> post_damage;
    std::vector<long long> health(num_of_monsters, 0);
    long long max_health = 0;;
    for (int i = 0;i < num_of_monsters;i++) {
        std::cin >> health[i];
        max_health = std::max(max_health, health[i]);
    }
    long long approx_num = (max_health + post_damage - 1)/ post_damage;
    long long left = 0, right = approx_num;
    while (left < right) {
        approx_num = (right + left) / 2;
        if (check(approx_num, health, num_of_monsters, post_damage, main_damage)) {
            right = approx_num;
        }
        else {
            left = approx_num+1;
        }
    }
    std::cout << right;
}