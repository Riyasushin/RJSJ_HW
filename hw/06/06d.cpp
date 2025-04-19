#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
using std::cout, std::endl;
template <typename Container>
class MultBackInsertIter {
private:
    Container* c;
public:
    // C++17 规定的迭代器必须定义的类型别名
    // C++20 只需 value_type 和 difference_type
    using value_type = typename Container::value_type;
    using reference = value_type&;
    using pointer = value_type*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::output_iterator_tag;
// 在此处补充你的代码
    MultBackInsertIter& operator*() {
        return *this;
    }

    MultBackInsertIter& operator++(){
        return *this;
        /// useless
    }

    MultBackInsertIter& operator=(const value_type& oth) {
        c->push_back(oth * 2);
        return *this;
    }

    MultBackInsertIter(Container& b) : c(&b) {}

    
//
};
template <typename T>
void print(const T& c) {
    for (auto i: c) { cout << i << ' '; }
    cout << endl;
}
int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::deque<int> d{8, 9};
    std::list<int> l{10, 11};
    std::copy(v.begin(), v.end(), MultBackInsertIter(d));
    std::copy(v.begin(), v.end(), MultBackInsertIter(l));
    print(d);
    print(l);
}