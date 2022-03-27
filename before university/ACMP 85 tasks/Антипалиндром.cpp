#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string s,a="NO SOLUTION";
    cin >>s;
    long long max=0;
   bool f_1=false,f_2=false,r=false;
    for (long long i =0;i<s.size();i++){
    if (s.substr(i,1)!=s.substr(s.size()-i-1,1)){
        r=true;
    }
    }
    if (!r){
    for (long long i =0;i<s.size();i++){
        if (!f_1)
       if (s.substr(0,1)!=s.substr(s.size()-i-1,1)){
           if (s.substr(0,s.size()-i).size()>max){
               max=s.substr(0,s.size()-i).size();
               a=s.substr(0,s.size()-i);
               f_1=true;
           }
       } 
       if(!f_2)
       if (s.substr(s.size()-1,1)!=s.substr(i,1)){
           if (s.substr(i,s.size()-i+1).size()>max){
               max=s.substr(i,s.size()-i+1).size();
               a=s.substr(i,s.size()-i+1);
               f_2=true;
           }
       } 
       if (f_1==true&&f_2==true){break;}}if (a.size()>1){
    cout <<a;}else{
        cout<<"NO SOLUTION";
    }
    
    }else{
        cout<<s;
    }
      
    return 0;
}