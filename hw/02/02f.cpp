#include <iostream>

class Alef {
public:
    int value;
    Alef(int value) : value{value} {}
    Alef(const Alef& a) : value{a.value + 1} {}
};

class Bet {
public:
    Alef alef;
    int value;
    Bet(int value) : alef(value), value{value} {}
};

int main() {
    int n;
    while (std::cin >> n) {
        Bet a1(n);
        Bet a2 = a1;
        std::cout << a1.value << "," << a1.alef.value << "," 
            << a2.value << "," << a2.alef.value << std::endl;
    }
}

/*
为什么？
复制初始化
赋值
*/
