#include <iostream>
#include <cmath>

// 补全 funcs 的定义

using DoubleFunc = double(double);

double f0(double x) {
    return -x;
}
double f1(double x) {
    return x * x;
}
DoubleFunc* funcs[] = {f0, f1, std::sqrt, std::log10, std::sin};

int main() {
    double src;
    int n;
    std::cin >> src >> n;
    for (int i = 0; i < n; i++) {
        int op;
        std::cin >> op;
        src = funcs[op](src);
    }
    std::cout << std::fixed << src << std::endl;
}

/*
用using 简化复杂类型

函数指针的数组
*/