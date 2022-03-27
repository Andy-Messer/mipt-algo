#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
int main() {
    long double x_1, y_1, r_1, x_2, y_2, r_2;
    cin >> x_1 >> y_1 >> r_1;
    cin >> x_2 >> y_2 >> r_2;
    long double d = sqrt(pow(abs(x_1 - x_2), 2) + pow(abs(y_1 - y_2), 2));
    if (d > r_1 + r_2) {
        cout << "NO";
    }
    else {
        if (d < abs(r_1 - r_2)) {
            cout << "NO";
        }
        else {
            cout<<"YES";
        }
    }
    return 0;
}