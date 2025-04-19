#include <iostream>
using std::cin, std::cout, std::endl;

int main() {
    int num;
    char str[10];
    // 实现num_ref和str_ref
    int &num_ref = num;
    auto &str_ref = str;
    //
    cin >> num_ref >> str_ref;
    cout << num << endl;
    cout << str << endl;
}