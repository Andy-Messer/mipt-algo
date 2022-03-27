#include <iostream>
using namespace std;
int main() {
    long long n,a,b=2;
    cin >> n;
    if (n == 1) {
        cout << 2;
    }
    else {
        for (int i = 2; i <= n;i++) {
            b = b + i;
        }
        cout << b;
    }
     
    return 0;
}