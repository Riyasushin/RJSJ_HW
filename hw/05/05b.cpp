#include <iostream>
#include <cmath>
// 在此处补充你的代码
template<typename T, int N>
class Array {
private:
    T vals[N]{};
public:
    T& operator[](int index) {
        // assert(index >= 0 && index < N); // 确保索引在合法范围内
        return vals[index];
    }

    const T& operator[](int index) const {
        // assert(index >= 0 && index < N); // 确保索引在合法范围内
        return vals[index];
    }
};

int main() {
    Array<int, 10> arrInt;
    static_assert(sizeof(arrInt) == sizeof(int) * 10);

    Array<double, 4> arrDbl;
    static_assert(sizeof(arrDbl) == sizeof(double) * 4);

    for (int i = 0; i < 4; i++) {
        arrInt[i] = i;
        arrDbl[i] = std::sqrt(i);
    }
    const auto arrInt2 = arrInt;
    for (int i = 0; i < 10; i++) {
        std::cout << arrInt2[i] << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << arrDbl[i] << ' ';
    }
}