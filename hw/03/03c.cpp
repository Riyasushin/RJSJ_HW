#include <cmath>
#include <iostream>

class Printer {
public:
    Printer operator()() {
        std::cout << std::endl;
        return {};
    }
    Printer operator()(char x) {
        std::cout << x;
        return {};
    }
    Printer operator()(int x) {
        std::cout << x;
        return {};
    }
    Printer operator()(double x) {
        std::cout << x;
        return {};
    }
    Printer operator()(const char* x) {
        std::cout << x;
        return {};
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

/*
重载括号运算符
*/
