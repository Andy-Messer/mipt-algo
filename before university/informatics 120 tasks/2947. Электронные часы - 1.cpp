#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int a,ans1,ans2;cin >> a;
	ans1 = a / (60);
	ans2 = a % (60 * 24);
	cout << ans1%24<<' '<<ans2%60;
	system("pause");
	return 0;
}