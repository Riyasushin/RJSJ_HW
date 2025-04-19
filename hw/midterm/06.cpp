

#include <iostream>
using std::cin, std::cout, std::endl;

class Duck {
  // 在此处补充你的代码
  // #include<variant>有一个比较优美的实现

  // 现在戴着枷锁跳舞
  // 评价是一样的吃屎
 private:
  enum class Type { Int, Char, Double };
  union Value {
    int i;
    char c;
    double d;
    Value() = default;
    ~Value() = default;
  };
  Value data;
  Type type;

 public:
  Duck(int x) : data{x}, type{Type::Int} {}
  Duck(char x) : data{x}, type{Type::Char} {}
  Duck(double x) : data{x}, type{Type::Double} {}

  Duck& operator=(int x) {
    data.i = x;
    type = Type::Int;
    return *this;
  }

  Duck& operator=(char x) {
    data.c = x;
    type = Type::Char;
    return *this;
  }

  Duck& operator=(double x) {
    data.d = x;
    type = Type::Double;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Duck& obj) {
    switch (obj.type) {
      case Type::Int:
        os << obj.data.i;
        break;
      case Type::Char:
        os << obj.data.c;
        break;
      case Type::Double:
        os << obj.data.d;
        break;
    }
    return os;
  }
  //
};

int main() {
  int i;
  char c;
  double d;
  cin >> i >> c >> d;
  Duck val1{i};
  Duck val2{c};
  Duck val3{d};
  cout << val1 << " " << val2 << " " << val3 << endl;
  val1 = d * 2;
  val2 = i * 2;
  val3 = (char)(c + 1);
  cout << val1 << " " << val2 << " " << val3 << endl;
  return 0;
}
