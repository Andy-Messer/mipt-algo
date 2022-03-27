#include <iostream>
#include <string>
using namespace std;
int main() {
    string s,f;
    cin >> s >>f;
    s = f +"-"+ s;
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
    for (int i = f.length(); i < s.length(); i++) {
        int j = f.length();
        if (c[i] == j) {
            cout << i - f.length() - f.length()<<' ';
        }
    }
 
    return 0;
}