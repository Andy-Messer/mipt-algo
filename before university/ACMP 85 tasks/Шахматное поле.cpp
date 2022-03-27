#include <iostream>
using namespace std;
int main() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (abs(x1 - y1) % 2 == abs(x2 - y2) % 2) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}