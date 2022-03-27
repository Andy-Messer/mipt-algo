#include <iostream>
#include <math.h>
#include <string>
using namespace std;
 
int main() {
    int max, c,i; char x; string a;
    c = max = 0;
    cin >> a;
        for (i=0;i<a.length();i++){
            x = a[i];
        if (x == '0') c = c + 1; else c = 0;
        if (c>max) max = c;
    }
    cout << max;
 
    return 0;
}