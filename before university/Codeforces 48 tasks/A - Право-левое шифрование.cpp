#include <iostream>
#include <string>
using namespace std;
int main() {
	string s,s2;
	int l = 0, k = 0, p = 1,f;
	cin >> s;
	if (s.length() > 1){
		if (s.length() % 2 == 0) {
			while (s2.length() < s.length()) {
				if (l == 0) {
					f = s.length() / 2 - 1;
					s2 = s2 + s.substr((f - k), 1); k++; l = 1;
				}
				else {
					f = s.length() / 2 - 1;
					s2 = s2 + s.substr((f + p), 1); p++; l = 0;
				}
 
			}
		}
		else {
			while (s2.length() < s.length()) {
				if (l == 0) {
					f = s.length() / 2;
					s2 = s2 + s.substr((f - k), 1); k++; l = 1;
				}
				else {
					f = s.length() / 2;
					s2 = s2 + s.substr((f + p), 1); p++; l = 0;
				}
 
			}
		}
		cout << s2;
	}
	else {
		cout << s;
	}
		
		
	return 0;
 
}
