#include <iostream>
#include <math.h>
#include <string>
using namespace std;
 
int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        cout << ">";
    }
    if (a == b) {
        cout << "=";
    }
    if (a < b) {
        cout << "<";
    }
     
    return 0;
}