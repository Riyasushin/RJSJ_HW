#include <iostream>
#include <utility>

class MyClass {
public:
    int value;

    MyClass() = default;
    explicit MyClass(int value) : value{value} {}
};

// 这是一些黑魔法代码，你不用管
template<typename, typename>struct J
:std::true_type{};template<typename T>
struct J<T,std::void_t<decltype(std::
declval<T&>()=0)>>:std::false_type{};
static_assert(J<MyClass,void>::value);

int main() {
    MyClass a;
    a = MyClass(42);
    // a = 42; // 报错
    std::cout << a.value << std::endl;
}

/**
 用 explicit 修饰的构造函数不能用于隐式类型转换。
*/
