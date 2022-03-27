#include <iostream>
#include <string>
using namespace std;
int main() {
    string s; string m; int k; k = 0;
    cin >> s;
    s = s+"X" ;
    int st = 0;
    string pr = "1", cur="", cc="";
    bool f = true;
    if (s[0] >= '0' && s[0] <= '9') f = false;
    for (int i = 0; i < s.length() && f; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (cur == pr) f = false;
            pr = cur;
//          st = 1;
            cur = s[i];
            if (cc[0 ]== '0' || cc == "1") f = false;
            cc = "";
        }
        if (s[i]>='a' && s[i]<='z')
 
              cur = cur + s[i];
             
        if (s[i] >= '0' &&s[i] <= '9')
                  cc += s[i];
                 
    }
     
    if (f) cout << "YES"; else cout << "NO";
    /*
    int i = 1;
    m = s[0]; if (s[1] >='a' &&s[1]<='z') {
        m = m + s[1]; i = 2;
    }
    if ( s[0] >='0' && s[0]<='9') {
        k = 1;
    }
    else
    for (; i < s.length(); i++) {
    if ((s[i] < '0') || (s[i] > '9')) {
            if (s[i] == m[0]) {
                if (m.length() == 2) {
                    if (i < s.length() - 1) {
                        if ((s[i + 1] > 'Z')) {
                            if ((m[1] == s[i + 1])) {
                                k = 1;
                                break;
 
                            }
                            else {
                                m = s[i] + s[i + 1];
                            }
                        }
                        else {
                            m = s[i];
                        }
 
                    }
                }
 
                else {
                    if (i < s.length() - 1) {
                        if (s[i + 1] < 'Z') {
                            k = 1;
                            break;
                            m = s[i]; if (s[i + 1] > 'Z') {
                                m = m + s[i + 1];
                            }
                        }
                    }
                    else {
                        k = 1;
                        break;
                    }
                }
 
            }
            else {
                m = s[i]; if (s[i + 1] > 'Z') {
                    m = m + s[i + 1];
                }
            }
        }
        if ((s[i] == '1') && (s[i - 1] > '9') && (s[i + 1] > '9')) { k = 1; }
        if ((s[i] == '0') && (s[i - 1] > '9')) { k = 1; }
    }
 
    if (k == 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    */
 
    return 0;
 
}