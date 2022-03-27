#include <iostream>
using namespace std;
int main() {
	int n, i = 1, pr, a = 0, l = 0, l2 = 0,max=0;
	int st=1;
	cin >> n;
	while (i<=n){
		pr = a;
		cin >> a;
		i++;
		if (pr != a) {
			
			if (l2 < l) {
				if (l2 > max) {
					max = l2;
				}
			}
			else {
				if (l > max) {
					max = l;
				}
			}
			l2 = l;
			l = 0;
			l++;
		}
		else {
			l++;
		}
	}
	if (l2 < l) {
		if (l2 > max) {
			max = l2;
		}
	}
	else {
		if (l > max) {
			max = l;
		}
	}
	l2 = l;
	l = 0;
	l++;
	cout << max * 2; 
	
	return 0;
}