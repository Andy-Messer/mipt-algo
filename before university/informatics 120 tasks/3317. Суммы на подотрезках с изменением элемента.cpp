#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;
long long n,m,m2;
vector <long long> a;
vector <long long> tr;
void build(long long v,long long vl,long long vr){
	if (vl+1==vr){
		tr[v]=a[vl];
	}else{
		long long m=(vl+vr)/2;
		build (2*v+1,vl,m);
		build(2*v+2,m,vr);
		tr[v]=tr[2*v+1]+tr[v*2+2];
	}
}
long long s(long long v,long long vl,long long vr,long long l,long long r){
	if (r<=vl||l>=vr) return 0;
	if (l<=vl&&r>=vr)
		return tr[v];
	long long m=(vl+vr)/2;
	return s(2*v+1,vl,m,l,r)+s(2*v+2,m,vr,l,r);
}
void u(long long v,long long vl,long long vr,long long i,long long x){
	if (vl+1==vr){
		tr[v]=x;
	}else{
		long long m=(vl+vr)/2;
		if (i<m){
			u(2*v+1,vl,m,i,x);
		}else{
			u(2*v+2,m,vr,i,x);
		}
		tr[v]=tr[2*v+1]+tr[v*2+2];
	}
}
int  main(){
	cin >>n;
	vector <long long>ans;
	a.resize(n);
	tr.resize(4*n,0);
	for (long long i=0;i<n;i++){
		cin>>a[i];
	}
	build(0,0,n);

	cin >>m2;
	for (long long i=0;i<m2;i++){
		char ch;
		long long a,b;
		cin >>ch;
		if (ch=='u'){
			cin >>a>>b;
			a--;
			u(0,0,n,a,b);
		}else{
			cin >>a>>b;a--;
			ans.push_back(s(0,0,n,a,b));
		}
	}
	cout <<endl;
	for (long long i=0;i<ans.size();i++){
		cout <<ans[i]<<' ';
	}
}