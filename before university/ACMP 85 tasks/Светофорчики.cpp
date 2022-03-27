#include <iostream>
using namespace std;
int main() {
    long long n,m,a,b=2;
    cin >> n>>m;
    int *s = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        s[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        s[a]++; s[b]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << s[i] << ' ';
    }
     
    return 0;
}