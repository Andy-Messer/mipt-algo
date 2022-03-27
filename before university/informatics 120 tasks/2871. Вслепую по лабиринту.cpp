#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;




map<pair<int, int>, bool> used;
vector < tuple < string, int, int>> shift{ {"NORTH", 0, 1},
{"SOUTH", 0, -1},
{"WEST", -1, 0},
{"EAST", 1, 0} };
map<string, string> inv;

void dfs(pair<int, int> v) {
	for (int i = 0; i < 4; ++i) {
		string s = get<0>(shift[i]);
		int dx = get<1>(shift[i]);
		int dy = get<2>(shift[i]);
		if (used[{v.first + dx, v.second + dy}] == false) {
			cout << s << endl;
			string ans;
			cin >> ans;
			used[{v.first + dx, v.second + dy}] = true;
			if (ans == "EMPTY") {
				dfs({ v.first + dx, v.second + dy });
				cout << inv[s] << endl;
				cin >> ans;
			}
		}
	}
}

int main() {
	used[{0, 0}] = true;
	inv["NORTH"] = "SOUTH";
	inv["SOUTH"] = "NORTH";
	inv["WEST"] = "EAST";
	inv["EAST"] = "WEST";
	dfs({ 0, 0 });
	cout << "DONE" << endl;
}