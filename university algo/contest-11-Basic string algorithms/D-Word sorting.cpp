#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <queue>

class Trie{
public:
    void add(char* str, size_t sz) {
        int v = 0;
        for (size_t i = 0; i < sz; ++i) {
            
            if (data[v].to[str[i] - 'a'] == 0){
                data.push_back(Node());
                data[v].to[str[i] - 'a'] = int(data.size()) - 1;
                data[v].sz = i;
                data[v].str = str;
            }

            v = data[v].to[str[i] - 'a'];
        }

        data[v].sz = sz;
        data[v].str = str;
        ++data[v].count;
        data[v].term = true;
    }

    std::vector<std::pair<size_t, char*>> ReadSortedDictFrom(int v) {
        std::vector<std::pair<size_t, char*>> readQ;
        used.assign(data.size(), 0);
        dfs(v, readQ);
        return readQ;
    }
    
    Trie(): data{Node()} {}
    Trie(const size_t& sz): used(sz, 0), data{Node()} {}
private:    
    struct Node {
        std::vector<int> to;
        bool term = false;   
        int count = 0; 
        int sz = 0;
        char* str = nullptr;
        Node(): to(26, 0){};
    };

    void dfs(int v, std::vector<std::pair<size_t, char*>>& readQ) {
        used[v] = 1;
        if (data[v].term)
            for (int i = 0; i < data[v].count; ++i)
                readQ.push_back({data[v].sz, data[v].str});
        
        for (int i = 0; i < 26; ++i)
            if (!used[data[v].to[i]]&& data[v].to[i] != 0)
                dfs(data[v].to[i], readQ);
    }

    std::vector<bool>        used;
    std::vector<Node>        data;
};

void printDots(const size_t& countOfDots){

    for(size_t j = 0; j < countOfDots; j++){
        std::cout << '.';
    }
}


int main() {
    
    char* s = (char*)calloc(1e6 + 1, sizeof(char));
    
    int lenTemp = 0;
    scanf("%s%n", s, &lenTemp);
    size_t len = (size_t)lenTemp;
    Trie trie;
    std::vector<int> dotsCount;
    size_t dCount = 0;
    size_t cCount = 0;
    
    for (size_t index = 0; index < len; ++index) {
        if (s[index] == '.') {
            
            if (cCount > 0) {
                trie.add((char*)(s + index - cCount), cCount);
                cCount = 0;
            }
            
            ++dCount;
            continue;
        } 
        
        if (dCount > 0) {
            dotsCount.push_back(dCount);
            dCount = 0;
        }

        ++cCount;
    }
    
    if (s[len - 1] == '.') 
        dotsCount.push_back(dCount);
    else {
        trie.add(s + len - cCount, cCount);
    }

    std::vector<std::pair<size_t, char*>> ans = trie.ReadSortedDictFrom(0);

    
    size_t y = ans.size() + dotsCount.size();
    for (size_t i = 0; i < y; ++i){
        if (s[0] == '.') {
            if (i%2 == 0){
                printDots(dotsCount[i / 2]);
            } else {
                for (size_t j = 0; j < ans[i / 2].first; ++j)
                    std::cout << *(ans[i / 2].second + j);
            }
        }else{
            if (i%2 == 1){
                printDots(dotsCount[i / 2]);
            } else {
                for (size_t j = 0; j < ans[i / 2].first; ++j)
                    std::cout << *(ans[i / 2].second + j);
            }
        }
    }
    free(s);
}