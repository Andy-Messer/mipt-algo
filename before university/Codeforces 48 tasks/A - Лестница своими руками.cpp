#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >>n;
	vector<int>ans;
	for (int i=0;i<n;i++){
		int a;
		cin >>a;
		int b,max2=-1,max=-1;
		for (int j=0;j<a;j++){
			cin >>b;
			if (b>=max) {
				max2 = max;
				max = b;
			}
			if(b>max2&&b<max){
				max2=b;
			}
		}
		if (a-2>max2-1){
			ans.push_back(max2-1);
		}else{
			ans.push_back(a-2);
		}
	}
	for (int i=0;i<n;i++){
		cout <<ans[i]<<endl;
	}
}