#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using std::queue;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::unordered_map;
using std::pair;
typedef vector<int> v_s;
typedef unordered_map<string, int> m_s_i;
typedef long long ll;

string rev(string a, ll x, ll y) {
    while (x < y) {
        std::swap(a[x], a[y]);
        y--;
        x++;
    }
    return a;
}


ll BFS(string &a, string &b) {
    std::queue<string> q_1, q_2;
    std::unordered_map<string, ll> global_used_1, global_used_2;
    q_1.push(a);
    q_2.push(b);
    long long dist = 0;
    while (!q_1.empty() && !q_2.empty()) {
        std::queue<string> second_q_in_q_1, second_q_in_q_2;
        string s = q_2.front();
        while (!q_1.empty()) {
            string f = q_1.front();
            if (global_used_2.find(f) != global_used_2.cend()) {
                return global_used_2[f] + dist;
            }
            q_1.pop();
            for (int i = 0; i < s.size(); i++) {
                for (int j = i + 1; j < s.size(); j++) {
                    string new_f = rev(f, i, j);
                    if (global_used_1.find(new_f) == global_used_1.cend()) {
                        second_q_in_q_1.push(new_f);
                        global_used_1[new_f] = dist + 1;
                    }
                    if (global_used_2.find(new_f) != global_used_2.cend()) {
                        return dist + 1 + dist;
                    }
                }
            }
        }
        while (!q_2.empty()) {
            string s = q_2.front();
            if (global_used_1.find(s) != global_used_1.cend()) {
                return global_used_1[s] + dist;
            }
            q_2.pop();
            for (int i = 0; i < s.size(); i++) {
                for (int j = i + 1; j < s.size(); j++) {
                    string new_s = rev(s, i, j);
                    if (global_used_2.find(new_s) == global_used_2.cend()) {
                        second_q_in_q_2.push(new_s);
                        global_used_2[new_s] = dist + 1;
                    }
                    if (global_used_1.find(new_s) != global_used_1.cend()) {
                        return dist + 1 + 1 + dist;
                    }
                }
            }

        }
        dist++;
        q_1 = second_q_in_q_1;
        q_2 = second_q_in_q_2;
    }


}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    std::cin >> n;
    string x, y;
    int a;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        a--;
        x += (a + '0');
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        a--;
        y += (a + '0');
    }
    if (y == x)
        std::cout << 0;
    else
        std::cout << BFS(x, y);
}