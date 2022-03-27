#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[100][100];
int main() {
    int w,n,h,x,max,y,i,j,x2,y2,k=0;
    cin>>w>>h;
    cin >>n;
  max=w*h;
      
     
    for (i=0;i<n;i++){
        cin >>x>>y>>x2>>y2;
        for (int p=x;p<x2;p++){
        for (j=y;j<y2;j++){
          if (a[p][j]!=1){
            a[p][j]=1;
          max--;}
        }
    }
    }
     
    cout <<max;
    return 0;
}