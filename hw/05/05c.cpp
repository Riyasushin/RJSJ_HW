#include <iostream>
#include <string>

template <typename T>
class Value {
    T value;

public:
    Value(T v) : value(v) {}
    const T& get() const;
    template <typename U>
    void set(U v) {
        value = v;
    }
};

int main() {
    Value v1(42);
    Value<double> v2(3.14);
    Value<std::string> v3("Hello, world");

    std::cout << v1.get() << std::endl;
    std::cout << v2.get() << std::endl;
    std::cout << v3.get() << std::endl;

    v1.set(3.14);
    v2.set(42);
    v3.set("Hello, C++");
    std::cout << v1.get() << std::endl;
    std::cout << v2.get() << std::endl;
    std::cout << v3.get() << std::endl;
}
// 在此处补充你的代码
template<typename T>
const T& Value<T>::get() const {
    return value;
}
