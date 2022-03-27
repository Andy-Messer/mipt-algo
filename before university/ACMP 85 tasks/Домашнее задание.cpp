#include <iostream>
#include<math.h>
using namespace std;
int main() {
    int n, k, min, max, sum,l,l2, s, s2, s1; sum = 0; 
     
    cin >> n; int a[100]; min = 100000000; max = -10000000;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (a[i] < min) {
            min = a[i];
            l = i;
        }
        if (a[i] > max) {
            max = a[i];
            l2 = i;
        }
        if (a[i] > 0) sum = sum + a[i];
    }
    s1 = 1;
    s2 = 1;
    if (l2 < l)
        for (int i = l2+1; i < l; i++)
            s1 = s1 * a[i];
    if (l2 > l)
        for (int i = l + 1; i < l2; i++)
            s1 = s1 * a[i];
     
    cout << sum << ' ' << s1;
    return 0;
}