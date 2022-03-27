#include <iostream> 
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
 
using namespace std;
 
int main() {
    long long b;
     
    string mass; string mass2; string a; string u;
    mass = "ABCDEFGH";
    mass2 = "12345678";
    u = "-";
     
    long long k;
    k = 0;
    getline(cin, a);
    long long len;
    len = a.length();
     
    if ((len > 5)|(len < 5)) {
        cout << "ERROR";
    }
    else {
        b = mass.find(a[0]);
        if (b != -1) {
            b = mass2.find(a[1]);
            if (b != -1) {
                if (u.find(a[2]) == 0) {
                    b = mass.find(a[3]);
                    if (b != -1) {
                        b = mass2.find(a[4]);
                        if (b != -1) {
                            //начало адеквата
                            if (labs(mass2.find(a[1]) - mass2.find(a[4])) == 1){
                                if (labs(mass.find(a[0]) - mass.find(a[3])) == 2) {
                                    cout << "YES"; k++;
                                }
                            }
                            if (labs(mass2.find(a[1]) - mass2.find(a[4])) == 2) {
                                if (labs(mass.find(a[0]) - mass.find(a[3])) == 1) {
                                    cout << "YES"; k++;
                                }
                            }
                            if (k == 0) {
                                cout << "NO";
                            }
                        }
                        else {
                            cout<< "ERROR";
                        }
                    }
                    else {
                        cout << "ERROR";
                    }
                }
                else {
                    cout << "ERROR";
                }
            }
            else {
                cout << "ERROR";
            }
        }
        else {
            cout << "ERROR";
        }
    }                       
    return 0;
 
}