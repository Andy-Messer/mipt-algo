/*!
 * \author Andrey Krotov
 * \file   solve_cubes.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>

//****************************************************************
/*! \fn template <typename T> std::vector<long long> Zfunction(T dataBegin, T dataEnd)
 * \brief Takes a container and returns an array with the result of the z-function
 * \param dataBegin first iterator - begin iterator of container
 * \param dataEnd second iterator - end iterator of container
 * \return it is the length of the maximum prefix of a substring starting at position x in string S, which is also a prefix for the entire string S.
 */
template <typename T>
std::vector<long long> Zfunction(T dataBegin, T dataEnd) {
    long long dataLength = distance(dataBegin,dataEnd);

    assert(dataLength >= 0 && "WRONG iterators");

    std::vector<long long> result(dataLength, 0);

    long long left = 0;
    long long right = 0;
    for (int i = 1; i < dataLength; ++i) {
        if (i <= right)
            result[i] = std::min(right - i + 1, result[i - left]);

        while ((i + result[i] < dataLength) &&
               (dataBegin[result[i]] == dataBegin[result[i] + i])) {
            ++result[i];
        }
        if (i + result[i] > right) {
            left = i;
            right = i + result[i] - 1;
        }
    }

    return result;
}
//****************************************************************

int main(){
    std::string s;
    std::cin >> s;
    std::vector<long long> ans = Zfunction(s.begin(), s.end());
    for (auto& a: ans) {
        std::cout << a <<' ';
    }
}