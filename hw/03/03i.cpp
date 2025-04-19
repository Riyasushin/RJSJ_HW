#include <iostream>
using std::cout, std::endl;
class A{
public:
    int val;
    A(int x): val(x){}
    friend std::ostream& operator<<(std::ostream &os, const A &a){
        return os << a.val;
    }
};
void f(int& t){
    cout << "lvalue: " << t << endl;
}
void f(double& t){
    cout << "lvalue: " << t << endl;
}
void f(A& t){
    cout << "lvalue: " << t << endl;
}
void f(int&& t){
    cout << "rvalue: " << t << endl;
}
void f(double&& t){
    cout << "rvalue: " << t << endl;
}
void f(A&& t){
    cout << "rvalue: " << t << endl;
}
int main(){
    int x = 1;
    int* p = &x;
    int&& y = 2;
    A a(2);
    f(x);
    f(1);
    f(x + 0.5);
    f(x++);
    f(++x);
    f(*p);
    f(y);
    f(a);
    f(A(5));
    f(a.val);
    f(A(x));
    f(x = 5);
    f((x, 2));
    f((2, x));
}

/*
左值
右值
*/
