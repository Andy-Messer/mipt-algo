
 #include <iostream>
#include <math.h>
#include<vector>
#include<string>
using namespace std;
int main() {
	long long n;
	cin >> n;
	vector<vector<long long>>a(n, vector<long long>(n, 0));
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	long long x = 0;
	for (long long i = 0; i < n-2; i++) {
		x=sqrt((a[i][i + 1] * a[i][i + 2]) / a[i + 1][i + 2]);
		cout << x << ' '; a[i][i] = x;
	}
	a[n-2][n-2] = a[n - 2][n - 3] / x;
	cout << a[n-2][n-2]<<' ';
	cout << a[n - 1][n - 2] / a[n-2][n-2];
 
}