#include <iostream>

struct BaseInt {
private:
    int value;

public:
    void set(int x) { value = x; }
    int getInt() { return value; }
};

struct BaseDouble {
private:
    double value;

public:
    void set(double x) { value = x; }
    double getDouble() { return value; }
};

class Derived : public BaseInt, public BaseDouble {
public:
    /// 重载
    // void set(int x) { BaseInt::set(x); }
    // void set(double x) { BaseDouble::set(x); }

    /// 下放
    using BaseInt::set;
    using BaseDouble::set;
    /////////////////

};

int main() {
    Derived obj;
    int i;
    double d;
    while (std::cin >> i >> d) {
        obj.set(i), obj.set(d);
        std::cout << obj.getInt() << ' '
            << obj.getDouble() << std::endl;
    }
}

// 多继承

