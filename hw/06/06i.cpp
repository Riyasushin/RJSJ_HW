#include <iostream>
#include <vector>
#include <cmath>
// 在此处补充你的代码

template<typename... Ts>
std::vector<double> makeSqrtVec(Ts... args) {
    
    return std::vector<double>{ sqrt(args)... };

}

int main() {
    for (auto i : makeSqrtVec(1, 4, 9, 16, 25)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (auto i : makeSqrtVec(8, 7, 6)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (auto i : makeSqrtVec()) {
        std::cout << i << " ";
    }
}