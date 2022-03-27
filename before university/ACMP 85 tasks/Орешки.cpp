#include <iostream>
using namespace std;
int main() {
    long long n,a,b;
    cin >> n>>a>>b;
    if (n*a >= b) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}