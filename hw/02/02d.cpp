#include <iostream>
using std::cin, std::cout, std::endl;
class Sample {
public:
    mutable int val;
    Sample(int x) : val{x} {}
    int GetValue() const {
        return val;
    }
    void SetValue(int x) const{
        val = x;
    }
};
int main() {
    int x, y;
    cin >> x >> y;
    const Sample s(x);
    cout << s.GetValue() << endl;
    s.SetValue(y);
    cout << s.GetValue() << endl;
}

/*
本题考察 mutable 关键词的使用。
用 const 修饰的只读对象只能调用用 const 修饰的只读成员函数，只读成员函数只能修改用 mutable 关键词修饰的成员变量。

*/
