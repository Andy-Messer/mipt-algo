#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n,min,max,c,d;
    cin >> n;
    vector <int> a;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        a.push_back(b);
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << a[i]<<" ";
    }
    return 0;
}