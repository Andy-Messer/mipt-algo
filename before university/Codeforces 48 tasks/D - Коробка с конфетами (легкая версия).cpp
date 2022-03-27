#include <iostream>
#include <algorithm>
#include<math.h>
#include<vector>
#include<map>
#include <stack>
using namespace std;
vector<int>ans;
int main() {
	int q;
	cin >> q;
	for (int l = 0; l < q; l++) {
		int n;
		cin >> n;
	
		vector<int>c(n+1,0);
		
		for (int i = 0; i < n; i++) {
			int b;
			cin >> b;
			
			c[b]++;
		}
		sort(c.begin(),c.end());
		int f = c[n], sum = 0,k=n;
		while (f > 0) {
			if (c[k]>=f) {
				sum += f; k--;
			}
			f--;
		}
		
		ans.push_back(sum);
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i]<<'\n';
	}
}