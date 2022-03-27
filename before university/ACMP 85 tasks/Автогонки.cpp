#include <iostream>
using namespace std;
int n, m; int i, a[1000][1000], j;
bool vis[1000], k = false;
void dfs(int v,int pr) {
    vis[v] = true;
    for (i = 0; i < n; i++) {
 
        if (!vis[i]  && a[i][v] != 0) {
 
            dfs(i,v);
        }
        else {
                if (a[i][v] != 0) {
                    if (vis[i]==true&&pr!=i) {
                    k = true;
                }
            }
        }
 
    }
}
 
int main() {
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        vis[i] = false;
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    for (int p = 0; p < m; p++) {
        cin >> i >> j;
        a[i-1][j-1] = 1;
        a[j-1][i-1] = 1;
    }
    for (i = 0; i < n; i++) {
        if (vis[i] == false) {
 
            dfs(i,0);
        }
    }
    if (k == true) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
     
}