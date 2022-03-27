#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int n, j, i, cor, k = 0, pos,y, max; int l = 0; int SV = 0;int m;
int a[1000][1000];//матрица
int viz[1000000];
void BFS(int v,int v2) {
 
     
 
 
    a[v][v2] = 2;
    queue<pair<int,int>> q;
    q.push({ v,v2 });
    while (!q.empty())
    {
        v= q.front().first;
        v2 = q.front().second;
        if ((v - 1 >= 0) && (a[v - 1][v2] == 0)) {
            a[v - 1][v2] = 2;
            q.push({ v - 1,v2 });
        }
        if ((v + 1 <n ) && (a[v + 1][v2] == 0)) {
            a[v + 1][v2] = 2;
            q.push({ v +1,v2 });
        }
        if ((v2+1 <m) && (a[v][v2+1] == 0)) {
            a[v][v2+1] = 2;
            q.push({ v ,v2 +1});
        }
        if ((v2 - 1 >= 0) && (a[v][v2-1] == 0)) {
            a[v][v2-1] = 2;
            q.push({ v ,v2 -1});
        }
         
         
        q.pop();
         
         
    }
 
 
}
 char x;
int main() {
    cin >>n >> m;
     
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> x;
            if (x == '.') {
                a[i][j] = 1;
            }
            if (x == '#') {
                a[i][j] = 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] ==0){
                BFS(i, j); SV++;
        }
        }
    }
    cout << SV;
     
    return 0;
}