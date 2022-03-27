#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector <int> viz;
vector <int> f;
int n,k=0,m,ans=0;
vector <pair <int,pair <int,int>>> a;
int gl(int v) {
    if (v == f[v]) {
        return v;
    }
    else {
        return gl(f[v]);
    }
}
int main() {
    cin >> n>>m;
     
    for (int i = 0; i < n; i++) {
        f.push_back(i);
    }
 
    viz.resize(n,-1);
    for (int i = 0; i < m; i++) {
         
        int b,c,d;
        cin >> b >> c >> d; b--; c--;
        a.push_back({ d, { b,c } });
 
    }
 
    sort(a.begin(), a.end());
 
    int s=0,l = 0;
    while (l < n - 1&&s<m) {
        if (gl(a[s].second.first) != gl(a[s].second.second)) {
            ans += a[s].first; l++;
            f[gl(a[s].second.first)] = gl(a[s].second.second);
        }s++;
    }
     
     
        cout << ans;
     
     
    return 0;
     
}