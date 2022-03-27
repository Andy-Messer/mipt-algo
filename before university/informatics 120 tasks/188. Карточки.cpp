#include <iostream>
#include <stack>
#include  <string>
#include <vector>
#include <math.h>
using namespace std; 
long long n,ans;
vector <long long> a(26,0);
string s;
long long fact(long long a) {
	long long l=1;
	for (long long i = 1; i <= a; i++) {
		l = l * i;
	}
	return l;
}
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		a[s[i]-'a']++;
	}
	ans = fact(s.size());
	for (int i = 0; i < 26; i++) {
		ans=ans/fact(a[i]);
	}
	cout << ans;
}