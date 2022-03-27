#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
 
vector <vector <pair<pair<int,int>,int>>>g;
int n,a,b;
int main(){
    cin >>n>>a>>b;a--;b--;
    int m;
    cin>>m;
    g.resize(n,vector <pair<pair<int,int>,int>>());
    for (int i=0;i<m;i++){
        int out,out_t,in,in_t;
        cin >>out>>out_t>>in>>in_t;out--;in--;
        g[out].push_back({{out_t,in_t},in});
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
            int ves_2=now_2.first.second;
            int to_2=now_2.second;
            if (ves<=now_2.first.first){
            if (ves_2<d[to_2]){
                s.erase({d[to_2],to_2});
                d[to_2]=ves_2;
                pred[to_2]=to;s.insert({d[to_2],to_2});}
            }
        }
    }
    vector <int>ans;
    if(d[b]!=INT_MAX){
        cout <<d[b];
    }else{
        cout<<-1;
    }
}