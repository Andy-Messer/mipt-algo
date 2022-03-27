#include <iostream> 
//это моя программа все врут)))
#include <vector> 
#include <algorithm> 
#include <set> 
#include <tuple> 
#include <cstdlib> 
#include <cstdio> 
#include <ctime> 
#define pb push_back 
#define ff first 
#define ss second 
using namespace std;

vector < pair < long long, pair <long long, long long> > > a;

struct node {
	long long data, pr, number;
	node *right, *left;
	node(long long val) {
		data = val;
		pr = rand() % 10000000;
		right = nullptr;
		left = nullptr;
	}

	~node() {
		if (right)
			delete right;
		if (left)
			delete left;
	}

};

bool exists(node *rt, long long x) {
	if (rt == nullptr)
		return false;
	if (rt->data == x)
		return true;
	if (rt->data < x)
		return exists(rt->right, x);
	else return exists(rt->left, x);
}

pair <node *, node *> split(node *rt, long long x) {
	//node* rrt = rt; 
	if (rt == nullptr)
		return{ nullptr, nullptr };
	if (rt->data < x) {
		auto res = split(rt->right, x);
		rt->right = res.first;
		return{ rt, res.second };
	}
	else {
		auto res = split(rt->left, x);
		rt->left = res.second;
		return{ res.first, rt };
	}
}

node * merge(node *rt1, node *rt2) {
	if (rt1 == nullptr)
		return rt2;
	if (rt2 == nullptr)
		return rt1;
	if (rt1->pr <= rt2->pr) {
		rt1->right = merge(rt1->right, rt2);
		return rt1;
	}
	else {
		rt2->left = merge(rt1, rt2->left);
		return rt2;
	}
}

node * add(node *rt, long long x) {
	//if (!exists(rt, x)) 
	// return rt; 
	if (exists(rt, x)) return rt;
	auto res = split(rt, x);
	node *newnode = new node(x);
	return merge(merge(res.first, newnode), res.second);
}

long long minimum(node *rt) {
	if (rt->left == nullptr)
		return rt->data;
	return minimum(rt->left);
}

long long find(node *rt, long long x) {
	if (rt == nullptr) return -1;
	auto res = split(rt, x);

	//if (res.first!=nullptr&&res.second==nullptr) { 
	// if (res.first->data==x) return res.first->data; 
	//} 
	//else 
	int y = -1;
	if (res.second != nullptr) y = minimum(res.second);
	//else return -1; 
	rt = merge(res.first, res.second);
	return y;
}

int main() {
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n;
	cin >> n;
	char c, pr_c = '1';
	long long j, pr_j = 0, question = 0;
	node *rt = nullptr;
	vector <long long> ans;
	for (long long i = 0; i < n; ++i) {
		cin >> c >> j;
		if (c == '+') {
			if (pr_c == '?')
			{
				rt = add(rt, (pr_j + j) % 1000000000);
				int yy;
				//cout « "---" « pr_j+j « "\n"; 
			}
			else rt = add(rt, j % 1000000000);
		}
		if (c == '?') {
			question = find(rt, j);
			//ans.push_back(question); 
			cout << question << endl;
		}
		pr_c = c;
		pr_j = question;
		//if (question == -1) pr_j = 0; 
	}
	//for (long long i = 0; i<ans.size(); ++i) cout « ans[i] « endl; 
}