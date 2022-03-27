#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int n, j, i, cor, k = 0, pos, max;int l=0;
int a[1000][1000];//матрица
int viz[1000000];
void BFS(int v) {//v-корень
    int ps = 0; //позиция в очереди
    int pe = 0;//позиция в элементах записи очереди
    int i;//в очередь добовляем корень
 
 
    viz[v] = 1;//побывали в вершине
    queue<int> q;
    q.push(v);
    while (!q.empty())//   ps >= pe&&(q[ps]!=pos)) {//пока очередь не пуста 
    {
        int v = q.front(); //  pop();
        for (i = 0; i < n; i++) {//просматриваем вершины
            if ((a[v][i] != 0) && (viz[i] == 0)) {//проверяем есть ли ребро
                pe++;//переходим к следущему элементу в очереди
                     //  q[pe] = i;//записываем, увиденную вершину
                q.push(i);
                viz[i] = viz[v] + 1;//побывали в вершине
            }
 
        }
        ps++;//переходи к следущему элементу в очереди
        q.pop();
        //k = k + 1;
        //v = q[ps];//меняем корень
 
 
    }
 
 
}
int main() {
    int x, y;
    for (i = 0; i < n; i++) {
        viz[i] = 0;
    }
 
    cin >> n >>k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    cin >> x;
    while (x!=0){ cin >> y;
        a[x-1][y-1] = 1;
             
            cin >> x;
             
        }
     
     
    BFS(k-1);
     
    for (i = 0; i < n; i++) {
        if (viz[i] != 0) {  l++; }
    }
    if (l == n) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
     
    return 0;
}