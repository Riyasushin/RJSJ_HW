#include <iostream>
#include <algorithm>
using std::cin, std::cout, std::endl;
class Point {
private:
    int x, y;
public:
    Point(): x{0}, y{0} {}
    friend std::istream& operator>>(std::istream& is, Point& p) {
        return is >> p.x >> p.y;
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << p.x << ' ' << p.y;
    }
// 在此处补充你的代码
    bool operator<(const Point& oth) const {
        if (x * x + y * y == oth.x * oth.x + oth.y * oth.y) {
            return (x < oth.x) || (x == oth.x && y < oth.y);
        } else {
            return x * x + y * y < oth.x * oth.x + oth.y * oth.y;
        }
    }
    bool operator==(const Point& oth) const {
        return (x == oth.x && y == oth.y);
    }
    bool operator>(const Point& oth) const {
        if (*this == oth) {
            return false;
        }
        return !(*this < oth);
    }
};
int main() {
    int n;
    cin >> n;
    Point* points = new Point[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    std::sort(points, points + n);
    for (int i = 0; i < n; i++) {
        cout << points[i] << endl;
    }
    std::sort(points, points + n, std::greater());
    for (int i = 0; i < n; i++) {
        cout << points[i] << endl;
    }
    delete[] points;
}