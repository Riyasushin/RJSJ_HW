#include <iostream>
// 在此处补充你的代码
class MyCin {
 private:
  std::istream& is;
  bool meetMinusOne;

  //   operator int() const = delete;
  //   operator long() const = delete;
  //   operator unsigned() const = delete;

  template <typename T>
  MyCin& operator<<(const T& val) = delete;

 public:
  MyCin& operator>>(int& n) {
    if (!meetMinusOne) {
      is >> n;
      if (n == -1) {
        meetMinusOne = true;
      }
    }
    return *this;
  }

  MyCin() : is(std::cin), meetMinusOne(false) {}

  /// while时候用来进行判断的
  /// 需要explicit，为什么？？？
  explicit operator bool() const { return !meetMinusOne; }
};

int main() {
  MyCin m;
  // m + 1;
  int n1, n2;
  while (m >> n1 >> n2) {
    std::cout << n1 << " " << n2 << std::endl;
  }
  // m << n1; // 编译错误
}

// 检查你是否正确解决了“m << n1 会通过编译”这个问题
template <typename, typename>
struct J : std::true_type {};
template <typename T>
struct J<T, std::void_t<decltype(std::declval<int&>() = std::declval<T&>())>>
    : std::false_type {};
static_assert(J<MyCin, void>::value);