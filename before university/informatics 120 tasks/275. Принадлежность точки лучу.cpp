#include <iostream>
#include <algorithm>

using namespace std;
struct pt {
	int x, y;
	pt(int a = 0, int b = 0) {
		x = a; y = b;
	}
	

};
pt operator +(pt a, pt b) {
	return pt(b.x + a.x, b.y + a.y);
}
pt operator -(pt a, pt b) {
		return pt(b.x - a.x, b.y - a.y);
}
pt operator * (pt a, int b) {
	return pt(a.x*b, a.y*b);
}
long long sqrabs(pt a) {
	return a.x*a.x + a.y*a.y;
}

long long operator & (pt a, pt b) {
	return a.x*b.y - a.y*b.x;
}

int main() {
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	pt c(x1, y1), a(x2, y2), b(x3, y3);
	long long l = (b - a)&(c - a);
	if (l == 0) {
		if (((b-a).x)*((c-a).x)>=0&&((b-a).y)*((c-a).y)>=0) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
	
}