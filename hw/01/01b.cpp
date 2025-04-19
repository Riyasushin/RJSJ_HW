#include <iostream>
#include <cmath>
using std::cin, std::cout, std::endl, std::sqrt;
//补全aver函数的定义
void aver(const int a, const int b, float &c, float &d){
    c = (a + b) / 2.0;
    d = sqrt(a * b);
}
int main(){
    int a, b;
    float c, d;
    cin >> a >> b;
    aver(a, b, c, d);
    cout << c << " " << d << endl;
}

/// 引用传参