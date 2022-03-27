#include <iostream> 
#include <cmath> 
using namespace std; 
main() { 
int c1,c2,x1,x2,y1,y2,c; 
double s; 
cin>>x1>>y1>>x2>>y2; 
c1=x2-x1; 
c2=y2-y1; 
c=c1*c1+c2*c2; 
s=sqrt(c); 
printf("%.5lf",s); 
}