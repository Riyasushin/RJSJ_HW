#include <iostream>
#include <random>
#include <cassert>

class Array2D {
    int* data;
    int w;

public:
    int& at(int x, int y) {
        return data[x * w + y];
    }
    
    Array2D(int h, int w)
        : w{w}, data{new int[h * w]{}} {}

    struct Array1D {
        Array2D* parent;
        int x;

        int& operator[](int y) {
            return parent->at(x, y);
        }
    };

    Array1D operator[](int x) {
        return Array1D{this, x};
    }

    ~Array2D() {
        delete[] data;
    }
};

// C++ 风格的随机数生成函数，不用深究
int rand() {
    static std::random_device rd;
    static std::default_random_engine e(rd());
    return int(e());
}

int main() {
    int h{3}, w{4};
    Array2D a(h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a.at(i, j) = rand();
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            // assert：如果条件不成立，则运行时错误
            assert(a.at(i, j) == a[i][j]);
        }
    }
}

/*
基于代理的二维数组
*/

