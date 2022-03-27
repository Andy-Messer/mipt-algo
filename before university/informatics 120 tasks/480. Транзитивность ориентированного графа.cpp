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
		for (int j = 0; j < n; j++) {
			// если существует ориентированное ребро, соединяющее вершины i и j
			if (a[i][j]) {
				for (int z = 0; z < n; z++) {
					if (a[j][z] && !a[i][z]) {
						cout << "NO";
						return 0;
					}
				}
			}
		}
	}
	cout << "YES";
}