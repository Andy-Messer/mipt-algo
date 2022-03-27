#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
int main() {
    string a; char b; int t;
    a = "qwertyuiopasdfghjklzxcvbnm";
    cin >> b;
    t = a.find(b) + 1;
    cout << a[t%26];
     
    return 0;
}