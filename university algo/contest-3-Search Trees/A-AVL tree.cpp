#include <iostream>
#include <vector>
#include <cmath>

typedef long long KeyType;
const std::vector<std::string> OPERATIONS =
        {
                "insert", "delete", "exists", "next", "prev"
        };

class KeyedItem {
private:
    KeyType _SearchKey;
    KeyedItem *_parent, *_rightChild, *_leftChild;
    //веса правого и левого дерева
public:
    int leftsize, rightsize;

    KeyedItem() : _SearchKey(0), _parent(nullptr), _rightChild(nullptr), _leftChild(nullptr),
                  rightsize(0),
                  leftsize(0) {};

    //Ключ рассматриваемой вершины
    void SetKey(KeyType n_value) {
        _SearchKey = n_value;
    }

    [[nodiscard]] KeyType GetKey() const {
        return _SearchKey;
    }

    //родитель вершины
    void SetParent(KeyedItem *n_value) {
        _parent = n_value;
    }

    [[nodiscard]] KeyedItem *GetParent() const {
        return _parent;
    }

    //правый ребёнок
    void SetRightChild(KeyedItem *n_value) {
        _rightChild = n_value;
    }

    [[nodiscard]] KeyedItem *GetRightChild() const {
        return _rightChild;
    }

    //левый ребёнок
    void SetLeftChild(KeyedItem *n_value) {
        _leftChild = n_value;
    }

    [[nodiscard]] KeyedItem *GetLeftChild() const {
        return _leftChild;
    }

};

typedef KeyedItem NodeTree;

class Tree {
public:
    Tree();

    //если в бинарном дереве нет элементов возвращает 1 иначе 0
    [[nodiscard]] virtual bool IsEmpty() const;

    /*рекурсивно ищет элемент и возвращает true  or false в зависимости от того,
     * есть ли этот элемент в куче*/
    virtual void Search(KeyType &SearchingItem, NodeTree *x);

    virtual bool SearchBool(KeyType &SearchingItem, NodeTree *x);

    virtual NodeTree *Minimum(NodeTree *x);//ищет минимальный элемент в поддереве
    virtual NodeTree *Maximum(NodeTree *x);//ищет максимальный элемент в поддереве
    virtual KeyType NextSearch(KeyType &SearchingItem, NodeTree *x);//ищет следующий элемент за х-ом
    virtual KeyType PrevSearch(KeyType &SearchingItem, NodeTree *x);//ищет предыдущий элемент за х-ом
    /*меняет корень и перепривязывает поддерево*/
    virtual NodeTree* RotateLeft(NodeTree *a);//малый левый поворот дерева
    /*меняет корень и перепривязывает поддерево*/
    virtual NodeTree* RotateRight(NodeTree *a);//малый правый поворот дерева
    //выравнивание дерева
    virtual NodeTree *DoAlignment(NodeTree *balancesNode);

    NodeTree *Insert(NodeTree *newItem, NodeTree *tempRoot);

    NodeTree *Delete(long long &removableItem, NodeTree *tempRoot);

    NodeTree *nodeRoot;//указатель на корень

};
Tree::Tree() : nodeRoot(nullptr) {}
bool Tree::IsEmpty() const {
    if (nodeRoot == nullptr)
        return true;
    return false;
}
void Tree::Search(KeyType &SearchingItem, NodeTree *x) {
    if (nodeRoot == nullptr) {
        std::cout << "false" << std::endl;
    } else {
        if (x->GetKey() == SearchingItem) {
            std::cout << "true" << std::endl;
            return;
        } else {
            if (SearchingItem < x->GetKey()) {
                if (x->GetLeftChild() != nullptr)
                    Search(SearchingItem, x->GetLeftChild());
                else {
                    std::cout << "false" << std::endl;
                    return;
                }
            } else {
                if (x->GetRightChild() != nullptr)
                    Search(SearchingItem, x->GetRightChild());
                else {
                    std::cout << "false" << std::endl;
                    return;
                }
            }
        }
        if (x->GetLeftChild() == nullptr && x->GetRightChild() == nullptr) {
            std::cout << "false" << std::endl;
            return;
        }
        return;
    }
}
bool Tree::SearchBool(KeyType &SearchingItem, NodeTree *x) {
    if (nodeRoot == nullptr) {
        return 0;
    } else {
        if (x->GetKey() == SearchingItem) {
            return 1;
        } else {
            if (SearchingItem < x->GetKey()) {
                if (x->GetLeftChild() != nullptr)
                    return SearchBool(SearchingItem, x->GetLeftChild());
                else {
                    return 0;
                }
            } else {
                if (x->GetRightChild() != nullptr)
                    return SearchBool(SearchingItem, x->GetRightChild());
                else {
                    return 0;
                }
            }
        }
    }
}
NodeTree *Tree::Minimum(NodeTree *x) {
    if (x->GetLeftChild() == nullptr) {
        return x;
    }
    return Minimum(x->GetLeftChild());
}
NodeTree *Tree::Maximum(NodeTree *x) {
    if (x->GetRightChild() == nullptr) {
        return x;
    }
    return Maximum(x->GetRightChild());
}
KeyType Tree::PrevSearch(KeyType &SearchingItem, NodeTree *x) {
    if (SearchingItem <= x->GetKey()) {
        if (x->GetLeftChild() != nullptr)
            return PrevSearch(SearchingItem, x->GetLeftChild());
        else
            return (long long) (-1e9);
    } else {
        if (x->GetRightChild() != nullptr)
            return (long long) (std::max(PrevSearch(SearchingItem, x->GetRightChild()), x->GetKey()));
        else
            return x->GetKey();
    }
}
KeyType Tree::NextSearch(KeyType &SearchingItem, NodeTree *x) {
    if (SearchingItem >= x->GetKey()) {
        if (x->GetRightChild() != nullptr)
            return NextSearch(SearchingItem, x->GetRightChild());
        else
            return (long long) (1e9);
    } else {
        if (x->GetLeftChild() != nullptr)
            return (long long) (std::min(NextSearch(SearchingItem, x->GetLeftChild()), x->GetKey()));
        else
            return x->GetKey();
    }
}
NodeTree *Tree::DoAlignment(NodeTree *balancesNode) {
    if (balancesNode != nullptr) {
        long long c,d;
        if (balancesNode->rightsize==0)
            c=0;
        else
            c=ceil(log(balancesNode->rightsize+1)/log(2));
        if (balancesNode->leftsize==0)
            d=0;
        else
            d=ceil(log(balancesNode->leftsize+1)/log(2));
        long long a = c - d;
        long long bLeft, bRight;
        if (a == 2) //big left rotate
        {
            long long c2,d2;
            if (balancesNode->GetRightChild()->rightsize==0)
                c2=0;
            else
                c2=ceil(log(balancesNode->GetRightChild()->rightsize+1)/log(2));
            if (log(balancesNode->GetRightChild()->leftsize)==0)
                d2=0;
            else
                d2=ceil(log(balancesNode->GetRightChild()->leftsize+1)/log(2));
            long long a2 = c2 - d2;
            if ( a2 < 0)
                balancesNode->SetRightChild(RotateRight(balancesNode->GetRightChild()));
            balancesNode = RotateLeft(balancesNode);
        }
        if (a == -2) //big left rotate
        {
            long long c2,d2;
            if (balancesNode->GetLeftChild()->rightsize==0)
                c2=0;
            else
                c2=ceil(log(balancesNode->GetLeftChild()->rightsize)/log(2));
            if (log(balancesNode->GetLeftChild()->leftsize)==0)
                d2=0;
            else
                d2=ceil(log(balancesNode->GetLeftChild()->leftsize)/log(2));
            long long a2 = c2 - d2;
            if (a2 > 0)
                balancesNode->SetLeftChild(RotateLeft(balancesNode->GetLeftChild()));
            balancesNode = RotateRight(balancesNode);
        }
    }
    return balancesNode;
}
NodeTree* Tree::RotateLeft(NodeTree *x) {
    x->rightsize -= (1 + x->GetRightChild()->rightsize);
    x->GetRightChild()->SetParent(nullptr);
    if (x->GetRightChild()->GetLeftChild() != nullptr) {
        x->GetRightChild()->GetLeftChild()->SetParent(x);
    }
    x->SetParent(x->GetRightChild());
    NodeTree *b = x->GetRightChild();
    x->SetRightChild(b->GetLeftChild());
    b->SetLeftChild(x);
    x = b;
    x->leftsize += (1 + x->GetLeftChild()->leftsize);
    return x;
}
NodeTree* Tree::RotateRight(NodeTree *x) {
    x->leftsize -= (1 + x->GetLeftChild()->leftsize);
    x->GetLeftChild()->SetParent(nullptr);
    if (x->GetLeftChild()->GetRightChild() != nullptr) {
        x->GetLeftChild()->GetRightChild()->SetParent(x);
    }
    x->SetParent(x->GetLeftChild());
    NodeTree *b = x->GetLeftChild();
    x->SetLeftChild(b->GetRightChild());
    b->SetRightChild(x);
    x = b;
    x->rightsize += (1 + x->GetRightChild()->rightsize);
    return x;
}
NodeTree *Tree::Insert(NodeTree *newItem, NodeTree *tempRoot) {
    if (nodeRoot == nullptr) {
        nodeRoot = new NodeTree();
        nodeRoot->SetKey(newItem->GetKey());
        return nodeRoot;
    } else {
        if (tempRoot->GetKey() > newItem->GetKey()) {
            if (tempRoot->GetLeftChild() == nullptr) {
                tempRoot->SetLeftChild(newItem);
                tempRoot->GetLeftChild()->SetParent(tempRoot);
                tempRoot->leftsize++;
            } else {
                tempRoot->leftsize++;
                tempRoot->SetLeftChild(Insert(newItem, tempRoot->GetLeftChild()));
                tempRoot=DoAlignment(tempRoot);
            }
        } else {
            if (tempRoot->GetKey() < newItem->GetKey()) {
                if (tempRoot->GetRightChild() == nullptr) {
                    tempRoot->SetRightChild(newItem);
                    tempRoot->GetRightChild()->SetParent(tempRoot);
                    tempRoot->rightsize++;
                } else {
                    tempRoot->rightsize++;
                    tempRoot->SetRightChild(Insert(newItem, tempRoot->GetRightChild()));
                    tempRoot=DoAlignment(tempRoot);
                }
            }
        }
    }
    return tempRoot;
}

NodeTree *Tree::Delete(long long &removableItem, NodeTree *tempRoot) {
    if (tempRoot == nullptr) return tempRoot;//если дерево пусто
    if (removableItem < tempRoot->GetKey()) {
        //если ключ больше удаляемого: фиксим высоту левого поддерева, правим высоту, правим разницу
        tempRoot->leftsize--;
        tempRoot->SetLeftChild(Delete(removableItem, tempRoot->GetLeftChild()));
        tempRoot->SetLeftChild(DoAlignment(tempRoot->GetLeftChild()));
        if (tempRoot->GetLeftChild() != nullptr)
            tempRoot->GetLeftChild()->SetParent(tempRoot);
    } else {
        if (removableItem > tempRoot->GetKey()) {
            //если ключ меньше удаляемого: фиксим высоту правого поддерева, правим высоту, правим разницу
            tempRoot->rightsize--;
            tempRoot->SetRightChild(Delete(removableItem, tempRoot->GetRightChild()));
            tempRoot->SetRightChild(DoAlignment(tempRoot->GetRightChild()));
            if (tempRoot->GetRightChild() != nullptr)
                tempRoot->GetRightChild()->SetParent(tempRoot);
        } else {
            //если ключ равен искомому
            if (tempRoot->GetLeftChild() != nullptr && tempRoot->GetRightChild() != nullptr) {
                KeyType a=Minimum(tempRoot->GetRightChild())->GetKey();
                tempRoot->SetKey(a);
                tempRoot->rightsize--;
                tempRoot->SetRightChild(Delete(a, tempRoot->GetRightChild()));
                tempRoot->SetRightChild(DoAlignment(tempRoot->GetRightChild()));
            } else {
                if (tempRoot->GetLeftChild() != nullptr) {
                    //если есть только левое поддерево
                    tempRoot = tempRoot->GetLeftChild();
                    if (tempRoot->GetLeftChild() != nullptr)
                        tempRoot->GetLeftChild()->SetParent(tempRoot);
                } else {
                    if (tempRoot->GetRightChild() != nullptr) {
                        //если есть только правое поддерево
                        tempRoot = tempRoot->GetRightChild();
                        if (tempRoot->GetRightChild() != nullptr)
                            tempRoot->GetRightChild()->SetParent(tempRoot);
                    } else {
                        //если поддеревьев нет
                        return nullptr;
                    }
                }
            }
        }
    }
    return tempRoot;
}

class TreeAVL {
public:
    TreeAVL();

    [[nodiscard]] virtual bool IsEmpty() const;

    virtual void Insert(long long &a);//добавление вершины
    virtual void Delete(long long &a);//удаление вершины
    virtual void Exists(long long &a);//поиск вершины
    virtual void GetPrev(long long &a);//предыдущая вершина
    virtual void GetNext(long long &a);//следующая вершина


private:
    //дерево
    Tree _treeAVL;
};
TreeAVL::TreeAVL() = default;
void TreeAVL::Exists(long long &a) {
    _treeAVL.Search(a, _treeAVL.nodeRoot);
}
void TreeAVL::GetPrev(long long &a) {
    if (_treeAVL.nodeRoot == nullptr) {
        std::cout << "none" << std::endl;
    } else {
        long long ans = _treeAVL.PrevSearch(a, _treeAVL.nodeRoot);
        if (ans == (long long) (-1e9)) {
            std::cout << "none" << std::endl;
        } else {
            std::cout << ans << std::endl;
        }
    }
}
void TreeAVL::GetNext(long long &a) {
    if (_treeAVL.nodeRoot == nullptr) {
        std::cout << "none" << std::endl;
    } else {
        long long ans = _treeAVL.NextSearch(a, _treeAVL.nodeRoot);
        if (ans == (long long) (1e9)) {
            std::cout << "none" << std::endl;
        } else {
            std::cout << ans << std::endl;
        }
    }
}
bool TreeAVL::IsEmpty() const {
    return _treeAVL.IsEmpty();
}
void TreeAVL::Insert(long long &a) {
    auto *temp = new NodeTree;
    temp->SetKey(a);
    if (!_treeAVL.SearchBool(a, _treeAVL.nodeRoot)) {
        _treeAVL.nodeRoot = _treeAVL.Insert(temp, _treeAVL.nodeRoot);
    }
}
void TreeAVL::Delete(long long &a) {
    if (_treeAVL.SearchBool(a, _treeAVL.nodeRoot)) {
        _treeAVL.nodeRoot = _treeAVL.DoAlignment(_treeAVL.Delete(a, _treeAVL.nodeRoot));
    }

}

void acceleeration() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
}
int NUM_Operations(std::string &x) {
    int counter = 0;
    for (const auto &y:OPERATIONS) {
        if (y == x) return counter;
        counter++;
    }
    return -1;
}
void solve() {
    TreeAVL tree;
    std::string s;

    while (std::cin >> s) {
        KeyType value;
        std::cin >> value;
        switch (NUM_Operations(s)) {
            case 0://Insert +
                tree.Insert(value);
                break;
            case 1://Delete +
                tree.Delete(value);
                break;
            case 2://Exists +

                tree.Exists(value);
                break;
            case 3://Next +

                tree.GetNext(value);
                break;
            case 4://Prev +

                tree.GetPrev(value);
                break;
            default://None +
                std::cout << "WRONG COMMAND!!!" << std::endl;
                break;
        }
    }
}

int main() {
    acceleeration();
    solve();
    return 0;
}