#include <iostream>
#include <vector>
#include <iterator>

void speedUp() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

//------------Const-----------------------//
const unsigned long long TableSize = 8388608;
const unsigned long long alpha     = 5431;
const unsigned long long beta      = 9619;
const unsigned long long Prime     = 999979000 + 7;

//------------NAMESPACE-------------------//
using std::vector;
using std::pair;
using std::cin;
using std::cout;

//----------------LIST--------------------//
template<class T_elem>
struct Node {
    Node  *nextNode;
    T_elem value;

    Node() : nextNode(nullptr) {};

    ~Node() = default;
};

template<typename T_elem>
class List {
private:
    Node<T_elem> *rootNode;
    Node<T_elem> *lastNode;
    size_t        size;

public:
    List() : rootNode(nullptr),
             lastNode(nullptr),
             size(0) {};

    void push_back(T_elem value) {
        if (size == 0) {
            rootNode           = new Node<T_elem>();
            lastNode           = rootNode;
            rootNode->value    = value;
            size++;
        } else {
            auto *newNode      = new Node<T_elem>();
            newNode->value     = value;
            lastNode->nextNode = newNode;
            lastNode           = newNode;
        }
    };

    bool empty(){
        return size == 0;
    }

    bool Search(T_elem value) {
        Node<T_elem> *it = rootNode;
        while (it != nullptr && it->value != value) {
            it = rootNode->nextNode;
        }
        if (it == nullptr) return false;
        return true;
    }

    ~List() {
        Node<T_elem> *it = rootNode;
        Node<T_elem> *copy_it_next;
        if (it != nullptr)
            copy_it_next = it->nextNode;
        while (it != nullptr) {
            delete it;
            size--;
            it = copy_it_next;
            if (it != nullptr)
                copy_it_next = it->nextNode;
        }
    };
};

//----------------------------------------//

//-----------------HashTable--------------//
template<typename T_elem>
class Hashtable {
private:
    vector<List<T_elem>> storage_HT;
    long long            count;

    unsigned long long Generate_Key(unsigned long long key) {

        unsigned long long hash = ((alpha * key + beta) % Prime) % TableSize;

        return hash;
    }

public:
    Hashtable() : storage_HT(TableSize), count(0) {};

    void Insert(long long x, long long y, long long &W, long long &H) {

        unsigned long long pos = (y - 1) * W + x;
        unsigned long long big_hash = Generate_Key(pos);

        if (storage_HT[big_hash].empty()){
            storage_HT[big_hash].push_back(pos);
            count++;
        }else
            if (!storage_HT[big_hash].Search(pos)) {
                storage_HT[big_hash].push_back(pos);
                count++;
            }

    }

    std::string Check(const long long &W, const long long &H) {
        return W * H == count ? "Yes" : "No";
    }

    ~Hashtable() = default;
};

//----------------------------------------//

void solve(){

    speedUp();

    vector<pair<long long, long long>> posUPD = {{0,  0},
                                                 {0,  1},
                                                 {1,  0},
                                                 {-1, 0},
                                                 {0,  -1}};
    long long W;
    long long H;
    long long N;
    long long x;
    long long y;
    Hashtable<unsigned long long> hashtable;


    std::cin >> W >> H
             >> N;

    bool flag=0;
    if (W * H > 5 * N)
        flag=1;

    for (int i = 0; i < N; i++) {
        std::cin >> x >> y;
        if (!flag)
            for (auto j:posUPD) {
                if (x + j.first > 0 && y + j.second > 0 && x + j.first <= W && y + j.second <= H)
                    hashtable.Insert(x + j.first, y + j.second, W, H);
            }
    }


    if (W * H > 5 * N) {
        std::cout << "No";
    } else {
        std::cout << hashtable.Check(W, H);
    }

}
//----------------------------------------//

int main() {
    solve();
    return 0;
}

