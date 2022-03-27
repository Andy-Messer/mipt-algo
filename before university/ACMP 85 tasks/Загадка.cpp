#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
int main() {
    int n,a,min,max,c,d;
    cin >> n;
    cin >> a;
    for (int i = 1; i <= sqrt(a); i++) {
        if (a%i == 0) {
            if (i + a / i == n) {
                c = i;
                d = a / i;
            }
        }
    }
    cout << c << ' ' << d;
    return 0;
}