#include <iostream>
#include <typeinfo>
using std::cout, std::endl;
class Animal {
public:
    virtual ~Animal() = default;
};
class Dog : public Animal {};
class Cat : public Animal {};
class Mouse : public Animal {};

void whoAreYou(Animal* a) {
    // if (typeid(*a) == typeid(Dog)) {
    //     cout << "I'm a dog." << endl;
    // } else if (typeid(*a) == typeid(Cat)) {
    //     cout << "I'm a cat." << endl;
    // } else if (typeid(*a) == typeid(Mouse)) {
    //     cout << "I'm a mouse." << endl;
    // } else {
    //     cout << "I don't know who I am." << endl;
    // }

    // 当Base没虚函数时候报错
    if (dynamic_cast<Dog*>(a)) {
        cout << "I'm a dog." << endl;
    } else if (dynamic_cast<Cat*>(a)) {
        cout << "I'm a cat." << endl;
    } else if (dynamic_cast<Mouse*>(a)) {
        cout << "I'm a mouse." << endl;
    } else {
        cout << "I don't know who I am." << endl;
    }
}
int main(){
    Animal* a[4]{new Dog(), new Cat(), new Mouse(), new Animal()};
    for (int i = 0; i < 4; i++) {
        whoAreYou(a[i]);
    }
    for (int i = 0; i < 4; i++) {
        delete a[i];
    }
}


// C++ 只允许拥有虚函数的类使用 RTTI
// 没有虚函数的时候，不会正确对应
