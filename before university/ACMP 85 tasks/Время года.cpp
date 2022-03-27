#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <list>
 
using namespace std;
 
const char LINE = '\n';
const char TAB = '\t';
 
 
int main() {
    int a;
    cin >> a;
    if (a > 12) {
        cout << "Error";
    }
    else {
        a = (a + 1) % 13;
        if (a < 4) {
            cout << "Winter";
        }
        else {
            if (a < 7) {
                cout << "Spring";
                 
            }
            else {
                if (a < 10) {
                    cout << "Summer";
                }
                else {
                    cout << "Autumn";
                }
            }
        }
    }
    return 0;
}