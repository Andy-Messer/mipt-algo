#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1,f, s2; int p;
    cin >> s1 >> s2;
    if (s1.length() > s2.length()) p = s1.length();
    else p = s2.length();
    int *a = new int[p+2];
    int *b = new int[p+2];
    int i;
    for (i = 0; i <= p; i++) {
        a[i] = 0; b[i] = 0;
    }
    for (i = s1.length(); i >= 0; i--) {
        f = s1.substr(i, 1);
        a[(p+1) - (s1.length() - i)] = atoi(f.c_str());
    }
    for (i = s2.length(); i >= 0; i--) {
        f = s2.substr(i, 1); 
        b[(p+1) - (s2.length() - i)] = atoi(f.c_str());
    }
     
    int q = 0;
    for (i = p+1; i >= 0; i--) {
         
        b[i] = a[i] + b[i] + q; q = 0;
        if (b[i] / 10 > 0) {
            q = 1;
             
        }
        b[i] = b[i] % 10;
    }
     
    int k = 0;
    for (i = 0; i <= p; i++) {
        if (b[i] != 0 && k == 0) {
            cout << b[i];
            k = 1;
        }
        else {
            if (k==1)
            cout << b[i];
        }
    }
    if ((b[p]==0)&&k!=1)
    cout << b[p];
 
    return 0;
}