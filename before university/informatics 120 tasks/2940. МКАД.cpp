#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int ans,V,T;
	cin >> V >> T;
	ans = (V * T) % 109;
	if (ans < 0) {
		ans = 109 + ans;
	}
	cout << ans;
	return 0;
}