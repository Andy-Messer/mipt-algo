#include<iostream>
#include<bitset>
using namespace std;
const long long INF = 1000;
long long ans,t,f,n,p;
int count(long long f) {
	long long loc=0;
	while (f > 0) if ((f & 1) == 1) { loc++; f = f >> 1; }
	else { f = f >> 1; }
	return loc;
}
bool check(long long k) {
	if (count(f-k*p)>k||count(f - k * p)<=0||(f-k*p<k)) {
		return 0;
	}
	else {
		if (count(f-k*p) <= k) {
			if (k < ans) ans = k;
		}
		return 1;
	}
}
int main() {
	long long  m, r, l;
	cin >> n>>p; f = n; ans = INF;
	for (long long j = 1; j < 32; j++) {
		if (check(j)) {
			break;
		}
	}
	if (ans!=INF)
		cout << ans;
	else {
		cout << -1;
	}
}
