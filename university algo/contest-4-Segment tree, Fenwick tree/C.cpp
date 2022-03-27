#include <iostream>
#include <fstream>
#include <vector>

namespace CHEATS {

    typedef long long ll;
    ll const sizeOfTree = 2e5 + 1;
    ll const INF = 1e18;


    namespace FLOWS {

#ifndef IN_OUT

        std::ifstream in;
        std::ofstream out;

#define IN_OUT 1
#endif //IN_OUT

    }

    using namespace std;

    template<class T>
    T &_slide(T &Vec, int timer = 1) {
        T newT;
        for (auto x:Vec) {
            if (timer == 0)
                newT.push_back(x);
            else {
                Vec.push_back(x);
                timer--;
            }
        }
        Vec = newT;
        return Vec;
    }

    void _acceleration() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    void _file_open() {
        using namespace FLOWS;
        in.open("inverse.in");
        out.open("inverse.out");
    }

    void _file_close() {
        using namespace FLOWS;
        in.close();
        out.close();
    }

}

namespace TREES::SEGMENT_tree {

    using namespace CHEATS;

    class SegmentTree {
    private:

        std::vector<long long> tree;

    public:

        std::vector<long long> a;

        SegmentTree() :  tree(sizeOfTree * 4) {};

        ~SegmentTree() = default;

        void BuildTree(long long vertex,
                       long long left,
                       long long right) {

            if (left + 1 == right) {

                tree[vertex] = a[left];

                return;
            }

            long long middle = (left + right) / 2;

            BuildTree(2 * vertex,     left, middle);
            BuildTree(2 * vertex + 1, middle, right);

            tree[2 * vertex] > tree[2 * vertex + 1] ? tree[vertex] = tree[2 * vertex] :
                                                      tree[vertex] = tree[2 * vertex + 1];

        }

        void UpdatePoint(long long vertex,
                         long long left,
                         long long right,
                         long long index,
                         long long value) {

            if (left + 1 == right) {

                a[left] = value;
                tree[vertex] = a[left];

                return;
            }

            long long mid = (left + right) / 2;

            if (index < mid)
                UpdatePoint(2 * vertex,     left, mid, index, value);
            else
                UpdatePoint(2 * vertex + 1, mid, right, index, value);

            tree[2 * vertex] > tree[2 * vertex + 1] ? tree[vertex] = tree[2 * vertex] :
                                                      tree[vertex] = tree[2 * vertex + 1];

        }

        long long GetAnswer(long long vertex,
                            long long left,
                            long long right,
                            long long index,
                            long long value) {

            if (right <= index || tree[vertex] < value)
                return -INF;

            if (left + 1 == right)
                return left;

            long long middle = (left + right) / 2;
            long long answer = GetAnswer(2 * vertex + 0, left, middle, index, value);

            if (answer != -INF)
                return answer;

            else return GetAnswer(2 * vertex + 1, middle, right, index, value);
        }

    };
}

void Solve() {

    long long n;
    long long m;

    using namespace TREES::SEGMENT_tree;

    SegmentTree tree;

    std::cin >> n >> m;

    long long value;

    for (long long i = 0; i < n; ++i) {

        std::cin >> value;

        tree.a.push_back(value);
    }

    tree.BuildTree(1, 0, n);

    long long index;
    long long newValue;
    long long type;

    for (ll i = 0; i < m; ++i) {
        std::cin >> type >> index >> newValue;
        index--;
        if (!type)
                           tree.UpdatePoint(1, 0, n, index, newValue);
        else {
            long long ans= tree.GetAnswer(1, 0, n, index, newValue);
            if (ans==-INF)
                std::cout << -1 << "\n";
            else
                std::cout <<ans + 1 << "\n";
        }
    }
}

int main() {
    using namespace CHEATS;
    _acceleration();
    Solve();
}
