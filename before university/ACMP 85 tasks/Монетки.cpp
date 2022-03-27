#include <iostream>
using namespace std;
int k1, k2, a, i;
int main() {
    int n;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) {
            k1++;
        }
        else {
            k2++;
        }
    }
    if (k1 > k2) {
        cout << k2;
    }
    else {
        cout << k1;
    }
    return 0;
}