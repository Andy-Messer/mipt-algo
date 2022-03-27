#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
int main(){
    int a, b, c, d,i;
    c = 0; d = 0;
    for (i = 0; i < 4; i++) {
      cin >> a>> b;
        c = c + a;
        d = d + b;
    }
    if (c > d) {
        cout << 1;
    }
    if (c == d) {
        cout << "DRAW";
    }
    if (c < d) {
        cout << 2;
    }
    return 0;
}