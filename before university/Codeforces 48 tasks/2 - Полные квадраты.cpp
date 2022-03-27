#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<pair<long long, long long>>f;
void del(long long k) {
	for (long long i = 1; i <= sqrt(abs(k)); i++) {
		if (k % i == 0) {
			if (i % 2 == ((abs(k) / i) % 2)) {
				f.push_back({ i,k / i });
			}
		}
	}
}
int main() {
	long long k,ans=0;
	bool flag = 0;
	cin >> k;
	del(k);
	if (f.size()>0)
	ans = (abs(f.back().second + f.back().first)) / 2;
	if (k != 0) {
		if (f.size() == 0) {
			cout << "none";
		}
		else {
			cout << ans;
		}
	}
	else {
		cout << 0;
	}
}