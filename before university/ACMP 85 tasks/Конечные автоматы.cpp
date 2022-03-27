#include <iostream>
#include <math.h>
#include <string>
using namespace std;
 
int main() {
    long long i,n,v,a, b;
    cin >> n;
    int *c = new int[n];
    for (i = 0; i < n; i++) {
    cin >> a >> b;  
    c[i] = 19 * b + ((a + 239)*(a + 366)) / 2;
    }
    for (i = 0; i < n; i++) {
        cout << c[i] << endl;
    }
     
    return 0;
}