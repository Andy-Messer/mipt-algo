#include <iostream>
#include<string>
#include <vector>
using namespace std;
int main(){
vector <int> ans;
int t,n,x;cin >>t;
for (int i=0;i<t;i++){
	cin>>n>>x;
	long long k=x*2;
 
	ans.push_back(k);
}
for (int i=0;i<ans.size();i++){
	cout <<ans[i]<<endl;
}
}