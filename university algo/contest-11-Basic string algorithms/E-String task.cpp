#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
const int ALPH_SIZE = 26;
const int ROOT = 0;

class Trie{
public:

    struct Node {
        std::vector<int> to;
        bool term = false;
        int link;
        std::vector<int> index;
        int len;
        int term_link;
        Node(): to(ALPH_SIZE, -1), term(false), link(-1), term_link(-1), len(0) {};
    };
    
    Trie(): data{Node()} {}

    bool IsContain(const std::vector<int>& to, const char& letter) const {
        return to[letter - 'a'] != 0;
    }

    const std::vector<int>& GetWays(const int& v) const {
        return data[v].to;
    }

    const int& GetWay(const int& v, const char& letter) const {
        return data[v].to[letter - 'a'];
    }

    const int& SetWay(const int& v, const char& letter, const int& u) {
        return data[v].to[letter - 'a'] = u;
    }

    const int& GetLink(const int& v) const {
        return data[v].link;
    }

    const int& GetTermLink(const int& v) const {
        return data[v].term_link;
    }

    bool IsTerm(const int& v) const {
        return data[v].term == true;
    }

    const int& GetLength(const int& v) const {
        return data[v].len;
    }

    const std::vector<int>& GetIndex(const int& v) const {
        return data[v].index;
    }

    void add(const std::string& word, int num) {
        int v = 0;
        for (int i = 0; i < word.length(); ++i) {  
            if (GetWay(v, word[i]) == -1) {
                data.push_back(Node());
                data[v].to[word[i] - 'a'] = (int)(data.size()) - 1;
            }
            v = GetWay(v, word[i]);
        }
        data[v].len = word.length();
        data[v].index.push_back(num);
        data[v].term = true;
        ++sz;
    }

    void Aho_Corasik() {
        data[0].link = 0;
        for (int i = 0; i < ALPH_SIZE; ++i) {
            if (data[0].to[i] != static_cast<int>(-1)) continue;
            data[0].to[i] = 0;
        }
        std::queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < ALPH_SIZE; ++i) {
                int u = GetWay(v, i + 'a');
                if (data[u].link != static_cast<int>(-1)) continue;
                data[u].link = (v == 0 ? 0 : data[GetLink(v)].to[i]);

                const Node& sLnode = data[data[u].link];
                if (sLnode.term)
                    data[u].term_link = GetLink(u);
                else
                    data[u].term_link = sLnode.term_link;
        
                for (int j = 0; j < ALPH_SIZE; ++j) {
                    if (data[u].to[j] != static_cast<int>(-1)) continue;
                    data[u].to[j] = GetWay(GetLink(u), j + 'a');
                }
                q.push(u);
            }
        }
    }

    void Analyze(const std::string& text){
        int v = 0;
        int p = 0;
        for (int i = 0; i < text.size(); ++i) {
            v = GetWay(v, text[i]);
            if (IsTerm(v)) {
                for (auto& u : GetIndex(v)) {
                    ans[u].insert(i - GetLength(v));
                }
            }
            p = GetTermLink(v);
            while(p != -1) {
                for (auto& u : GetIndex(p)) {
                    ans[u].insert(i - GetLength(p));
                }
                p = GetTermLink(p);
            }
        }
    }

    void ShowOccurrences(const std::string& text) {
        Analyze(text);
        for (int i = 0; i < sz; ++i){
            std::cout << ans[i].size() << ' ';
            for (auto& index: ans[i]) {
                std::cout << 2 + index << ' ';
            }
            std::cout << std::endl;
        }
    }
private:    
    std::map<int, std::set<int>> ans;
    std::vector<Node> data;
    int sz = 0;
};

int main(){
    std::string text;
    std::string word;
    std::cin >> text;
 
    int n = 0;
    std::cin >> n;
 
    Trie trie;
    for(int i = 0; i < n; ++i){
        std::cin >> word;
        trie.add(word, i);
    }
    trie.Aho_Corasik();
    trie.ShowOccurrences(text);
    return 0;
}