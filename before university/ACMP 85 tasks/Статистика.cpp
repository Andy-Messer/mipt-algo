#include <iostream> 
 
using namespace std;
 
int main() {
    long B, sum,i,n;
    cin >> n;
    int *mass = new int[n+1];
    int *mass2 = new int[n+1];
    mass[n + 1] = 0;
    mass2[n + 1] = 0;
    for (i = 1; i <= n; i++) {
        cin >> mass[i];
        if (mass[i] % 2 == 0) {
            mass2[i] = 1; mass[n + 1] = mass[n + 1]++;//четверки
        }
        else {
            mass2[i] = 0; mass2[n + 1] = mass2[n + 1]++;//тройки
        }
    }
    for (i = 1; i <= n; i++) {
        if (mass2[i] == 0) {
            cout << mass[i]<<" ";
       }
    }
    cout << endl;
    for (i = 1; i <= n; i++) {
        if (mass2[i] == 1) {
            cout << mass[i] << " ";
        }
    }
    cout << endl;
    if (mass[n + 1] >= mass2[n + 1]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
 
}