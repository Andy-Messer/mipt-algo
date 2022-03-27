#include <iostream>
using namespace std;
int a[10000][3],n,m,i,j,put[10000];
void Elem() {
    for (i = 1; i <= n; i++) {
         
            put[i] = 30000;
         
    }
    //for (i = 0; i < m; i++) {
    //  if (a[i][0] == 0) {
    //      put[a[i][1]] = a[i][2];
    //  }
    /*}
    for (i = 0; i < n; i++) {
        cout << put[i] << ' ';
    ////put[a[j][0]] != 101 &&}*/
}
void Ford_BeLL() {
    for (i = 1; i < n; i++) {
        for (j = 1; j <= m; j++) {
            if (put[a[j][0]] != 30000 && (put[a[j][0]] + a[j][2] < put[a[j][1]]||put[a[j][1]]==30000)) {
                put[a[j][1]] = put[a[j][0]] + a[j][2];
            }
        }
    }
     
}
 
int main() {
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2]; 
    }
    Elem();
    put[1] = 0;
    Ford_BeLL();
    for (i = 1; i <= n; i++) {
        cout << put[i]<<' ';
    }
     
    return 0;
}