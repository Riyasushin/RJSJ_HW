#include <iostream>
#include <utility>
using std::cin, std::cout, std::endl;
int multiply(int a, int b, int c = 1, int d = 1) {
    return a * b * c * d;
}
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << multiply(a, b) << endl;
    cout << multiply(a, b, c) << endl;
    cout << multiply(a, b, c, d) << endl;
}

// 下一行代码用于确保你未使用函数重载，不用管
static_assert(std::is_function_v<decltype(multiply)>);

/*
参数缺省，只能是最后一行的参数进行缺省
*/