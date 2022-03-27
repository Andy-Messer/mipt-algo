#include <iostream>
#include<math.h>
using namespace std;
int main() {
    long long int a, i, b, c, d, x, a2, b2, c2, d2, j; i = -100; j = 101;
    cin >> a >> b >> c >> d;
    a2 = a; b2 = b; c2 = c; d2 = d;
    for (;i<j;i++)
        if ((i*i*i*a2) + (i*i*b2) + (i*c2) + d2 == 0) cout << i << ' ';
    return 0;
}