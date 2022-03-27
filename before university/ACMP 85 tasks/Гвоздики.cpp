#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std; 
 
int main() { 
int n; 
cin >> n; 
vector <int> a(n); 
vector <int> f(n, 0); 
int i; 
for (i=0; i<n; ++i) cin >> a[i]; 
sort(a.begin(), a.end()); 
f[0]=0; 
f[1]=a[1]-a[0]; 
if (n>2) f[2]=f[1]+(a[2]-a[1]); 
for (i=3; i<n; ++i) 
{ 
if (f[i-1]<f[i-2]) f[i]=f[i-1]; 
else f[i]=f[i-2]; 
f[i]+=a[i]-a[i-1]; 
} 
//for (i=0; i<n; ++i) cout « f[i] « " "; 
cout << f[n-1]; 
}