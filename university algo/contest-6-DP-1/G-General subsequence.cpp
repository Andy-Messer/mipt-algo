#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

vector<long long> edit_length(std::string &first_str, std::string &second_str) {
    vector<long long> array(second_str.length() + 1, 0);
    for (auto &x_element: first_str) {
        vector<long long> prev = array;
        for (int i = 0; i < second_str.length(); ++i) {
            if (x_element == second_str[i]) {
                array[i + 1] = prev[i] + 1;
            } else {
                array[i + 1] = std::max(array[i], prev[i + 1]);
            }
        }
    }
    return array;
}

std::string Hirshberg(std::string first_str, std::string second_str) {
    long long x_length = first_str.length();
    switch (x_length) {

        case 0:
            return "";

        case 1:
            return (std::find(second_str.begin(), second_str.end(), first_str[0]) != second_str.end()) ? first_str : "";

        default:

            std::string first_half_str;
            std::string second_half_str;

            std::vector<long long> editorial_distances_first;
            std::vector<long long> editorial_distances_second;

            long long first_pos = x_length / 2;

            first_half_str = first_str.substr(0, first_pos);
            second_half_str = first_str.substr(first_pos, x_length - first_pos);

            editorial_distances_first = edit_length(first_half_str, second_str);



            std::reverse(second_half_str.begin(), second_half_str.end());
            std::reverse(second_str.begin(), second_str.end());

            editorial_distances_second = edit_length(second_half_str, second_str);
            std::reverse(editorial_distances_second.begin(), editorial_distances_second.end());

            std::reverse(second_half_str.begin(), second_half_str.end());
            std::reverse(second_str.begin(), second_str.end());



            std::vector<long long> Sum_of_dist;
            long long max = editorial_distances_first[0] + editorial_distances_second[0], pos = 0;
            for (int i = 0; i < editorial_distances_second.size(); ++i) {
                Sum_of_dist.push_back(editorial_distances_first[i] + editorial_distances_second[i]);
                if (Sum_of_dist[i] > max) {
                    max = Sum_of_dist[i];
                    pos = i;
                }
            }

            std::string first_res = second_str.substr(0, pos);
            std::string second_res = second_str.substr(pos, second_str.length() - pos);
            return Hirshberg(first_half_str, first_res) + Hirshberg(second_half_str, second_res);
    }
}


int main() {

    std::string first_str;
    std::string second_str;

    std::cin >> first_str;
    std::cin >> second_str;

    std::cout << Hirshberg(first_str, second_str);
}