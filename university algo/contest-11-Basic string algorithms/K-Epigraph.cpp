#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cassert> 

//****************************************************************
/*! \fn template <typename T> std::vector<long long> Zfunction(T dataBegin, T dataEnd)
 * \brief Takes a container and returns an array with the result of the z-function
 * \param dataBegin first iterator - begin iterator of container
 * \param dataEnd second iterator - end iterator of container
 * \return it is the length of the maximum prefix of a substring starting at position x in string S, which is also a prefix for the entire string S.
 */
template <typename T>
long long Zfunction(T dataBegin, T dataEnd) {
    long long dataLength = distance(dataBegin,dataEnd);
 
    assert(dataLength >= 0 && "WRONG iterators");
 
    std::vector<long long> result(dataLength, 0);
    long long maXzFunc = 0;
    long long left = 0;
    long long right = 0;
    for (int i = 1; i < dataLength; ++i) {
        if (i <= right)
            result[i] = std::min(right - i + 1, result[i - left]);

        while ((i + result[i] < dataLength) &&
               (dataBegin[result[i]] == dataBegin[result[i] + i])) {
            ++result[i];
        }
        maXzFunc = std::max(maXzFunc, result[i]);
        if (i + result[i] > right) {
            left = i;
            right = i + result[i] - 1;
        }
    }
 
    return maXzFunc;
}
//****************************************************************
 

int main(){
    std::string s;
    std::cin >> s;
    long long ans = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        std::reverse(s.begin(), s.end() - s.length() + 1 + i);
        // for (auto j = s.begin();j!=s.end() - s.length() + 1 + i; ++j){
        //     std::cout<<*j << ' ';
        // }
        // std::cout<<'\n';
        long long len = i + 1;
        // std::cout <<"len: "<<len<<'\n';
        long long rZ =  Zfunction(s.begin(),s.end() - s.length() + 1 + i);
        // std::cout<<"rZ: "<<rZ<<'\n';
        long long ans_l = (len*(len+1))/2 - (rZ*(rZ+1))/2;
        // std::cout << "ans_l: " << ans_l << '\n';
        ans += ans_l;
        // std::cout << "ans: " << ans << '\n';
        // std::cout << '\n';
        std::reverse(s.begin(), s.end() - s.length() + 1 + i);
    }
    std::cout << ans;
}