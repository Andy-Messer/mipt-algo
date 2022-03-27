#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector <int> a(3,0);
    vector <int> b(3,0);
    cin >> a[1] >> a[2] >> a[0] >> b[1] >> b[2] >> b[0];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << a[2] * b[2] + a[1] * b[1] + a[0] * b[0];
    return 0;
}