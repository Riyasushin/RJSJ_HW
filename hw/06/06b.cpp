#include <iostream>
#include <list>
#include <vector>
// 在此处补充你的代码
/// 自己实现Accumulate累加算法
template <typename It>  /// TODO 20
typename std::iterator_traits<It>::value_type accumulate(It begin, It end) {
  using Type = typename std::iterator_traits<It>::value_type;

  Type res{};
  for (; begin != end; ++begin) {
    res = res + *begin;
  }

  return res;
}
//
struct Rational {
  int num;
  int den;
  Rational(int n = 0, int d = 1) : num{n}, den{d} {}
  friend Rational operator+(const Rational& lhs, const Rational& rhs) {
    return {lhs.num * rhs.den + lhs.den * rhs.num, lhs.den * rhs.den};
  }
  friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
    return os << r.num << '/' << r.den;
  }
};

int main() {
  std::string strArr[]{"Hello", "World", "From", "STL"};
  int intArr[]{1, 2, 3, 4, 5};
  std::vector<double> dblVec{1.414, 1.732, 2.236};
  std::list<Rational> ratList{{1, 2}, {1, 3}, {1, 5}};

  std::cout << accumulate(strArr, strArr + 4) << std::endl;
  std::cout << accumulate(intArr, intArr + 5) << std::endl;
  std::cout << accumulate(intArr, intArr) << std::endl;
  std::cout << accumulate(dblVec.begin(), dblVec.end()) << std::endl;
  std::cout << accumulate(ratList.begin(), ratList.end()) << std::endl;
}