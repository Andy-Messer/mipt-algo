//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//struct pt {
//	int x, y;
//	pt(int a = 0, int b = 0) {
//		x = a; y = b;
//	}
//
//
//};
//pt operator +(pt a, pt b) {
//	return pt(b.x + a.x, b.y + a.y);
//}
//pt operator -(pt a, pt b) {
//	return pt(b.x - a.x, b.y - a.y);
//}
//pt operator * (pt a, int b) {
//	return pt(a.x*b, a.y*b);
//}
//long long sqrabs(pt a) {
//	return a.x*a.x + a.y*a.y;
//}
//
//long long operator & (pt a, pt b) {
//	return a.x*b.y - a.y*b.x;
//}
//long long pl(pt a) {
//	return a.x + a.y;
//}
//bool info(pt a) {
//	if (a.x == 0 && a.y == 0) {
//		return true;
//	}
//	return false;
//}
//long long cor(pt a) {
//	return a.x*a.x + a.y*a.y;
//}
//int main() {
//	int x1, x2, x3, y1, y2, y3, x4, y4;
//	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
//	pt a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
//	long long l1=(c-a)&(b-a),l2=(c-b)&(a-b),l3=(b-a)&(d-a),l4=(a-b)&(d-b);
//	if (l1*l3 >= 0 && l2*l4 >= 0 ) {
//		if (l1*l3*l2*l4 == 0) {
//			int k = 0;
//			if (l1 != 0) {
//				k++;
//			}
//			if (l2 != 0) {
//				k++;
//			}
//			if (l3 != 0) {
//				k++;
//			}
//			if (l4 != 0) {
//				k++;
//			}
//			if (k > 1)  {
//				cout << "NO";
//			}
//			else {
//				if (cor((b - a)) - cor((c - a)) == cor((c - b))|| cor((b - a)) - cor((d - a)) == cor((d - b))) {
//					cout << "YES";
//				}
//				else {
//					cout << "NO";
//				}
//			}
//		}
//		else {
//			cout << "YES";
//		}
//	}
//	else {
//		cout << "NO";
//	}
//	system("pause");
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
int operator * (pt a, pt b) {
	return a.x*b.x+ a.y*b.y;
}
long long sqrabs(pt a) {
	return a.x*a.x + a.y*a.y;
}

long long operator & (pt a, pt b) {
	return a.x*b.y - a.y*b.x;
}
long long pl(pt a) {
	return a.x + a.y;
}
bool info(int a) {
	if (a == 0) {
		return true;
	}
	return false;
}
long long cor(pt a) {
	if (info(a.x)) {
		return a.y*a.y;
	}
	if (info(a.y)) {
		return a.x*a.x;
	}
	return a.x*a.x;
}
int main() {
	int x1, x2, x3, y1, y2, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	pt a(x1, y1), b(x2, y2), c(x3, y3);
	long long l1 =(c-a)*(b-a),l2=(c-a)&(b-a) ;
	if (l1 <= 0&&l2==0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	system("pause");

}
