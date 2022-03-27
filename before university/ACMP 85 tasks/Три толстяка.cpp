#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    long long a,n,b;
    cin >> a>>b>>n;
    if (a >= 94 && a <= 727 && b>=94 && b <= 727 && n>=94 && n <= 727) {
        a = max(a, b);
        n = max(a, n);
        cout << n;
    }
    else {
        cout << "Error";
    }
     
    return 0;
}