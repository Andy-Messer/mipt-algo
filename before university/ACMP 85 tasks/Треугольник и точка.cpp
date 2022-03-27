#include <iostream>
using namespace std;
 
int rast(int x,int y,int x2,int y2,int x3,int y3) {
    return x*y2+y*x3+x2*y3-x*y3-y*x2-x3*y2;
}
 
int main() {
    long long a, b,f1,f2,f3, x_1, y_1, x_2, y_2, x_3, y_3, d_1, d_2, d_3;
     
    cin >> x_1 >> y_1;
    cin >> x_2 >> y_2;
    cin >> x_3 >> y_3;
    cin >> a>> b;
    d_1 = rast( x_1, y_1, x_2, y_2,a, b ); 
    d_2 = rast(  a,b,x_2, y_2,x_3, y_3); 
    d_3 = rast(x_3, y_3,x_1, y_1,a, b  ); 
    if ((d_1>=0&&d_2>=0&&d_3>=0)|| (d_1 <= 0 && d_2 <= 0 && d_3 <= 0)) {
        cout << "In";
    }
    else {
        cout << "Out";
    }
 
    return 0;
}