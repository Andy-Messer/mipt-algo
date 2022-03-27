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
    long long n,k;
    cin >> n>>k;
       
 cout <<(fact (n)*fact(n))/(fact (n-k)*fact(n-k)*fact(k));
}