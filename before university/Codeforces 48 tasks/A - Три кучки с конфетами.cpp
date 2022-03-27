
 #include<iostream>
#include<vector>
using namespace std;
int main(){
	int q;
	cin >>q;
	vector<long long>ans;
	for(int i=0;i<q;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		long long sum=a+b+c;
		ans.push_back(sum/2);
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
}