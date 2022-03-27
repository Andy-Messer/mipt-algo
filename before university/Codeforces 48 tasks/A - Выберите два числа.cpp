#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m;
	vector<int>c(401, 0);
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; c[a[i]]++;
	}
	cin >> m;
	vector<int>b(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> b[i]; c[b[i]]++;
	}
	int ans, ans2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[a[i] + b[j]] == 0) {
				ans = a[i];
				ans2 = b[j];
			}
		}
	}
	cout << ans << ' ' << ans2;
 
	return 0;
}