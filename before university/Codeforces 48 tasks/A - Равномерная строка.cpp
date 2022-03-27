#include <iostream>
#include <string>
using namespace std;
int main() {
	int t,i,n,k,j;
	cin >> t;
	string s = "abcdefghijklmnopqrstuvwxyz",f;
	string a;
	for (j = 0; j < t; j++) { 
		 a="";
		cin >> n >> k;
		if (n == k) {
			a = s.substr(0, k);
			f = f+ a+"#" ;
		}
		else {
			if (k > n) {
				a = s.substr(0, n);
				f = f + a + "#";
			}
			else {
				if (n % k != 0) {
					for (i = 0; i < (n / k); i++) {
						a =a+ s.substr(0, k);
					}
					a =a+ s.substr(0, (n%k));
					f = f + a + "#";
				}
				else {
					if (n % k == 0) {
						for (i = 0; i < (n / k); i++) {
							a = a + s.substr(0, k);
							}f = f + a + "#";
					}
				}
			}
		}
	}
	f = f +".";
	i = 0;
	while (f.substr(i, 1) != ".") {
		while (f.substr(i, 1) != "#") {
			cout << f.substr(i, 1);
			i++;
		}
		i++; cout << endl;
	}
	return 0;
}
