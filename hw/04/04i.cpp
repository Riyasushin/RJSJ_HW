#include <iostream>

struct Point {
    int x, y, z;
    /// @brief 用移动成员指针，怎么写
    /// @param direction 
    /// @param delta 
    void translate(int Point::*direction, int delta) {
        this->*direction += delta;
    }
//
    void print() {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main() {
    Point p{};

    char c;
    int x;
    while (std::cin >> c >> x) {
        int Point::*dir = nullptr;
        switch (c) {
            case 'x': dir = &Point::x; break;
            case 'y': dir = &Point::y; break;
            case 'z': dir = &Point::z; break;
        }
        p.translate(dir, x);
        p.print();
    }
}


// 数据成员指针
// 是偏移量
