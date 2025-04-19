#include <iostream>

class Base {
public:
    void f() {
        std::cout << "Base::f" << std::endl;
    }
    virtual void g() {
        std::cout << "Base::g" << std::endl;
    }

    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void f() {
        std::cout << "Derived::f" << std::endl;
    }
    void g() {
        std::cout << "Derived::g" << std::endl;
    }
};

int main() {
    Base* ptr1 = new Base{};
    ptr1->f();
    ptr1->g();
    delete ptr1;

    Base* ptr2 = new Derived{};
    ptr2->f();
    ptr2->g();
    delete ptr2;

    auto obj3 = Derived{};
    obj3.f();
    obj3.g();
}

/// 基类指针承接子类
/// 如果不是虚函数，不能运行时识别
