#include<iostream>
#include<math.h>
#include <iomanip> 
using namespace std;
const long long INF = 1000000000;
int main() {
	long double x, l;
	cin >> x >> l;
	cout <<setprecision(13)<< (pow(x, 2) + pow(l, 2)) / (2 * x) - x;
}
