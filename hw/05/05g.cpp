#include <iostream>
#include <list>
#include <vector>
// 在此处补充你的代码
template<typename range, typename Filter>
int sumIf(range&& r, Filter f) { // ??? &&
    int res = 0;
    
    for (auto iter = std::begin(r); iter != std::end(r); ++iter) {
        if (f(*iter)) {
            res += *iter;
        }
    }

    return res;
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << sumIf(v, [](int i) { return i % 3 == 1; }) << std::endl;
    std::cout << sumIf(x, [](int i) { return i % 3 == 0; }) << std::endl;
    std::cout << sumIf(a, [](int i) { return i % 2 == 0; }) << std::endl;
    std::cout << sumIf(l, [](int i) { return i % 2 == 1; }) << std::endl;
}
