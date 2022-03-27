#include <iostream>
#include <iterator>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
 
int main() {
    int n,count=0;
     
     
     
    cin >> n;vector <int> a(n,1e9);
    cin >> a[count]; count++;
    for (int i = 1; i < n; i++) {
        int b;
        cin >> b;
        vector<int>::iterator  k = lower_bound(a.begin(), a.end(), b);
        if (count < k - a.begin()+1) {
            count = k - a.begin()+1;
        }
        *k = b;
    }
    //for (int i = 0; i < n; i++) {
    //  cout << a[i]<<' ';
    //}
    cout << count;
 
}