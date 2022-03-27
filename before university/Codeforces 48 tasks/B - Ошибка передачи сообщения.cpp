#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int* c = new int[s.length() + 1];
 
	c[0] = 0;
	for (int i = 1; i < s.length(); i++) {
		c[i] = 0;
	}
	for (int i = 1; i < s.length(); i++) {
		int j = c[i - 1];
		while (s[i] != s[j] && j > 0) {
			j = c[j - 1];
		}
		if (s[j] == s[i]) {
			c[i] = j + 1;
		}
	}
	bool flag = 0;
	if (c[s.length()-1] > (s.length() / 2)) {
		flag = 1;
	}
	if (flag) {
		cout << "YES"<<endl;
		for (long long i = s.length()-c[s.length()-1]; i < s.length(); i++) {
			cout << s[i];
		}
	}
	else {
		cout << "NO";
	}
 
	return 0;
}
