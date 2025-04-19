#include <iostream>

struct Complex {
    double real;
    double imag;
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    return os << c.real << '+' << c.imag << 'i';
}
Complex operator""_i(unsigned long long s) {
    return Complex{0, double(s)};
}

Complex operator""_i(long double s) {
    return Complex{0, double(s)};
}
int main() {
    std::cout << 5_i << std::endl;
    std::cout << 3.14_i << std::endl; 
}

/*
字面量！！！
*/
