#include <iostream>
#include <cmath>

int main() {
    auto compose = [](double (*g)(double), double (*f)(double)) {
        return [=](double x) {
            return g(f(x));
        };
    };
    double x;
    std::cin >> x;
    auto id = compose(std::asin, std::sin);
    std::cout << std::fixed << id(x) << std::endl;
}

/*
高阶函数，或者说 返回函数 的函数
大作业能用到
*/