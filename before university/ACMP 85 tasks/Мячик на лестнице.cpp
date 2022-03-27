#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;
 
int main() {
    long long n;
    cin >> n;
    vector <long long> a(n+3,0);
    a[0] = 1;
    for (long long i = 1; i <= n;i++) {
        a[i] += a[i - 1];
        a[i+1] += a[i - 1];
        a[i+2] += a[i - 1];
    }
    cout << a[n];
}