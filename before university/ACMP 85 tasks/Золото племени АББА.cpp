#include <iostream>
#include <string>
using namespace std;
#define and &&
int main() {
    string a, b, c, d; int i,k;
    d = "0123456789";
    cin >> a >> b >> c; k = 2;
    if ((a.length() == b.length())&& (a.length() > c.length())) {
        for (i = 0; i < b.length(); i++) {
            if (k == 2) {
 
                if (d.find(b[i]) > d.find(a[i])) {
                    k = 1;
                }
                if (d.find(b[i]) < d.find(a[i])) {
 
                    k = 3;
 
                }
            }
 
 
        }
        if (k == 2) {
            k = 1;
        }
     
     
    }
    if ((a.length() > b.length()) and (a.length() == c.length())) {
        for (i = 0; i < c.length(); i++) {
            if (k == 2) {
 
                if (d.find(c[i]) > d.find(a[i])) {
                    k = 0;
                }
                if (d.find(c[i]) < d.find(a[i])) {
 
                    k = 3;
 
                }
            }
 
 
        }
        if (k == 2) {
            k = 0;
        }
 
 
    }
    if ((b.length() > a.length()) and (b.length() == c.length())) {
        for (i = 0; i < b.length(); i++) {
            if (k == 2) {
 
                if (d.find(b[i]) > d.find(c[i])) {
                    k = 1;
                }
                if (d.find(b[i]) < d.find(c[i])) {
 
                    k = 0;
 
                }
            }
 
 
        }
        if (k == 2) {
            k = 1;
        }
    }
    if ((c.length() > a.length()) and (c.length() > b.length())) {
        cout << c;
    }
    if ((a.length() == b.length()) and (a.length() == c.length())) {
        for (i = 0; i < b.length(); i++) {
            if (k == 2) {
 
                if (d.find(b[i]) > d.find(a[i])) {
                    k = 1;
                }
                if (d.find(b[i]) < d.find(a[i])) {
 
                    k = 3;
 
                }
            }
             
 
 
        }
        if (k == 2) {
            k = 1;
        }
        if (k == 1) {
            for (i = 0; i < b.length(); i++) {
                if (d.find(b[i]) < d.find(c[i])) {
 
                    k = 0;
 
                }
            }
        }
        if (k == 3) {
            for (i = 0; i < a.length(); i++) {
                if (d.find(a[i]) < d.find(c[i])) {
 
                    k = 0;
 
                }
            }
        }
 
    }
    if ((b.length() > a.length()) and (c.length() < b.length())) {
        cout << b;
    }
    if ((c.length() < a.length()) and (a.length() > b.length())) {
        cout << a;
    }
    if (k == 1) {
        cout << b;
    }
    if (k == 0) {
        cout << c;
    }
    if (k == 3) {
        cout << a;
    }
    
    return 0;
}