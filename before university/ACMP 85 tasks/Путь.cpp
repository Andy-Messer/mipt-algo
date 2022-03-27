#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int n,j,i,cor,k=0,pos,max ;
int a[1000][1000];//матрица
int q[100];//очередь
void BFS(int v,int v2) {//v-корень
    int ps=0; //позиция в очереди
    int pe=0;//позиция в элементах записи очереди
    int i;
    q[pe] = v;//в очередь добовляем корень
    vector<int>viz(n, -1);
 
    viz[v] = 0;//побывали в вершине
    queue<int> q;
    q.push(v);
    while (!q.empty())//   ps >= pe&&(q[ps]!=pos)) {//пока очередь не пуста 
    {
        int v = q.front(); //  pop();
        for (i = 0; i < n; i++) {//просматриваем вершины
            if ((a[v][i] != 0) && (viz[i] == -1)) {//проверяем есть ли ребро
                pe++;//переходим к следущему элементу в очереди
            //  q[pe] = i;//записываем, увиденную вершину
                q.push(i);
                viz[i] = viz[v]+1;//побывали в вершине
            }
         
        }
        ps++;//переходи к следущему элементу в очереди
        q.pop();
        //k = k + 1;
        //v = q[ps];//меняем корень
         
         
    }
    cout << viz[v2];
 
}
int main() {
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> cor >> pos;
    BFS(cor-1,pos-1);
     
    return 0;
}