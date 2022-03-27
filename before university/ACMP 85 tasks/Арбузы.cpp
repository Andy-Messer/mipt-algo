#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
int main() {
    int n,a,min,max;
    cin >> n;
    cin >> a;
    min = a; max = a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a < min) { min = a; }
        if (a > max) { max = a; }
    }
    cout << min << " " << max;
    return 0;
}