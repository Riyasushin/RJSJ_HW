#include <iostream>
#include <utility>
// 在此处补充你的代码
template<int N>
class Fibonacci {
public:
    constexpr static int value{Fibonacci<N-1>::value + Fibonacci<N - 2>::value};
};

template<>
class Fibonacci<0> {
public:
    constexpr static int value{0};
};

template<>
class Fibonacci<1> {
public:
    constexpr static int value{1};
};






int main() {
    const int f[6]{
        Fibonacci<1>::value,
        Fibonacci<2>::value,
        Fibonacci<3>::value,
        Fibonacci<4>::value,
        Fibonacci<5>::value,
        Fibonacci<6>::value,
    };
    for (int i = 0; i < 6; i++) {
        std::cout << f[i] << " ";
    }
    // 静态断言：编译器检查条件是否成立。不成立时引发编译错误
    static_assert(Fibonacci<30>::value == 832040);
}

// 检查斐波那契数列前三十项的和是否正确
template<std::size_t... Ns>
constexpr int check(std::index_sequence<Ns...>) {
   return (0 + ... + Fibonacci<Ns>::value);
}
static_assert(check(std::make_index_sequence<30>{}) == 1346268);
