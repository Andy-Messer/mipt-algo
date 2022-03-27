
#include<iostream>
#include <vector>
#include<math.h>
#include<climits>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<string>
#include<fstream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <numeric>
#include <bitset>
 
#define IOS ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl "\n";
 
typedef long long ll;
typedef long double ld;
const ll INF = 1e9+7;
const ll INF_bit = 1e9 - 1;
const ld EPS = 0.000000001;
typedef unsigned long long ull;
typedef std::string str;
typedef std::vector<long long> vec;
typedef std::bitset <INF_bit> bit;
typedef std::vector<std::pair<long long, long long>> pvec;
typedef std::vector<std::vector<long long>> vec2;
 
#pragma warning(disable : 4996)
ll up[5001][5000], down[5001][5000];
int main() {
	ll n, k;
	std::cin >> n >> k;
	
	
 
	for (ll i = 1; i <= n; i++) {
		
		up[i][i] = 1;
		down[i][i] = 1;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= i; j++) {
			if (i != j) {
				if (i - j >= j + 1) {
					up[i][j] = (down[i - j][i - j] - down[j][i-j]) % INF;
				}
				if (j - 1 >= 1) {
					if (j <= i - j) {
						down[i][j] = (up[j - 1][i - j]) % INF;
					}
					else {
						down[i][j] = (up[i - j][i - j]) % INF;
					}
				}
			}
			if (up[i][j] > 0 && up[i][j] < 1e9) {
				ll p = up[i][j];;
				if (i == j) {
					p = 1;
				}
					
				up[j][i] = up[j - 1][i] +p ;
			}
			else {
				up[j][i] = up[j - 1][i];
			}
			if (down[i][j] > 0 && down[i][j] < 1e9) {
				ll p = down[i][j];;
				if (i == j) {
					p = 1;
				}
				down[j][i] = down[j - 1][i] + p;
			}
			else {
				down[j][i] = down[j - 1][i];
			}
			/*{std::cout << endl; std::cout << "DOWN" << endl;
				for (ll i2 = 1; i2 <= n; i2++) {
					for (ll j2 = 1; j2 <= n; j2++) {
						std::cout << down[i2][j2] << ' ';
					}
					std::cout << endl;
				}
				std::cout << endl; std::cout << "UP" << endl;
				for (ll i2 = 1; i2 <= n; i2++) {
					for (ll j2 = 1; j2 <= n; j2++) {
						std::cout << up[i2][j2] << ' ';
					}
					std::cout << endl;
				}}
		}*/
		/*
		{std::cout << endl; std::cout << "S_DOWN" << endl;
			for (ll i2 = 1; i2 <= n; i2++) {
				for (ll j2 = 1; j2 <= n; j2++) {
					std::cout << S_down[i2][j2] << ' ';
				}
				std::cout << endl;
			}
			std::cout << endl; std::cout << "S_UP" << endl;
			for (ll i2 = 1; i2 <= n; i2++) {
				for (ll j2 = 1; j2 <= n; j2++) {
					std::cout << S_up[i2][j2] << ' ';
				}
				std::cout << endl;
			}*/}
		
		/*for (ll j = i; j > 0; j--) {
			for (ll f = j + 1; f <= i - j; f++) {
				up[i][j] =(up[i][j]+ down[i - j][f])%INF;
			}
		}
		for (ll j = 1; j <= i; j++) {
			for (ll f = 1; f <= j-1; f++) {
				down[i][j]=(down[i][j] + up[i - j][f])%INF;
			}
		}*/
	}
	/*
	for (ll i = 0; i <= n; i++) {
		for (ll j = i - 1; j >= 0; j--) {
			up[i][j] = up[i][j + 1] + down[i - j][j + 1];
		}
		for (ll j = 1; j < i; j++) {
			down[i][j] = down[i][j - 1] + up[i][j - 1];
		}
	}*/
	/*std::cout << endl;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			std::cout << up[i][j] << ' ';
		}
		std::cout << endl;
	}
	std::cout << endl;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			std::cout << down[i][j] << ' ';
		}
		std::cout << endl;
	}*/
	if (n != k) {
		std::cout << (down[n][k] + up[n][k])%INF;
	}
	else {
		std::cout << 1;
	}
}