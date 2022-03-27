#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
int main(){
    string es; char b[1], c[1];
    es = "2.71828182845904523536028750";
    int a,i,d,f;
    cin >> a;
    if (a != 0) {
        for (i = 0; i < (a + 1); i++) {
            cout << es[i];
        }
        b[0] = es[a + 1]; d = atoi(b);
        c[0] = es[a + 2]; f = atoi(c);
        if (f >= 5) {
            d = d + 1;
        }
        cout << d;
    }
    else
        cout << 3;
     
     
    return 0;
}