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
/*! \fn template <typename T> std::vector<long long> prefixFunction(T dataBegin, T dataEnd)
 * \brief Takes a container and returns an array with the result prefix of the function
 * \param dataBegin first iterator - begin iterator of container
 * \param dataEnd second iterator - end iterator of container
 * \return an array of the lengths of the largest borders (borders: ∀i = 1…k: α[i] = α[i + (n − k)]) for each position of this line
 */
template <typename T>
std::vector<long long> prefixFunction(T dataBegin, T dataEnd) {
    long long dataLength = distance(dataBegin,dataEnd);

    assert(dataLength >= 0 && "WRONG iterators");

    std::vector<long long> result(dataLength, 0);

    long long k = 0;
    
    for (long long i = 1; i < dataLength; ++i) {
        k = result[i - 1];
        
        while (k > 0 && (dataBegin[k]) != (dataBegin[i])) {
            k = result[k - 1];
        }
        
        if ((dataBegin[k]) == (dataBegin[i])) {
            ++k;
        }

        result[i] = k;
    }

    return result;
}
//****************************************************************

//****************************************************************
/*! \fn template <typename T> std::vector<long long> oddManaker(T dataBegin, T dataEnd)
 * \brief Takes a container and returns an array with the result Manaker algorithm for odd length
 * \param dataBegin first iterator - begin iterator of container
 * \param dataEnd second iterator - end iterator of container
 * \return an array with the number of palindromes of odd length centered at position i
 */
template <typename T>
std::vector<long long> oddManaker(T dataBegin, T dataEnd) {
    long long left  =  0;
    long long right = -1;
    long long k     =  0;
    long long dataLength = distance(dataBegin, dataEnd);
    
    std::vector<long long> result(dataLength);
    
    for (long long i = 0; i < dataLength; ++i) {
        k = 0;
        
        if (i <= right) k = std::min(right - i + 1, result[right - i + left]);

        while((i + k < dataLength) && (i - k >= 0) &&
              (dataBegin[i + k] == dataBegin[i - k])) k++;
    
        result[i] = k;
        
        if (i + k - 1 > right) {
            left  = i - k + 1;
            right = i + k - 1;
        }
    }
    return result;
}
//****************************************************************

//****************************************************************
/*! \fn template <typename T> std::vector<long long> evenManaker(T dataBegin, T dataEnd)
 * \brief Takes a container and returns an array with the result Manaker algorithm for even length
 * \param dataBegin first iterator - begin iterator of container
 * \param dataEnd second iterator - end iterator of container
 * \return an array with the number of palindromes of even length
 */
template <typename T>
std::vector<long long> evenManaker(T dataBegin, T dataEnd) {
    long long left  =  0;
    long long right = -1;
    long long k     =  0;
    long long dataLength = distance(dataBegin, dataEnd);
    
    std::vector<long long> result(dataLength);
    
    for (long long i = 0; i < dataLength; ++i) {
        k = 0;
        
        if (i <= right)
            k = std::min(right - i + 1, result[right - i + left + 1]);

        while((i + k < dataLength) && (i - k - 1 >= 0) &&
              (dataBegin[i + k] == dataBegin[i - k - 1])) k++;
    
        result[i] = k;
        
        if (i + k - 1 > right) {
            left  = i - k;
            right = i + k - 1;
        }
    }
    return result;
}
//****************************************************************


int main() {
    long long countOfCubes  = 0;
    long long countOfColors = 0;

    std::cin >> countOfCubes >> countOfColors;

    std::vector<long long> colorsOfCubes(countOfCubes, 0);

    for (long long i = 0; i < countOfCubes; ++i) {
        std::cin >> colorsOfCubes[i];
    }
    
    std::set<long long> result;
    
    std::vector<long long> resultManakerEven = evenManaker(colorsOfCubes.begin(), colorsOfCubes.end());
    
    result.insert(countOfCubes);
    
    // for (auto& a: resultManakerEven) {
    //     std::cout << a << ' ';
    // }
    // std::cout << std::endl;

    for (long long i = 0; i <= countOfCubes / 2; ++i) {
        if (resultManakerEven[i] != 0) {
            if (std::min( i , countOfCubes - i) == resultManakerEven[i])
                result.insert(std::max(i , countOfCubes - i));
        }
    }

    for (auto& a: result) {
        std::cout << a << ' ';
    }
}