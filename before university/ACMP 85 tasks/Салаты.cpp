#include <iostream>
#include <stack>
#include  <string>
#include <vector>
#include <math.h>
using namespace std; 
 
long long fact(long long a) {
    long long l=1;
    for (long long i = 1; i <= a; i++) {
        l = l * i;
    }
    return l;
}
 
int main() {
    long long n;
    cin >> n;
    long long ans = 1;
    for (long long i = 1; i <= n;i++) {
        ans *= 2;
    }
    cout << ans - 1 - n;
}