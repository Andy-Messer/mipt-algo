#include <iostream>
using namespace std;
int main() {
    int r_1, r_2, r_3;
    cin >> r_1 >> r_2 >> r_3;
    if (r_1 < r_2 + r_3) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
    return 0;
}