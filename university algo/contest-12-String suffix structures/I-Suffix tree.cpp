#include <iostream>
#include <string>
#include <vector>


using namespace std;

const int ALPHABET = 28;

struct Node {
    Node() {
        children.resize(ALPHABET, -1);
        suffix_link = -1;
    }
    int vertex;
    int left, right;
    int mama;
    int suffix_link;
    vector<int> children;
    int new_index;
};

struct Position {
    int vertex;
    int up;
};

class Ukkonen {
public:
    Ukkonen(string pattern, int size, int size1, int size2) : pattern(pattern), size(size), size1(size1), size2(size2) {}
    void solve();		// for cout

private:
    void dfs(int vertex, vector<int >& new_order);
    int getSuffixLink(int vertex);
    Position extendTree(Position postion, int index);
    Position findWay(char current_symbol, const Position& vertex);
    void buildSuffixTree();
    int hasWay(const Node& vertex, char symbol);
    int getCode(char symbol);
    int addChild(int vertex, int left, int right);
    int split(const Position& position);
    Position jump(int vertex, int left, int right);
    string pattern;	// s + t
    int size;
    int size1;
    int size2;
    vector<Node> suffix_tree;
};

int Ukkonen::getCode(char symbol) {
    if (symbol == '#') {
        return 0;
    }
    else if (symbol == '$') {
        return 1;
    }
    else {
        return symbol - 'a' + 2;
    }
}

int Ukkonen::hasWay(const Node& vertex, char symbol) {
    int index = getCode(symbol);
    if (vertex.children[index] != -1) {
        return vertex.children[index];
    }
    else {
        return -1;
    }
}

Position Ukkonen::findWay(char current_symbol, const Position& position) {
    int vertex = position.vertex;
    int up = position.up;
    if (up != 0) {
        int number = suffix_tree[vertex].right - up;
        if (pattern[number] == current_symbol) {
            Position p;
            p.up = up - 1;
            p.vertex = vertex;
            return p;
        }
        Position no;
        no.up = -1;
        no.vertex = -1;
        return no;
    }
    else {
        int to = hasWay(suffix_tree[vertex], current_symbol);
        if (to != -1) {
            Position p;
            p.vertex = to;
            p.up = suffix_tree[to].right - suffix_tree[to].left - 1;
            return p;
        }
        else {
            Position no;
            no.up = -1;
            no.vertex = -1;
            return no;
        }
    }
}

int Ukkonen::addChild(int vertex, int left, int right) {
    Node new_child;
    new_child.left = left;
    new_child.right = right;
    new_child.mama = vertex;
    new_child.vertex = suffix_tree.size();
    suffix_tree.push_back(new_child);
    int index = getCode(pattern[left]);
    suffix_tree[vertex].children[index] = new_child.vertex;
    return new_child.vertex;
}

int Ukkonen::split(const Position& position) {
    int vertex = position.vertex;
    int up = position.up;
    int down = suffix_tree[vertex].right - suffix_tree[vertex].left - up;
    if (up == 0) {
        return vertex;
    }
    if (down == 0) {
        return suffix_tree[vertex].mama;
    }
    int pos = addChild(suffix_tree[vertex].mama, suffix_tree[vertex].left, suffix_tree[vertex].right - up);
    suffix_tree[vertex].left += down;
    suffix_tree[vertex].mama = pos;
    int index = getCode(pattern[suffix_tree[vertex].left]);
    suffix_tree[pos].children[index] = vertex;
    return std::move(pos);

}

Position Ukkonen::jump(int vertex, int left, int right) {
    Position p;
    while (true) {
        if (left == right) {
            p.vertex = vertex;
            p.up = 0;
            return p;
        }
        int index = getCode(pattern[left]);
        int to = suffix_tree[vertex].children[index];
        if (suffix_tree[to].right - suffix_tree[to].left >= right - left) {
            p.vertex = to;
            p.up = suffix_tree[to].right - suffix_tree[to].left - right + left;
            return p;
        }
        vertex = to;
        left += suffix_tree[to].right - suffix_tree[to].left;
    }
}

int Ukkonen::getSuffixLink(int vertex) {
    if (suffix_tree[vertex].suffix_link == -1) {
        int mama = suffix_tree[vertex].mama;
        Position p;
        int left1 = 0;
        if (mama == 0) {
            left1 = suffix_tree[vertex].left + 1;
        }
        else {
            left1 = suffix_tree[vertex].left;
        }
        int right1 = suffix_tree[vertex].right;
        p = jump(getSuffixLink(mama), left1, right1);
        int it = split(p);
        suffix_tree[vertex].suffix_link = it;// std::move(split(p));
    }
    return suffix_tree[vertex].suffix_link;
}

Position Ukkonen::extendTree(Position position, int index) {
    while (true) {
        Position p = findWay(pattern[index], position);
        if (p.vertex != -1) {
            return p;
        }
        int vertex = split(position);
        addChild(vertex, index, size);
        position.vertex = getSuffixLink(vertex);
        position.up = 0;
        if (vertex == 0) {
            return position;
        }
    }
}

void Ukkonen::buildSuffixTree() {
    Node root;
    Position position;
    root.suffix_link = 0;
    root.mama = 0;
    root.left = 0;
    root.right = 0;
    root.vertex = 0;
    position.up = 0;
    position.vertex = 0;
    suffix_tree.push_back(root);
    for (int i = 0; i < size; i++) {
        position = extendTree(position, i);
    }
}

void Ukkonen::dfs(int vertex, vector<int>& new_order) {
    new_order.push_back(vertex);
    suffix_tree[vertex].new_index = new_order.size() - 1;
    for (int i = 0; i < ALPHABET; i++) {
        if (suffix_tree[vertex].children[i] != -1) {
            dfs(suffix_tree[vertex].children[i], new_order);
        }
    }

}

void Ukkonen::solve() {
    buildSuffixTree();
    vector<int> new_order;
    dfs(0, new_order);
    int p, w, lf, rg;
    printf("%d\n", new_order.size());
    for (int i = 1; i < new_order.size(); i++) {
        int mama = suffix_tree[new_order[i]].mama;
        p = suffix_tree[mama].new_index;
        if (suffix_tree[new_order[i]].right <= size1) {
            w = 0;
            lf = suffix_tree[new_order[i]].left;
            rg = suffix_tree[new_order[i]].right;
        }
        else if (suffix_tree[new_order[i]].left >= size1) {
            w = 1;
            lf = suffix_tree[new_order[i]].left - size1;
            rg = suffix_tree[new_order[i]].right - size1;
        }
        else {
            w = 0;
            lf = suffix_tree[new_order[i]].left;
            rg = size1;
        }
        printf("%d %d %d\n", p, lf, rg);
    }
}

int main() {
    string s, t;
    cin >> s;
    t="";
    int size1 = s.size();
    int size2 = t.size();
    string pattern = s + t;
    int size = pattern.size();
    Ukkonen u(pattern, size, size1, size2);
    u.solve();
    return 0;
}