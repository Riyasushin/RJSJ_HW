#include <iostream>
using std::cin, std::cout, std::endl;
// 在此处补充你的代码

// 完全不会类型擦除和指针转换和回调函数
// 但是都见过，都写过

#include <functional>

template <typename T>
class EntangledPair {
 private:
  T elem_;
  std::function<void()> unbindCallback;  // 类型擦除的解绑回调

 public:
  EntangledPair() = default;
  explicit EntangledPair(const T& val) : elem_(val) {}

  template <typename U>
  friend class EntangledPair;

  template <typename U>
  void bind(EntangledPair<U>& other) {
    // 设置相互更新逻辑
    auto updateOther = [&](const T& val) { other.elem_ = static_cast<U>(val); };
    auto updateThis = [&](const U& val) { elem_ = static_cast<T>(val); };

    // 设置解绑回调
    unbindCallback = [&]() {
      other.unbindCallback = nullptr;
      other.updatePartner = nullptr;
    };
    other.unbindCallback = [this]() {
      unbindCallback = nullptr;
      updatePartner = nullptr;
    };

    // 设置赋值更新函数
    updatePartner = updateOther;
    other.updatePartner = updateThis;
  }

  void unbind() {
    if (unbindCallback) {
      unbindCallback();  // 触发对方解绑
      unbindCallback = nullptr;
      updatePartner = nullptr;
    }
  }

  // 通用赋值运算符
  template <typename U>
  EntangledPair& operator=(const U& val) {
    elem_ = static_cast<T>(val);
    if (updatePartner) {
      updatePartner(elem_);  // 通过类型擦除函数更新对方
    }
    return *this;
  }

  // 同类型赋值特化
  EntangledPair& operator=(const T& val) {
    elem_ = val;
    if (updatePartner) {
      updatePartner(elem_);
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const EntangledPair& obj) {
    os << obj.elem_;
    return os;
  }

 private:
  std::function<void(const T&)> updatePartner;  // 类型擦除的更新函数
};

//

// TestCase 类用于生成测试用例，你无需关注其具体实现。
class TestCase {
  class A {
    int elem_;

   public:
    A(int elem = 0) : elem_{elem} {}
    operator int() const { return elem_; };
  };

  class B {
    int elem_;

   public:
    B(int elem = 0) : elem_{elem} {}
    operator int() const { return elem_; };
  };

 public:
  static void Test(EntangledPair<double>& b, int t2);
  static void Test2(int t3, int t4);
};

// main 函数代码需要阅读
int main() {
  EntangledPair<int> a;
  EntangledPair<double> b;

  a.bind(b);

  int t1, t2, t3, t4;
  double d1, d2;
  cin >> t1 >> t2 >> t3 >> t4 >> d1 >> d2;

  a = t1;
  cout << a << " " << b << endl;

  b = d1;
  cout << a << " " << b << endl;

  a.unbind();
  b = d2;
  cout << a << " " << b << endl;

  TestCase::Test(b, t2);
  TestCase::Test2(t3, t4);

  return 0;
}

// 以下为测试用例生成，无需关注。
void TestCase::Test(EntangledPair<double>& b, int t2) {
  EntangledPair<A> c;
  b.bind(c);
  b = A{t2};
  cout << b << " " << c << endl;
  return;
}

void TestCase::Test2(int t3, int t4) {
  EntangledPair<A> a;
  EntangledPair<B> b;

  b.bind(a);
  b = t3;
  cout << a << " " << b << endl;

  b.unbind();
  a = t4;
  cout << a << " " << b << endl;
  return;
}
