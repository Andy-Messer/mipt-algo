#include <iostream>
#include <vector>

typedef long long KeyType;
const std::vector<std::string> OPERATIONS =
        {
                "insert", "delete", "exists", "next", "prev"
        };

class KeyedItem {
private:
    KeyType SearchKey;
    KeyType Sum;
    KeyedItem *_parent, *_rightChild, *_leftChild;
    //веса правого и левого дерева
public:
    KeyedItem(KeyType a, KeyedItem *b, KeyedItem *c) : SearchKey(0), Sum(0), _parent(nullptr), _rightChild(nullptr),
                                                       _leftChild(nullptr) {
        SearchKey = a;
        _leftChild = b;
        _rightChild = c;
    };

    //Ключ рассматриваемой вершины
    void SetKey(KeyType n_value) {
        SearchKey = n_value;
    }

    [[nodiscard]] KeyType GetKey() const {
        return SearchKey;
    }

    void UpdateSum() {
        if (this == NULL) return;
        KeyType rightSum = 0, leftSum = 0;
        if (_rightChild != nullptr)
            rightSum = _rightChild->Sum;
        if (_leftChild != nullptr)
            leftSum = _leftChild->Sum;
        Sum = rightSum + leftSum + SearchKey;
    }

    [[nodiscard]] KeyType GetSum() const {
        return Sum;
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

class SplayTree {
public:
    SplayTree() = default;;

    static void UpdateParent(KeyedItem *child, KeyedItem *parent) {
        if (child != nullptr)
            child->SetParent(parent);
    }

    static void ChangeParent(KeyedItem *newParent) {
        if (newParent != nullptr) {
            UpdateParent(newParent->GetLeftChild(), newParent);
            UpdateParent(newParent->GetRightChild(), newParent);
        }
    }

    virtual void Rotate(NodeTree *parent, NodeTree *child) {
        NodeTree *grandParent = nullptr;
        if (parent != nullptr)
            grandParent = parent->GetParent();
        if (grandParent != nullptr) {
            if (grandParent->GetLeftChild() == parent) {
                grandParent->SetLeftChild(child);
            } else {
                grandParent->SetRightChild(child);
            }
        }
        if (parent != nullptr)
            if (parent->GetLeftChild() == child) {
                parent->SetLeftChild(child->GetRightChild());
                child->SetRightChild(parent);
            } else {
                parent->SetRightChild(child->GetLeftChild());
                child->SetLeftChild(parent);
            }
        if (child != nullptr)
            ChangeParent(child);
        if (parent != nullptr)
            ChangeParent(parent);
        child->SetParent(grandParent);
    }

    NodeTree *Splay(NodeTree *Node) {
        NodeTree *temp;
        if (Node->GetParent() == nullptr) {
            return Node;
        }
        NodeTree *parent = Node->GetParent();
        NodeTree *grandparent = parent->GetParent();
        if (grandparent == nullptr) {
            Rotate(parent, Node);
            Node->UpdateSum();
            parent->UpdateSum();
            return Node;
        } else {
            bool zigzig = (grandparent->GetLeftChild() == parent) == (parent->GetLeftChild() == Node);
            if (zigzig) {
                Rotate(grandparent, parent);
                grandparent->UpdateSum();
                parent->UpdateSum();
                Rotate(parent, Node);
                Node->UpdateSum();
                parent->UpdateSum();
            } else {
                Rotate(parent, Node);
                Node->UpdateSum();
                parent->UpdateSum();
                Rotate(grandparent, Node);
                grandparent->UpdateSum();
                Node->UpdateSum();
            }
            temp = Splay(Node);
            Node->UpdateSum();
            temp->UpdateSum();
            return temp;
        }
    }

    NodeTree *Find(NodeTree *Node, const KeyType &key) {
        NodeTree *temp;
        if (Node == nullptr) {
            return nullptr;
        }
        if (key == Node->GetKey()) {
            temp = Splay(Node);
            Node->UpdateSum();
            temp->UpdateSum();
            return temp;
        }
        if (key < Node->GetKey() && Node->GetLeftChild() != nullptr) {
            temp = Find(Node->GetLeftChild(), key);
            rootNode = temp;
            temp->UpdateSum();
            return temp;
        }
        if (key > Node->GetKey() && Node->GetRightChild() != nullptr) {
            temp = Find(Node->GetRightChild(), key);
            rootNode = temp;
            temp->UpdateSum();
            return temp;
        }
        temp = Splay(Node);
        Node->UpdateSum();
        temp->UpdateSum();
        return temp;
    }

    std::pair<NodeTree *, NodeTree *> Split(NodeTree *root, KeyType key) {
        if (root == nullptr) {
            return {nullptr, nullptr};
        }
        root = Find(root, key);
        if (root->GetKey() == key) {
            UpdateParent(root->GetLeftChild(), nullptr);
            UpdateParent(root->GetRightChild(), nullptr);
            return {root->GetLeftChild(), root->GetRightChild()};
        }
        if (root->GetKey() < key) {
            NodeTree *right = root->GetRightChild();
            root->SetRightChild(nullptr);
            UpdateParent(right, nullptr);
            return {root, right};
        } else {
            NodeTree *left = root->GetLeftChild();
            root->SetLeftChild(nullptr);
            UpdateParent(left, nullptr);
            return {left, root};
        }
    }

    NodeTree *Insert(NodeTree *root, long long key) {
        root = Find(root, key);
        if (root != nullptr) {
            if (root->GetKey() != key) {
                std::pair<NodeTree *, NodeTree *> lr_Node = Split(root, key);
                root = new KeyedItem(key, lr_Node.first, lr_Node.second);
                root->UpdateSum();
                ChangeParent(root);
            }
        } else {
            std::pair<NodeTree *, NodeTree *> lr_Node = Split(root, key);
            root = new KeyedItem(key, lr_Node.first, lr_Node.second);
            root->UpdateSum();
            ChangeParent(root);
        }
        return root;
    }

    NodeTree *Merge(NodeTree *left, NodeTree *right) {
        if (right == nullptr) {
            return left;
        }
        if (left == nullptr) {
            return right;
        }
        right = Find(right, left->GetKey());
        right->SetLeftChild(left);
        left->SetRightChild(right);
        return right;
    }

    NodeTree *Delete(NodeTree *root, KeyType key) {
        root = Find(root, key);
        UpdateParent(root->GetLeftChild(), nullptr);
        UpdateParent(root->GetRightChild(), nullptr);
        return Merge(root->GetLeftChild(), root->GetRightChild());
    }

    KeyType FindSum(NodeTree *root, KeyType &left, KeyType &right) {
        long long rightSum=0;
        NodeTree *rightNode = Find(root, right);
        if (rightNode->GetRightChild() != nullptr) rightSum = rightNode->GetRightChild()->GetSum();
        if (right < rightNode->GetKey())rightSum += rightNode->GetKey();
        root = rightNode;
        root->UpdateSum();
        NodeTree *leftNode = Find(root, left);
        root = leftNode;
        root->UpdateSum();
        long long rootSum = 0, leftSum = 0;
        if (root != nullptr) rootSum = root->GetSum();

        if (leftNode->GetLeftChild() != nullptr) leftSum = leftNode->GetLeftChild()->GetSum();
        if (left > leftNode->GetKey())leftSum += leftNode->GetKey();
        KeyType ans = rootSum - rightSum - leftSum;
        return ans;
    }

    NodeTree *rootNode = nullptr;
};

int main() {
    SplayTree tree;
    long long n;
    std::cin >> n;
    char previousS='\0';
    long long previousANS = 0;
    for (int i = 0; i < n; i++) {
        char s;
        std::cin >> s;
        if (previousS == '?') {
            if (s == '+') {
                KeyType value;
                std::cin >> value;
                tree.rootNode = tree.Insert(tree.rootNode, (previousANS + value) % (1000000000));
            }
            if (s == '?') {
                KeyType right, left;
                std::cin >> left >> right;
                previousANS = tree.FindSum(tree.rootNode, left, right);
                std::cout << previousANS << std::endl;
            }
            previousS = s;
        } else {
            if (s == '+') {
                KeyType value;
                std::cin >> value;
                tree.rootNode = tree.Insert(tree.rootNode, value);
            }
            if (s == '?') {
                KeyType right, left;
                std::cin >> left >> right;
                previousANS = tree.FindSum(tree.rootNode, left, right);
                std::cout << previousANS << std::endl;
            }
            previousS = s;
        }
    }
}