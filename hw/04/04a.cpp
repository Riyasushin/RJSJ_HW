#include <iostream>

class Base {
public:
    int baseValue;
    Base(int value): baseValue{value} { }
};

class Derived : public Base {
    int derivedValue;

public:
    Derived(): derivedValue{45818}, Base{3378} {}
    Derived(int n): derivedValue{n}, Base{n} {}
//
    void print() {
        std::cout << baseValue << ' ' << derivedValue << std::endl;
    }
};

int main() {
    Derived a;
    a.print();

    int n;
    std::cin >> n;
    a = n;
    a.print();
}
