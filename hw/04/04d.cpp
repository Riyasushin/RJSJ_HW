#include <iostream>

class A {
public:
    void Fun() const {
        std::cout << "A::Fun" << std::endl;
    }
    virtual void Do() const {
        std::cout << "A::Do" << std::endl;
    }

    virtual ~A() = default;
};

class B : public A {
public:
    virtual void Do() const {
        std::cout << "B::Do" << std::endl;
    }
};

class C : public B {
public:
    void Do() const {
        std::cout << "C::Do" << std::endl;
    }
    void Fun() const {
        std::cout << "C::Fun" << std::endl;
    }
};

void Call(
    const A& a
) {
    a.Fun();
    a.Do();
}

int main() {
    A a;
    const C c{};
    Call(a);
    Call(c);
}


