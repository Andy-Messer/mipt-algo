#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
 
using namespace std;
const long long INF = 1000000000;
vector<long long> a;
vector <long long>dp;
int main() {
	long long q, m;
	cin >> q;
	for (long long i = 0; i < q; i++) {
		long long n;
		cin >> n;
		if (n % 2 == 0) {
			if (n > 3) {
				cout << 0;
			}
			else {
				cout << 4 - n;
			}
		}
		else {
			cout << 1;
		}
		cout << endl;
	}
}