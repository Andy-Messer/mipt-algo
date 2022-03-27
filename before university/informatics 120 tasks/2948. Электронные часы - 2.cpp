#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main() {
	int a, b, c;
	string ans, ans2, ans1;
	cin >> c;
	b = c / 60;
	c = c % 60;
	a = (b / 60)%24;
	b = b % 60;
	if (c < 10) {
		ans = to_string(c);
		ans = "0" + ans;
	}
	else {
		ans = to_string(c);
	}
	if (b < 10) {
		ans1 = to_string(b);
		ans1 = "0" + ans1;
	}
	else {
		ans1 = to_string(b);
	}
	
		ans2 = to_string(a);
	
	cout << ans2 << ':' << ans1 << ':' << ans;
	system("pause");
	return 0;
}