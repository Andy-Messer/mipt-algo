#include <iostream>
using namespace std;
int main(){
int h,k,k2,j,x,y,d,m,n,i;
cin >> n>>d;
cin >>m;
k=0;
for (i=0;i<m;i++){
 cin >>x;
cin >>y;k=0;
 if (y<=x+d){
  if (y>=(-x)+d){
   if (y>=x-d){
    if (y<=(-x)+2*n-d){k=1;}}}}
 if (k==0){cout<<"NO"<<endl;}
 else {cout<<"Yes"<<endl;}}
 
return 0;
}