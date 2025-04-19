#include <iostream>

class Magic {
public:
    int value;
    Magic() {}
    Magic(int x): value{x} {}
    Magic(const Magic& m): value{m.value + 2} {}
};

void print(Magic o) {
    std::cout << o.value << std::endl;
}

int main() {
    Magic a(5);
    Magic b = a;
    print(b);

    Magic d;
    d = a;
    std::cout << d.value << std::endl;
    print(d);
}

/*
什么时候复制初始化
什么时候复制赋值
*/
