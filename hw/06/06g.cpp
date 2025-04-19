#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

template <typename T>
class OstreamIterator {
public:
    // C++17 规定的迭代器必须定义的类型别名
    // C++20 只需 value_type 和 difference_type
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::output_iterator_tag;
    OstreamIterator(const OstreamIterator&) = default;
    OstreamIterator& operator=(const OstreamIterator&) = default;

private:
// 在此处补充你的代码
    std::ostream* os;
public:
    OstreamIterator(std::ostream& _os) : os(&_os) {}

    OstreamIterator& operator*() {
        return *this;
        /// useless ???
    }

    OstreamIterator& operator++() {
        return *this;
    }

    OstreamIterator& operator=(const T val) {
        (*os) << val;
        return *this;
    }

    


};

int main() {
    std::string strArr[]{"Creeper", "? ", "Aw", " ", "man"};
    std::copy(std::begin(strArr), std::end(strArr), OstreamIterator<std::string>(std::cout));

    // 输出到 std::string 的流
    std::stringstream ss;
    std::vector<int> intVec{1, 2, 3, 4, 5};
    std::copy(intVec.begin(), intVec.end(), OstreamIterator<int>(ss));
    assert(ss.str() == "12345");
}