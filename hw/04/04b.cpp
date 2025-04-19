#include <iostream>

struct Base {
    int value;

    void printBaseValue() {
        std::cout << value << std::endl;
    }
};

struct Derived : Base {
    int value;
};

void setBaseValue(Derived& d, int n) {
    d.Base::value = n;
}

int main() {
    int n;
    std::cin >> n;
    Derived d;
    setBaseValue(d, n);
    d.printBaseValue();
}

/// 基类和子类有同名变量
