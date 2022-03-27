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
    int x, y;
    cin >> x >> y;
    if ((x == 1 && y == 1)||x<1||y<1) {
        cout << 0;
    }
    else {
    if (x == 1 || y == 1) {
        cout << 1;
    }
    else {
        if (x==y) {
            cout << 2;
        }
        else {
            cout << 1;
        }
    }
    }
     
    return 0;
}