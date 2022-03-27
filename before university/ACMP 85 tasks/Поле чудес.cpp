#include <iostream>
#include <string>
using namespace std;
int main() {
    string s; int a; int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
         
            s += a;
 
    }
     
    int *c = new int[s.length() + 1];
 
    c[0] = 0;
    for (int i = 1; i < s.length(); i++) {
        c[i] = 0;
    }
    for (int i = 1; i < s.length(); i++) {
        int j = c[i - 1];
        while (s[i] != s[j] && j > 0) {
            j = c[j - 1];
        }
        if (s[j] == s[i]) {
            c[i] = j + 1;
        }
    }
    int p=c[n-1];
    if ((n - 1) % (n-p)==0) {
        cout << n - p;
    }
    else {
        cout <<n-1;
    }
 
    return 0;
}