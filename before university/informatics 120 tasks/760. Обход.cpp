#include<iostream> 
using namespace std;
int ma = 0, l = 0, l2 = 0;
struct item
{
	int data;
	item*left;
	item*right;
};
void print(item*r)
{
	if (r != 0) {
		print(r->left);
		cout << r->data<<endl;
		print(r->right);

	}

}
void add(item*&r, int x) {
	if (r == 0) {
		r = new item;
		r->data = x;
		r->right = 0;
		r->left = 0;

	}
	else {
		if (x<r->data)
			add(r->left, x);
		else if (x != r->data) add(r->right, x);
	}
};

int main() {
	item*tr = 0;
	int n;
	cin >> n;
	while (n != 0) {
		add(tr, n);
		cin >> n;
	}
	print(tr);
	

};
