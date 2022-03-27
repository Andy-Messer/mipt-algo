#include<iostream>
#include<vector>
using namespace std;

int main() {
	long long n, t, x_c, y_c, z_c;
	cin >> n >> t;
	vector <vector<long long>>yz(n + 1, vector<long long>(n, 0));
	vector<vector<long long>>yx(n, vector<long long>(n / 30 + 1, 0)), zx(n, vector<long long>(n / 30 + 1, 0));
	for (long long i = 0; i < t; i++) {
		long long x, y, z;
		cin >> x >> y >> z; x--; y--; z--;
		yz[y][z] = 1;
		yx[y][x / 30] = yx[y][x / 30] | (1 << ((x % 30)));
		zx[z][x / 30] = zx[z][x / 30] | (1 << ((x % 30)));
	}
	bool flag = 0; long long y, z;
 	for ( y = 0; y < n; y++) {
		for ( z = 0; z < n; z++) {
			
 			if (yz[y][z] == 0) {
				for (long long k = 0; k <= n / 30; k++) {
					if ((yx[y][k] | zx[z][k]) != (1 << 29)+((1<<29)-1)) {
						for (long long k2 = 0; k2 < 30; k2++) {
							if (k*30+k2<n) {
								long long f = ((yx[y][k] >> k2) & 1), f2 = (zx[z][k] >> k2) & 1;
								if (f == 0 && f2 == 0) {
									y_c = y; z_c = z; x_c = k * 30 + (k2); flag = 1; break;
								}
							}
						}
					}
					if (flag)break;
				}
			}
			if (flag)break;
		}
		if (flag)break;
	}
	if (!flag) {
		cout << "YES";
	}
	else {
		cout << "NO" << endl;
		cout << ++x_c << ' ' << ++y_c << ' ' << ++z_c;
	}
}