#include <iostream>
#include <climits>
using std::cin, std::cout, std::endl;

// minRef
int& minRef(int& a, int& b) {
    return a < b ? a : b;
}
int main() {
    int a = 0, b = 0;
    for (int i = 0; i < 5; i++) {
        cin >> minRef(a, b);
    }
    minRef(a, b) = INT_MAX;
    cout << minRef(a, b) << endl;
}
/*
返回一个引用
*/