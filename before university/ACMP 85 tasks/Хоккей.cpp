#include <iostream>
#include <stack>
#include  <string>
#include <vector>
#include <math.h>
using namespace std; 
 
long long fact(long long a) {
    long long l=1;
    for (long long i = 1; i <= a; i++) {
        l = l * i;
    }
    return l;
}
int main() {
    long long n;
    cin >> n;   
    if (n>=3)
    cout << n*(n-1)*(n-2);
    if (n < 3) {
        cout <<n;
    }
}