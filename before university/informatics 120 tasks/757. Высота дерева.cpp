#include<iostream> 
using namespace std;
int ma = 0;
struct item
{
	int data;
	item*left;
	item*right;
};

void add(item*&r, int x, int a) {
	if (r == 0) {
		r = new item;
		r->data = x;
		r->right = 0;
		r->left = 0;
		if (a>ma) ma = a;
	}
	else {
		a++;
		if (x<r->data)
			add(r->left, x, a);
		else if (x != r->data) add(r->right, x, a);
	}
};

int main() {
	item*tr = 0;
	int n;
	cin>>n;
	while (n != 0) {
		add(tr, n, 1);
		cin>>n;
	}
	cout<<ma;
};