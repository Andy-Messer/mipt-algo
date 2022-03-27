#include <iostream>
#include <math.h>
using namespace std;
 
int main() {
    long long a, b, c, d;
    cin >> a >> b >> c;
    if (a > b) {
        if (a > c) {
            if (b > c) {
                d = abs(a - c);
            }
            else {
                d = abs(a - b);
            }
        }
    }
    if (b > a) {
        if (b > c) {
            if (a > c) {
                d = abs(b - c);
            }
            else {
                d = abs(a - b);
            }
        }
    }
    if (c >= b) {
        if (c >= a) {
            if (b >= a) {
                d = abs(a - c);
            }
            else {
                d = abs(c - b);
            }
        }
    }
    cout << d;
 
    return 0;
}