#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a = n + n - 1,ans=0;
	for (int i = 1; i < n + n - 1; i = i + 2) {
		ans += i;
	}
	ans = ans * 2+a;
	cout << ans;
	return 0;
}