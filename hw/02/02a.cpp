#include <iostream>
using std::cin, std::cout, std::endl;
class Sponge {
private:
    int l, w, h;
    int vol;
public:
    int volume() {
        return vol;
    }
    Sponge(int x, int y, int z): l{x}, w{y}, h{z}, vol{x * y * z} {}
    Sponge(const Sponge& s) = default;
    void expand(int dx, int dy, int dz) {
        l += dx;
        w += dy;
        h += dz;
        vol = l * w * h;
    }
};
int main() {
    int x, y, z;
    int dx, dy, dz;
    cin >> x >> y >> z;
    Sponge s1(x, y, z);
    Sponge s2{s1};
    cout << s1.volume() << endl;
    cin >> dx >> dy >> dz;
    s2.expand(dx, dy, dz);
    cout << s2.volume() - s1.volume() << endl;
}

/*
类的：构造函数，成员函数
*/
