#include <iostream>
#include <string>
using namespace std;
 
int main() {
	int n;
	string s;
	cin >> n>>s;
	int i = 0;
	string a = s.substr(i, 1),b= s.substr(i + 1, 1);
	while (a<=b &&i<s.size()-1)
	{
		i++;
		a = s.substr(i, 1); b = s.substr(i + 1, 1);
	}
	if (i == s.size()-1) {
		cout << "NO";
	}
	else {
		cout << "YES" << endl;
		cout << i+1 << ' ' << i + 2;
	}
 
	return 0;
}
