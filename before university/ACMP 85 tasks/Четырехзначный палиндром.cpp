#include <iostream>
#include <string>
using namespace std;
int main() {
    long long a,n,b;
    string s,ans;
    cin >> s;
    a = 1-1;
    b = s.length()-1;
    ans = "YES";
    while (a <= b) {
        if (s[a] == s[b]) {
            a++; b--;
        }
        else {
            ans = "NO"; a = 0; b = -1;
        }
    }
    cout << ans;
     
    return 0;
}