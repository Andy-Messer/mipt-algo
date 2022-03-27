#include <iostream>
#include <string>
#include <vector>

typedef long long KeyType;
const int TEMP_SIZE = 0;

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

class Heap {

public:
    Heap(); //конструктор по умолчанию
//операции над кучей
    [[nodiscard]] virtual bool IsEmpty() const;

    virtual void DefaultInfo(long long newSize);

    virtual void Insert(const HeapItemType &newItem);

    virtual void Decrease(const HeapItemType &newItem);

    virtual void Delete(HeapItemType &rootItem);

    virtual long long GetMin(HeapItemType &rootItem);

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

Heap::Heap() : size(0), used(TEMP_SIZE, -1), anArray(TEMP_SIZE, 0) {}

bool Heap::IsEmpty() const {
    return bool(size == 0);
}

void Heap::DefaultInfo(long long newSize) {
    used.resize(newSize, -1);
    anArray.resize(newSize, 0);
}

void Heap::Decrease(const HeapItemType &newItem) {
    if (size > MAX_HEAP)
        std::cout << "error";

    items[used[newItem.getPoz()]].decreaseKey(newItem.getKey());
    long long place = used[newItem.getPoz()];

    SwiftUp(newItem, place);
}

void Heap::Insert(const HeapItemType &newItem) {
    if (size > MAX_HEAP)
        std::cout << "error";
    items[size] = newItem;
    SwiftUp(newItem, size);
    ++size;
}

void Heap::Delete(HeapItemType &rootItem) {
    if (IsEmpty()) {
        std::cout << "error";
    } else {
        used[items[0].getPoz()] = -1;
        rootItem = items[0];
        items[0] = items[--size];
        SwiftDown(0);
    }
}

void Heap::SwiftDown(long long root) {
    long long child = 2 * root + 1;
    if (child < size) {
        long long rightChild = child + 1;
        if ((rightChild < size) && (items[rightChild].getKey() < items[child].getKey())) {
            child = rightChild;
        }
        if (items[root].getKey() > items[child].getKey()) {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            used[items[root].getPoz()] = root;
            used[items[child].getPoz()] = child;
            SwiftDown(child);
        }
    }
}

long long Heap::GetMin(HeapItemType &rootItem) {
    rootItem = items[0];
    return items[0].getKey();
}

void Heap::SwiftUp(const HeapItemType &newItem, long long existing_place) {
    long long place = existing_place;
    long long parent = (place - 1) / 2;
    used[items[place].getPoz()] = place;
    used[items[parent].getPoz()] = parent;
    while ((parent >= 0) && (items[place].getKey() < items[parent].getKey())) {
        HeapItemType temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;
        used[items[place].getPoz()] = place;
        used[items[parent].getPoz()] = parent;
        place = parent;
        parent = (place - 1) / 2;
    }
}

const std::vector<std::string> OPERATIONS = {"insert", "decreaseKey", "getMin", "extractMin"};

long long WhatRQST(std::string rqst) {
    int rqst_local = 0;
    for (auto x:OPERATIONS) {
        if (x != rqst)
            rqst_local++;
        else break;
    }
    return rqst_local;
}

void DecisionUPD(std::string rqst, Heap &heap, long long &current) {
    KeyedItem new_Item;
    long long value, index, delta;
    KeyedItem new_root_Item;
    switch (WhatRQST(rqst)) {
        case 0:
            scanf("%lld", &value);
            new_Item.setKey(value);
            new_Item.setPoz(current);
            heap.Insert(new_Item);
            break;
        case 1:
            scanf("%lld %lld", &index, &delta);
            index--;
            new_Item.setPoz(index);
            new_Item.setKey(delta);
            heap.Decrease(new_Item);
            break;
        case 2: {
            long long ans = heap.GetMin(new_root_Item);
            printf("%lld\n", ans);
        }
            break;
        case 3:
            heap.Delete(new_root_Item);
            break;
    }
}

void SLrequest(char *requestStr, std::string &request) {
    for (int i = 0; i < 12; i++)
        if (requestStr[i] != 0) request += requestStr[i];
        else break;
}

int main() {

    Heap heap;

    long long num_of_request;
    char *requestStr = (char *) calloc(13, sizeof(char));
    long long current = 0;
    std::cin >> num_of_request;

    heap.DefaultInfo(num_of_request);

    while (num_of_request--) {
        std::string request = "";
        scanf("%s", requestStr);
        SLrequest(requestStr,request);
        DecisionUPD(request, heap, current);
        current++;
    }


}