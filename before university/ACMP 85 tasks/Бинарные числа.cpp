#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <list>
 
using namespace std;
 
const char LINE = '\n';
const char TAB = '\t';
 
 
int main() {
    int a,i;
    cin >> a;
    for ( i = 1; i < a; i = i * 2) {}
    if (i == a) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}