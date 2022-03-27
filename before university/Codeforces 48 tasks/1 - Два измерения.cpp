#include<iostream>
using namespace std;
int main() {
	long long r,l,n,k, a,ans=0;
	cin >> r >> l >> a; n = l - r+1; k = n / a;
	
	cout << ((k*(k+1))/2)*(n%a)+((k*(k-1))/2)*(a-(n%a));
}