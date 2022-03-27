#include <iostream>
#include <string>
#include <vector>

//#define IOS std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
long long const Red_Marker = -(1e11-200);
/*------------------------------------------------------*/
//поисковый ключ
/*------------------------------------------------------*/

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


/*------------------------------------------------------*/



/*------------------------------------------------------*/
//"HeapMax.h"
/*------------------------------------------------------*/
long long const MAX_HEAP = 1000000;
typedef KeyedItem HeapItemType;

class HeapMAX {

public:
    HeapMAX(); //конструктор по умолчанию
//операции над кучей
    [[nodiscard]] virtual bool IsEmpty() const;

    virtual void Insert(const HeapItemType &newItem, std::vector<long long> &used);

    virtual void Decrease(const HeapItemType &newItem, std::vector<long long> &used);

    virtual void Delete(HeapItemType &rootItem, std::vector<long long> &used, std::vector<long long> &AnArray);

    virtual long long getMax(HeapItemType &rootItem);


protected:
    void heapRebuild(long long root, std::vector<long long> &used);//преобразовывает полукучу в кучу

private:
    //std::vector<HeapItemType>items;
    HeapItemType *items = (HeapItemType *) calloc(MAX_HEAP, sizeof(HeapItemType));
    long long size;
};
/*------------------------------------------------------*/



/*------------------------------------------------------*/
//"HeapMax.cpp"
/*------------------------------------------------------*/
HeapMAX::HeapMAX() : size(0) {}

bool HeapMAX::IsEmpty() const {
    return bool(size == 0);
}

void HeapMAX::Decrease(const HeapItemType &newItem, std::vector<long long> &used) {
    if (size > MAX_HEAP)
        std::cout << "error";

    items[used[newItem.getPoz()]].decreaseKey(newItem.getKey());

    long long place = used[newItem.getPoz()];
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

void HeapMAX::Insert(const HeapItemType &newItem, std::vector<long long> &used) {
    if (size > MAX_HEAP)
        std::cout << "error";
    items[size] = newItem;
    long long place = size;
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

    ++size;
}

void HeapMAX::Delete(HeapItemType &rootItem, std::vector<long long> &used, std::vector<long long> &AnArray) {
    if (IsEmpty()) {
        std::cout << "error";
    } else {
        used[items[0].getPoz()] = -1;
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0, used);
    }
}

void HeapMAX::heapRebuild(long long root, std::vector<long long> &used) {
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
            heapRebuild(child, used);
        }
    }
}

long long HeapMAX::getMax(HeapItemType &rootItem) {
    rootItem = items[0];
    return items[0].getKey();
}
/*------------------------------------------------------*/





/*------------------------------------------------------*/
//"HeapMIN.h"
/*------------------------------------------------------*/
class HeapMIN {

public:
    HeapMIN();

    [[nodiscard]] virtual bool IsEmpty() const;

    virtual void Insert(const HeapItemType &newItem, std::vector<long long> &used);

    virtual void Decrease(const HeapItemType &newItem, std::vector<long long> &used);

    virtual void Delete(HeapItemType &rootItem, std::vector<long long> &used, std::vector<long long> &AnArray);

    virtual long long getMin(HeapItemType &rootItem);


protected:
    void heapRebuild(long long root, std::vector<long long> &used);//преобразовывает полукучу в кучу

private:
    //std::vector<HeapItemType>items;
    HeapItemType *items = (HeapItemType *) calloc(MAX_HEAP, sizeof(HeapItemType));
    long long size;
};
/*------------------------------------------------------*/



/*------------------------------------------------------*/
//"HeapMIN.cpp"
/*------------------------------------------------------*/
HeapMIN::HeapMIN() : size(0) {}

bool HeapMIN::IsEmpty() const {
    return bool(size == 0);
}

void HeapMIN::Decrease(const HeapItemType &newItem, std::vector<long long> &used) {
    if (size > MAX_HEAP)
        std::cout << "error";

    items[used[newItem.getPoz()]].decreaseKey(newItem.getKey());

    long long place = used[newItem.getPoz()];
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

void HeapMIN::Insert(const HeapItemType &newItem, std::vector<long long> &used) {
    if (size > MAX_HEAP)
        std::cout << "error";
    items[size] = newItem;
    long long place = size;
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

    ++size;
}

void HeapMIN::Delete(HeapItemType &rootItem, std::vector<long long> &used, std::vector<long long> &AnArray) {
    if (IsEmpty()) {
        std::cout << "error";
    } else {
        used[items[0].getPoz()] = -1;
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0, used);
    }
}

void HeapMIN::heapRebuild(long long root, std::vector<long long> &used) {
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
            heapRebuild(child, used);
        }
    }
}

long long HeapMIN::getMin(HeapItemType &rootItem) {
    rootItem = items[0];
    return items[0].getKey();
}

/*------------------------------------------------------*/

std::pair<std::string, long long> RequestArt(std::string request) {
    std::string requestType = "";
    long long i = 0;
    request += '#';
    while (request[i] - '0' != '('-'0' && request[i] - '0' != '#'-'0') {
        requestType += request[i];i++;
    }
    if (request[i] - '0' == '#') {
        return {requestType, Red_Marker};
    }
    long long number = 0;i++;
    while (request[i] - '0' != ')'-'0') {
        number += request[i] - '0';
        number *= 10;i++;
    }
    number/=10;
    return {requestType, number};
}

int main() {
    HeapMAX heap_max;
    HeapMIN heap_min;
    long long N;
    std::string request;
    std::cin >> N;
    long long current = 0;
    std::vector<long long> used1(N, -1);
    std::vector<long long> anArray1(N, 0);
    std::vector<long long> used2(N, -1);
    std::vector<long long> anArray2(N, 0);
    while (N--) {
        std::cin >> request;
        std::pair<std::string, long long> requestInfo = RequestArt(request);
        KeyedItem new_Item;
        if (requestInfo.first == "Insert") {
            new_Item.setKey(requestInfo.second);
            new_Item.setPoz(current);
            heap_max.Insert(new_Item, used1);
            heap_min.Insert(new_Item, used2);
            anArray1[current] = requestInfo.second;
            anArray2[current] = requestInfo.second;
        }
        if (requestInfo.first == "GetMin") {
            KeyedItem new_root_Item;
            long long ans = heap_min.getMin(new_root_Item);
            std::cout << ans << '\n';
            heap_min.Delete(new_root_Item, used2, anArray2);
            new_root_Item.setKey(Red_Marker);
            heap_max.Decrease(new_root_Item, used1);
            heap_max.Delete(new_root_Item, used1, anArray1);
        }
        if (requestInfo.first == "GetMax") {
            KeyedItem new_root_Item;
            long long ans = heap_max.getMax(new_root_Item);
            std::cout << ans << '\n';
            heap_max.Delete(new_root_Item, used1, anArray1);
            new_root_Item.setKey(-Red_Marker);
            heap_min.Decrease(new_root_Item, used2);
            heap_min.Delete(new_root_Item, used2, anArray2);
        }current++;
    }


}