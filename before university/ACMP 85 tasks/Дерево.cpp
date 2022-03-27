#include <iostream>
#include <vector>
using namespace std;
vector <int> viz;
int n,k=0;
vector <vector <int>> a;
void dfs(int v) {
    for(int i=0;i<n;i++){
        if (a[v][i] == 1)
            if (viz[i] == -1) {
            viz[i] = v;
            dfs(i);
            }
        else {
             
            if (viz[v] != i) {
                k++; //cout << i<<" "<<v<<endl;
            }
        }
    }
    return;
}
int main() {
    cin >> n;
    a.resize(n, vector <int> (n,0));
    viz.resize(n,-1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (viz[i] == -1) {
            k++;
            viz[i] = i;
            dfs(i);
        }
    }
    if (k > 1)
        cout << "NO";
    else
        cout << "YES";
     
    return 0;
     
}