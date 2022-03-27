#include<iostream>
#include <algorithm>
using namespace std;
int ma = 0, l = 0, l2 = 0, t2 = 0;
struct item
{
	int data;
	item*left;
	item*right;
};

int high(item*&r) {
	if (r == 0) 
		return 0;
		return 1+max(high(r->right),high(r->left));
	}

bool balance(item*&r) {
	if (r != 0) {
		if (abs(high(r->right) - high(r->left)) > 1)
			return false;
		
		return	balance(r->right)&&	balance(r->left);
	}
	return true;
}


void add(item*&r, int x, int a) {
	if (r == 0) {
		r = new item;
		r->data = x;
		r->right = 0;
		r->left = 0;
		if (a > ma) ma = a;
	}
	else {
		a++;
		if (x < r->data)
			add(r->left, x, a);
		else if (x != r->data) add(r->right, x, a);
	}
};
int main() {
	item*tr = 0;
	int n;
	cin >> n;
	while (n != 0) {
		add(tr, n,0);
		cin >> n;
	}
	
	if (balance(tr)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	system("pause");
};
