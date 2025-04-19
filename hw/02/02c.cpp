#include <iostream>
#include <utility>
using std::cout, std::endl;

class MyClass {
public:
    int value;

    MyClass(int value = 42) : value{value} {}
    MyClass& getObj() {
        return *this;
    }
    const MyClass& getObj() const {
        return *this;
    }
};

// 一些黑魔法，避免你写出错误的代码
static_assert(std::is_const_v<std::
remove_reference_t<decltype(std::
declval<const MyClass&>().getObj())>>);

void print(const MyClass& a) {
    cout << a.getObj().value << endl;
}

int main() {
    int m, n;
    MyClass a;
    cout << a.value << endl;
    while (std::cin >> m >> n) {
        a.getObj() = m;
        cout << a.value << " ";
        a.getObj() = MyClass(n);
        print(a);
    }
}

/*
通过 a 的只读性区分两个重载，定义不同的返回值类型
*/
