#include <iostream>
#include <type_traits>
using std::cout, std::endl;
class Animal {
public:
    Animal() = default;
    virtual void speak() = 0;
    virtual ~Animal() = default;
};
class Dog : public Animal {
public:
    void speak() override { cout << "Bark!" << endl; }
};
class Cat : public Animal {
public:
    void speak() override { cout << "Meow!" << endl; }
};

// 这是一些黑魔法代码，你不用管
template<typename,typename>struct J:
std::true_type{};template<typename T
>struct J<T,std::void_t<decltype(T()
)>>:std::false_type{};static_assert(
J<Animal,void>::value);static_assert
(std::has_virtual_destructor<Animal>
::value);

int main(){
    Dog d;
    Cat c;
    // Animal a;  //报错
    Animal* a[2]{&d, &c};
    for (int i = 0; i < 2; i++) {
        a[i]->speak();
    }
    return 0;
}

/// 含有纯虚函数的类为抽象类，无法定义具体对象。
/// 含有虚函数的类一般都应当声明虚析构函数。
