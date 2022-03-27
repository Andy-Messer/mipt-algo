#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <list>
 
using namespace std;
 
const char LINE = '\n';
const char TAB = '\t';
 
 
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= c + c &&b>=c+c) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}