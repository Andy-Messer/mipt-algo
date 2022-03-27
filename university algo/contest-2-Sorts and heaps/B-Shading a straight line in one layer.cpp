#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ss second
#define ff first
const int INF = 1e9;

int main() {
    
    int num_of_br;
    std::vector<std::pair<std::pair<int, int>, std::string>> queue_brackets;
    int curr = 0;
    int right, left;
    
    std::cin >> num_of_br;
    
    
    for (int i = 0; i < num_of_br; i++) {
        
        std::cin >> left >> right;
        
        curr++;
        queue_brackets.push_back({{left, curr}, "open"});
        queue_brackets.push_back({{right, curr}, "close"});
    
    }
    
    std::sort(queue_brackets.begin(), queue_brackets.end());
    
    queue_brackets.push_back({{INF, INF}, "edge"});
    
    int index = 0;
    int status = 0;
    std::vector<std::pair<int, int>> open_bracket;
    std::vector<bool> used(20000, 0);
    int ans = 0;/*a {{позиция на прямой, позиция в массиве}тип скобки}*/
    
    while (index < 2 * num_of_br) {/*open_bracket {номер в оригинальном массиве, позиция на прямой}*/
        
        if (queue_brackets[index].ss == "open") {
        
            if (status == 1) {
        
                if (!used[open_bracket.back().ff]/*чекаем номер пришедшей скобки в прошлый раз*/) {
        
                    int delta = abs(open_bracket.back().ss - queue_brackets[index].ff.ff);
                    ans += delta;
                    open_bracket.back().ss = queue_brackets[index].ff.ff;
        
                }
        
            }
        
            open_bracket.push_back({queue_brackets[index].ff.ss, queue_brackets[index].ff.ff});
            status++;
        
        }
      
        if (queue_brackets[index].ss == "close") {
      
            if (status == 1) {
      
                int delta = abs(open_bracket.back().ss - queue_brackets[index].ff.ff);
                ans += delta;
                open_bracket.back().ss = queue_brackets[index].ff.ff;
      
            }
      
            open_bracket.back().ss = queue_brackets[index].ff.ff;
            used[queue_brackets[index].ff.ss] = 1;
            status--;
      
        }
      
        index++;
    
    }
   
    std::cout << ans;
}