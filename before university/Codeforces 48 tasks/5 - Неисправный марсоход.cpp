#include<iostream>
using namespace std;
int main() {
	long long a, b, c, k_1, k_2;
	cin >> a >> b >> c;
	k_1 = (a/c+1)*c;
	k_2 = b / c * c;
	if (k_1 > k_2) cout << (b - a + 1) / 2;
	else
	cout << (k_1-a)/2+ ((c+1)/2)*((k_2-k_1)/c)+((b-k_2+2)/2);
 
}