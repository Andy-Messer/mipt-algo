#include <iostream>
#include <string>
#include <vector>


typedef long long KeyType;

class KeyedItem {
public:
    KeyedItem() : searchKey(0), poz(0) {};

    void setKey(long long n_value) {
        searchKey = n_value;
    }

    void decreaseKey(long long n_value) {
        searchKey -= n_value;
    }

    void setPoz(long long n_value) {
        poz = n_value;
    }

    [[nodiscard]] long long getKey() const {
        return searchKey;
    }

    [[nodiscard]] long long getPoz() const {
        return poz;
    }

private:
    KeyType searchKey;
    KeyType poz;
};

long long const MAX_HEAP = 1000000;
typedef KeyedItem HeapItemType;

class HeapMAX {

public:
    HeapMAX(); //конструктор по умолчанию
//операции над кучей
    [[nodiscard]] virtual bool IsEmpty() const;

    [[nodiscard]] virtual long long GetSize() const;

    virtual void DefaultInfo(long long newSize);

    virtual void Insert(const HeapItemType &newItem);

    virtual void Delete(HeapItemType &rootItem);

    virtual void Decrease(const HeapItemType &newItem);

    virtual long long GetMax(HeapItemType &rootItem);

    virtual void SwiftUp(const HeapItemType &newItem, long long existing_place);

protected:
    void SwiftDown(long long root);//преобразовывает полукучу в кучу

private:
    //std::vector<HeapItemType>items;
    std::vector<long long> used;
    std::vector<long long> anArray;
    HeapItemType *items = (HeapItemType *) calloc(MAX_HEAP, sizeof(HeapItemType));
    long long size;
};

HeapMAX::HeapMAX() : size(0), used(0, -1), anArray(0, 0) {}

long long HeapMAX::GetSize() const{
    return size;
}

bool HeapMAX::IsEmpty() const {
    return bool(size == 0);
}

void HeapMAX::DefaultInfo(long long newSize) {
    used.resize(newSize, -1);
    anArray.resize(newSize, 0);
}

void HeapMAX::Decrease(const HeapItemType &newItem) {
    if (size > MAX_HEAP)
        std::cout << "error";
    items[used[newItem.getPoz()]].decreaseKey(newItem.getKey());
    long long place = used[newItem.getPoz()];
    SwiftUp(newItem, place);
}

void HeapMAX::Insert(const HeapItemType &newItem) {
    if (size > MAX_HEAP)
        std::cout << "error";
    items[size] = newItem;
    SwiftUp(newItem, size);
    ++size;
}

void HeapMAX::Delete(HeapItemType &rootItem) {
    if (IsEmpty()) {
        std::cout << "error";
    } else {
        used[items[0].getPoz()] = -1;
        rootItem = items[0];
        items[0] = items[--size];
        SwiftDown(0);
    }
}

void HeapMAX::SwiftDown(long long root) {
    long long child = 2 * root + 1;
    if (child < size) {
        long long rightChild = child + 1;
        if ((rightChild < size) && (items[rightChild].getKey() > items[child].getKey())) {
            child = rightChild;
        }
        if (items[root].getKey() < items[child].getKey()) {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            used[items[root].getPoz()] = root;
            used[items[child].getPoz()] = child;
            SwiftDown(child);
        }
    }
}

long long HeapMAX::GetMax(HeapItemType &rootItem) {
    rootItem = items[0];
    return items[0].getKey();
}

void HeapMAX::SwiftUp(const HeapItemType &newItem, long long existing_place) {
    long long place = existing_place;
    long long parent = (place - 1) / 2;
    used[items[place].getPoz()] = place;
    used[items[parent].getPoz()] = parent;
    while ((parent >= 0) && (items[place].getKey() > items[parent].getKey())) {
        HeapItemType temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;
        used[items[place].getPoz()] = place;
        used[items[parent].getPoz()] = parent;
        place = parent;
        parent = (place - 1) / 2;
    }
}
/*------------------------------------------------------*/


int main() {
    HeapMAX heapMax;
    long long N, K;
    std::cin >> N >> K;
    heapMax.DefaultInfo(N);
    long long current=0;
    while (N--) {
        KeyedItem newItem,newItem_copy;

        long long temp;
        std::cin >> temp;
        newItem.setKey(temp);
        newItem.setPoz(current);
        if (heapMax.GetSize() == K) {
            if (heapMax.GetMax(newItem_copy) > temp) {
                heapMax.Delete(newItem_copy);
                heapMax.Insert(newItem);
                current++;
            }
        } else {
            heapMax.Insert(newItem);
            current++;
        }

    }
    std::vector<long long> a;
    while (K--) {
        KeyedItem newItem;
        a.push_back(heapMax.GetMax(newItem));
        heapMax.Delete(newItem);
    }
    for (long long i=a.size()-1;i>=0;i--){
        std::cout<<a[i]<<' ';
    }
}