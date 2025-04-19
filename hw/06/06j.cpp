#include <iostream>
#include <string>
// 在此处补充你的代码

template<typename... Ts>
auto sum(Ts&&... args) {
    return ((... + args));
}

template<typename... Ts>
auto sumOfSquare(Ts... args) {
    return sum( (args * args)...   );
}

template<int... Ts>
class Sum {
public:
    static constexpr int value{ (... + Ts)};
    
};

int main() {
    std::cout << sum(6, 6, 6) << std::endl;
    std::cout << Sum<1, 2, 3, 4, 5>::value << std::endl;
    std::cout << sum(1, 4, 2, 8, 5, 7) << std::endl;
    std::cout << Sum<4, 3, 9, 9>::value << std::endl;
    std::cout << sum(std::string{}, "Hello", ", ", "world", '!') << std::endl;
    std::cout << sumOfSquare(3, 4, 12, 13) << std::endl;
}