#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >>n;
	vector <int>a(n);
	int max=-1;
	int r;
	for (int i=0;i<n;i++){
		cin >>a[i];
		if (a[i]>max){
			max=a[i];r=i;
		}
	}
	int i=r-1,j=r+1;int now=a[r];bool flag=0;
	while ((i>-1||j<n)&&flag==0){
		if (i==-1){
			if (a[j]<now){
				now=a[j];j++;
			}else{
				flag=1;
			}
		}else{
		if (j==n){
			if (a[i]<now){
				now=a[i];i--;
			}else{
				flag=1;
			}
		}else{
			if (a[i]<now&&a[j]<now){
				if (a[i]>a[j]){
					now=a[i];i--;
				}else{
					now=a[j];j++;
				}
			}else{
				flag=1;
			}
		}
		}
 
	}
	if (!flag){
		cout<<"YES";
	}else{
		cout <<"NO";
	}
}
