#include <iostream>

class Foobar {
    static int totalNum;
public:
    Foobar() {
        totalNum++;
    }
    Foobar(const Foobar&) {
        totalNum++;
    }
    ~Foobar() {
        totalNum--;
    }
//
    static void printTotal() {
        std::cout << totalNum << std::endl;
    }
};
int Foobar::totalNum = 0;

void byRef(const Foobar& a) {
    a.printTotal();
}
void byVal(Foobar a) {
    a.printTotal();
}
void staticLocal() {
    static Foobar a, b, c = b;
}

int main() {
    Foobar(), Foobar::printTotal();
    Foobar x;
    x.printTotal();

    Foobar* p = new Foobar[3]{};
    byRef(p[1]);
    byVal(p[2]);

    delete[] p;
    Foobar::printTotal();
    staticLocal();
    Foobar::printTotal();
}

/*
生命周期
析构函数

复制构造函数别忘
复制构造函数与operator=的区别

*/
