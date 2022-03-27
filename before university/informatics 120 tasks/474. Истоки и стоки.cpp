#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;
int a[100][100];
bool b[100][2];
vector <int> c, d;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
	}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			b[i][j] = false;
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][0]==false){
				if (a[i][j] == 1) {
					b[i][0] = true;
				}
			}
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (b[j][1] == false) {
				if (a[i][j] == 1) {
					b[j][1] = true;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i][1] == false) {
			c.push_back(i);
		}
			if (b[i][0]!=true)
			d.push_back(i);
	}
	cout << c.size()<<endl;
	for (int i = 0; i < c.size(); i++) {
		cout << c[i]+1<<endl;
	}
	cout << d.size()<<endl;
	for (int i = 0; i < d.size(); i++) {
		cout << d[i]+1<<endl;
	}
}