#include <iostream>
// 在此处补充你的代码
template <typename Func>
/// 这里能够自动推倒
class PointerPrinter {
 private:
  Func f;

 public:
  PointerPrinter(Func x) : f(x) {}
  // Func 可能没有默认构造函数, 必须这样初始化，而非（默认初始化后）赋值

  template <typename T>
  PointerPrinter& operator<<(const T* ptr) {
    if (ptr == nullptr) {
      std::cout << f();
    } else {
      std::cout << *ptr;
    }

    return *this;
  }
};
//

int main() {
  int nNull = 0;
  PointerPrinter sayNull([]() { return "null"; });
  PointerPrinter countNull([&]() { return ++nNull; });

  double doubles[]{0.0, -1.0, 3.14};
  for (auto i : doubles) {
    sayNull << &i << &" ";
  }
  std::cout << std::endl;

  int* ints[6]{new int{42}, nullptr, new int{0}, new int{-1}};
  for (auto ptr : ints) {
    countNull << ptr << " ";
  }
  sayNull << &"\nints have " << &nNull << &" null pointers.\n";

  for (auto ptr : ints) {
    if (!ptr)
      sayNull << &ptr << " " << ptr << "\n";
    else
      delete ptr;
  }
}