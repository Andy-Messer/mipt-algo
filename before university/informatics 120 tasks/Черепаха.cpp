#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;
//////////////////////////

/////////////////////////////
const long double eps = 0.00009;
long double v, d; long long n;
vector <pair<long double, long double>>od;
////////////////////////////////

///////////////////////////////
bool check(long double t) {
	long double poz = 0, s = 0; bool flag = 0;
	for (long long i = 0; i < n; i++) {
		if (((od[i].first - poz)/v+t+s)>=od[i].second) {
			s = ((od[i].first - poz) / v + s+d);
		}
		else {
			s = ((od[i].first - poz) / v + s);
			if (i == n-1) {
				flag = 1;
			}
		}
		poz = od[i].first;
		
	}
	if (flag) return 0;
	return 1;
}
void ans(long double t) {
	long double poz = 0, s = 0,len=0;
	for (long long i = 0; i < n; i++) {
			s = ((od[i].first - poz) / v + s + d);
		poz = od[i].first;
	}
	long double t_ans=ceil(s + poz / v+t);

	if (int(t_ans) / 60 < 10) {
		if (int(t_ans) % 60 < 10) {
			cout << 0 << (int(t_ans) / 60) % 24 << ':' << 0 << int(t_ans) % 60;
		}
		else {
			cout << 0 << (int(t_ans) / 60) % 24 << ':' << int(t_ans) % 60;
		}
	}
	else {
		if (int(t_ans) % 60 < 10) {
			cout << (int(t_ans) / 60) % 24 << ':' << 0 << int(t_ans) % 60;
		}
		else {
			cout << (int(t_ans) / 60) % 24 << ':' << int(t_ans) % 60;
		}
	}
}
///////////////////////////////

////////////////////////////////
int main() {
	long double r, l;
	cin >> v >> d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int now_S;
		cin >> now_S;
		long double now_t_m, now_t_h;
		char mus;
		cin >> now_t_h >> mus >> now_t_m;
		od.push_back({now_S,now_t_h*60+now_t_m});
	}
	sort(od.begin(), od.end());
	l = 0; r = 10000000000; long double m;
	while (r - l > eps) {
		m = (l + r) / 2;
		if (check(m)) {
			r = m-eps;
		}
		else {
			l = m;
		}
	}
	ans(r);
	return 0;
}