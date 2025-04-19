#include <iostream>

class IntVector {
    static constexpr int capacity{256};
    int len{0};
    int data[IntVector::capacity];

public:
    IntVector() = default;
    IntVector(const IntVector&) = default;
    void pushBack(int e) {
        data[len++] = e;
    }
    int at(int i) {
        return data[i];
    }
    int size() {
        return len;
    }
};

struct Adder {
    IntVector& src;
};

Adder operator+=(IntVector& v, int e) {
    v.pushBack(e);
    return Adder{v};
}
Adder operator,(Adder v, int e) {
    v.src.pushBack(e);
    return v;
}

int main() {
    IntVector v;
    v += 1, 2, 3;

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;

    int x, y;
    std::cin >> x >> y;
    v += x, 5, 6, 7, y;
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;

    // 先将 v 清空，然后检查 v.size() 是否为 0
    if (v = {}, v.size()) {
        std::cout << "Unreachable" << std::endl;
    }
}

/*
+=重载成代理类
只有左边是+=时候回,,,,,,,,,
*/
