#include <iostream>
using namespace std;

void sum() {
	int x;
	cin >> x;
	if (x != 0) {
		sum();
	}
	cout << x<<endl;
}
int main() {
	sum();
}