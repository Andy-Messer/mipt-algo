#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long a,n,b,ans;
    cin >> n;
    a = n / 100000+((n/10000)%10)+ ((n / 1000) % 10);
    b = (n%1000) / 100 + ((n / 10) % 10) + (n % 10);
    if(a==b){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}