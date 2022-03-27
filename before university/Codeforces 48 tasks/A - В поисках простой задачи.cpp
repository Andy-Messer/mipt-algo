#include <iostream>
using namespace std;
int main(){
int h,k,k2,j,i;
cin>>h;k=0;
for (int i=0; i<h;i++){
   cin >> j;
   if (j==1) k=1;}
if (k==1) cout<<"HARD";
if (k==0) cout<<"easy";
return 0;
}