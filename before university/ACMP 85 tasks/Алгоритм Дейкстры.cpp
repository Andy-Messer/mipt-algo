#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
 
vector <vector <pair<int,int>>>g;
int n,a,b;
int main(){
    cin >>n>>a>>b;a--;b--;
    g.resize(n,vector <pair<int,int>>());
    for (int out=0;out<n;out++){
        for (int to=0;to<n;to++){
            int ves;
            cin >>ves;
            if (ves!=-1&&to!=out){
                g[out].push_back({ves,to});
            }
        }
    }
    set <pair<int,int>>s;
    vector <int>d(n,INT_MAX);
    vector <int>pred(n,-1);
    d[a]=0;
    s.insert({0,a});
    while (!s.empty()){
        pair <int,int> now=*s.begin();
        int to=now.second;int ves=d[to];
        s.erase(s.begin());
        for (auto now_2:g[to]){
            int ves_2=now_2.first;
            int to_2=now_2.second;
            if (ves+ves_2<d[to_2]){
                s.erase({d[to_2],to_2});
                d[to_2]=ves+ves_2;
                pred[to_2]=to;
                s.insert({d[to_2],to_2});}
        }
    }
    vector <int>ans;
    if(d[b]!=INT_MAX){
        cout <<d[b];
    }else{
        cout<<-1;
    }
}