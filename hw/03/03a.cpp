#include <iostream>

class Point {
    int x, y;

public:
    Point() = default;
    Point(int x, int y) : x{x}, y{y} {}

    friend std::istream& operator>>(std::istream& in, Point& p) {
        return in >> p.x >> p.y;
    }
    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        return out << p.x << ' ' << p.y;
    }
};

int main() {
    Point p;
    while (std::cin >> p) {
        std::cout << p << std::endl;
    }
}

/*
流运算符的重载
*/
