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
        in.open("in.in");
        out.open("out.out");
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
        std::vector<long long> tempTree;

    public:

        std::vector<long long> sum;

        SegmentTree() : tree(sizeOfTree * 4),
                        tempTree(sizeOfTree * 4, INF) {};

        ~SegmentTree() = default;

        void Build(long long vertex,
                   long long left,
                   long long right) {

            if (left + 1 == right) {

                tree[vertex] = sum[left];

                return;
            }

            long long middle = (left + right) / 2;

            Build(2 * vertex, left, middle);
            Build(2 * vertex + 1, middle, right);

            tree.at(2 * vertex) < tree.at(2 * vertex + 1) ? tree.at(vertex) = tree.at(2 * vertex) :
                    tree.at(vertex) = tree.at(2 * vertex + 1);

        }


        void InsertVertexToTemp(long long vertex,
                                long long left,
                                long long right) {

            if (tempTree[vertex] == INF) {

                return;
            }

            tree[vertex] = tempTree[vertex];

            if (1 != right - left) {

                tempTree[2 * vertex] = tempTree[vertex];
                tempTree[2 * vertex + 1] = tempTree[vertex];
            }

            tempTree[vertex] = INF;
        }

        void UpdateSG(long long vertex,
                      long long value,
                      long long firstLeft,
                      long long firstRight,
                      long long secondLeft,
                      long long secondRight) {

            InsertVertexToTemp(vertex, firstLeft, firstRight);

            if (firstRight <= secondLeft || secondRight < firstLeft) {
                return;
            }

            if (secondLeft <= firstLeft && firstRight - 1 <= secondRight) {

                tempTree[vertex] = value;
                InsertVertexToTemp(vertex, firstLeft, firstRight);

                return;
            }

            long long middle = (firstLeft + firstRight) / 2;

            UpdateSG(2 * vertex,     value, firstLeft, middle, secondLeft, secondRight);
            UpdateSG(2 * vertex + 1, value, middle, firstRight, secondLeft, secondRight);

            tree[2 * vertex] < tree[2 * vertex + 1] ? tree[vertex] = tree[2 * vertex] :
                    tree[vertex] = tree[2 * vertex + 1];

        }

        long long GetAnswer(long long vertex,
                            long long firstLeft,
                            long long firstRight,
                            long long secondLeft,
                            long long secondRight) {

            InsertVertexToTemp(vertex, firstLeft, firstRight);

            if (firstRight <= secondLeft || secondRight < firstLeft) {

                return INF;
            }

            if (secondLeft <= firstLeft && firstRight - 1 <= secondRight) {

                return tree[vertex];
            }

            long long middle = (firstLeft + firstRight) / 2;

            return std::min(GetAnswer(2 * vertex, firstLeft, middle, secondLeft,
                                      secondRight),
                            GetAnswer(2 * vertex + 1, middle, firstRight, secondLeft,
                                      secondRight));
        }
    };
}


int main() {
    using namespace CHEATS;
    long long red;
    long long green;
    long long blue;
    long long lengthSG;
    long long paintingRequests;

    using namespace TREES::SEGMENT_tree;

    SegmentTree tree;

    std::cin >> lengthSG;

    for (int i = 0; i < lengthSG; ++i) {
        std::cin >> red >> green >> blue;
        tree.sum.push_back(red + green + blue);
    }

    std::cin >> paintingRequests;

    tree.Build(1, 0, lengthSG);

    long long beginningFirstSG;
    long long endingFirstSG;
    long long beginningSecondSG;
    long long endingSecondSG;

    for (long long i = 0; i < paintingRequests; ++i) {

        std::cin >> beginningFirstSG >> endingFirstSG
                 >> red >> green >> blue
                 >> beginningSecondSG >> endingSecondSG;

        tree.UpdateSG(1, red + green + blue, 0, lengthSG, beginningFirstSG, endingFirstSG);
        long long ans = tree.GetAnswer(1, 0, lengthSG, beginningSecondSG, endingSecondSG);
        std::cout << ans << ' ';
    }
    return 0;
}