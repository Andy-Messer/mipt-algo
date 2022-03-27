#include <iostream>
#include <vector>
using namespace std;
char a[12][12]; int f;
void analys( int k, int m) {
	if (a[k][m] != '*') {f++;a[k][m] = '*';
		k = k + 1; 
		analys(k, m);
		k = k - 2;
		analys(k, m);
		k = k + 1; m = m - 1;
		analys(k, m);
		m = m + 2;
		analys(k, m);
	}
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			a[i][j] = '*';
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin>> a[i][j];
		}
	}
	int k, m;
	cin >> k >> m; f = 0;analys(k,m);
	cout << f;
}