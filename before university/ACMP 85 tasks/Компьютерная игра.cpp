#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;
 
int main() {
    long long n;
    cin >> n;
    vector <long long> a(n+3,0);
    vector <long long> f(n + 3, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = a[n - 1];
    f[0] = 0;
    f[1] = abs(a[0]-a[1]);
    for (long long i = 2; i < n;i++) {
        if (f[i-1] + abs(a[i] - a[i - 1]) < f[i-2]+3*abs(a[i - 2] - a[i])) {
            f[i] = f[i-1] + abs(a[i] - a[i - 1]);
        }
        else {
            f[i] = f[i - 2] + abs(a[i - 2] - a[i])*3;
        }
        /*if ((abs(a[i + 1] - a[i])+abs(a[i + 2] - a[i+1]) < abs(a[i + 2] - a[i]) * 3)) {
            ans += abs(a[i + 1] - a[i]);
        }
        else {
            if (abs(abs(a[i + 2] - a[i]) * 3 - abs(a[i + 1] - a[i]) + abs(a[i + 2] - a[i + 1])) > max) {
                max = abs(abs(a[i + 2] - a[i]) * 3 - abs(a[i + 1] - a[i]) + abs(a[i + 2] - a[i + 1]));
                max2 = abs(a[i + 2] - a[i]) * 3;
                call = abs(a[i + 1] - a[i]) + abs(a[i + 2] - a[i + 1]);
            }
            ans += abs(a[i + 1] - a[i]);
        }*/
    }
    cout << f[n-1];
}