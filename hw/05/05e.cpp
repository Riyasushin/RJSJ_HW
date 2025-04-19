#include <iostream>
#include <cmath>
// 在此处补充你的代码
class Printer {

public:

    /// 注意先后顺序，为什么这个昂后面会报错？？？？ 
    Printer& operator() () {
        std::cout << '\n';
        return *this;
    }

    template<typename T>
    Printer& operator()(const T& val) {
        std::cout << val;
        return *this;
    }

   

};

int main() {
    Printer printer;

    int x, y;
    std::cin >> x >> y;

    printer("The sum of ")(x)(" and ")(y)(" is ")(x + y)('!')();

    double root = std::sqrt(x);
    printer("The square root of ")(x)(" is ")(root)('.')();
}