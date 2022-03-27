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
    if (a + b - c < 0) {
        cout << "Impossible";
    }
    else {
        cout << a + b-c;
    }
    return 0;
}