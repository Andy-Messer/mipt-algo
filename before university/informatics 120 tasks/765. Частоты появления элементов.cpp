#include<iostream>
#include <algorithm>
using namespace std;
int ma = 0, l = 0, l2 = 0, t2 = 0;
struct item
{
	int data,vol;
	item*left;
	item*right;
};

void print(item*r)
{
	if (r != 0) {
		print(r->left);
		cout << r->data <<" "<< r->vol << endl;
		print(r->right);

	}

}

void add(item*&r, int x, int a) {
	if (r == 0) {
		r = new item;
		r->vol = 1;
		r->data = x;
		r->right = 0;
		r->left = 0;
		if (a > ma) ma = a;
	}
	else {
		if (r->data == x) {
			r->vol++;
		}
		else {
			a++;
			if (x < r->data)
				add(r->left, x, a);
			else if (x != r->data) add(r->right, x, a);
		}
	}
};
int main() {
	item*tr = 0;
	int n;
	cin >> n;
	while (n != 0) {
		add(tr, n, 0);
		cin >> n;
	}
	print(tr);


	system("pause");
};