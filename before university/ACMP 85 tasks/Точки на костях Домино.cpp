#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
const long long INF = 1000000000;
vector<long long> a;
vector <long long>dp;
long long fact(long long a) {
    long long l=1;
    for (long long i = 1; i <= a; i++) {
        l = l * i;
    }
    return l;
}
int main() {
    long long n,k=2;
    cin >>n;
    cout <<n*(n+1)*(n+2)/2;
}