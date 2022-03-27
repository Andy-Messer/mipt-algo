#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int main() {
    string s;
    cin >> s;
    string a, b;
    a = s.substr(0, 1);
    b = s.substr(1, 1);
    if (a[0] % 2 == 0) {
        if (b[0] % 2 == 0) {
            cout << "BLACK";
        }
        else {
            cout <<"WHITE";
        }
    }
    else {
        if (b[0] % 2 == 1) {
            cout << "BLACK";
        }
        else {
            cout << "WHITE";
        }
    }
     
    return 0;
}