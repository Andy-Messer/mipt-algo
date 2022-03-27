#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    vector <vector<int>> d;
    cin >> n >> k;
    d.push_back(vector<int>());
    d.push_back(vector<int>());
    d[0].push_back(0);
    d[1].push_back(k-1);
    for (int i=1; i < n; i++) {
        d[0].push_back(d[1][i-1]);
        d[1].push_back((d[0][i-1]+d[1][i-1])*(k-1));
    }
    cout << d[0][n - 1] + d[1][n - 1];
 
    return 0;
}