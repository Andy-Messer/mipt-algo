#include <iostream>
#include <vector>
const int f=10;
#define IOS std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
int main(){
    IOS;
    long long temp,p=1,sizeN;
    std::cin>>sizeN;
    std::vector<long long> arrayN(sizeN),arrayN_2(sizeN),indexN(f);

    for (int i=0;i<sizeN;i++){
        std::cin>>arrayN[i];
    }
    for (int i = 0; i < 20; ++i) {
        indexN.assign(f,0);
        long long m=1;
        arrayN_2.assign(sizeN,0);
        for (int j = 0; j < sizeN; ++j) {
            indexN[(arrayN[j]/p)%f]++;
        }
        for (int j = 0; j < f; ++j) {
            if (indexN[j]>0){
               temp=indexN[j],indexN[j]=m,m+=temp;
            }
        }
        long long r;
        for (int j = 0; j < sizeN; ++j) {
            r=(arrayN[j]/p)%f;
            if (indexN[r]>0){
                arrayN_2[indexN[r]-1]=arrayN[j],indexN[r]++;
            }
        }
        for (int j = 0; j < sizeN; ++j) {
            arrayN[j]=arrayN_2[j];
        }
        if (p>=1e18)break;
        p=p*f;
    }
    for (auto x:arrayN){
        std::cout<<x<<' ';
    }
}