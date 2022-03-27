#include <iostream> 
using namespace std;
 
int main(){
    int a,sum;
cin >> a;
if (a > 0) {
sum = (a*(a + 1))/ 2;
}
else
{
    sum = (a*(a - 1)) / (-2)+1;
}
 
cout << sum;
return 0;
 
}