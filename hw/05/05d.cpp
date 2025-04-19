#include <iostream>
// 在此处补充你的代码
template<typename F>
void call3(F f) {
    f();
    f();
    f();
}

void f1() {
    int x = 0;
    std::cout << ++x << std::endl;
}
void f2() {
    static int x = 0;
    std::cout << ++x << std::endl;
}
struct F34 {
    int x{0};
    void operator()() {
        std::cout << ++x << std::endl;
    }
};
F34 f3, f4;
int main() {
    int v = 42;
    auto f5 = [&]() {
        std::cout << ++v << std::endl;
    };
    call3(f1);
    call3(f2);
    call3(f3);
    call3(f4);
    call3(f5);
}
