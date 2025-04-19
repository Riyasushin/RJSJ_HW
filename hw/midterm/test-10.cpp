

/*
描述
MemberFactory 类是一个“工厂”模板类，可以通过 create
方法生成一个对象。这个对象的每个成员的值，则通过此前对“工厂”设置的一系列“初始化函数”给出。比如下面的代码中，f1
是构造 Xyz 的工厂，执行 f1.set(&Xyz::x, some_function); 则表明在通过
f1.create() 创建 Xyz 对象时，使用 some_function 的结果来设置 x 成员的值。

请补全 MemberFactory 的实现；传入工厂的类型保证是可默认构造的类。


输入
共一行，三个空格分隔的整数 x, y, z；随后是一个空格和一个字符串 s。
1≤x, y, z≤100，字符串长度不超过10。
输出
第一行：空格分隔的三个数 2, 6, 2.000000；
第二行：空格分隔的三个数 x * 2, y * 3, sqrt(z)；浮点数保留六位小数。
第三行：24，空格后接字符串 s。
样例输入
4 3 2 John
样例输出
2 6 2.000000
8 9 1.414214
24 John
提示
MemberFactory 内使用
std::vector<std::function<void(T&)>>保存所有创建对象时的行为。
你可能需要参考的Cppreference页面：
数据成员指针: reference/zh/cpp/language/pointer.html中的数据成员指针部分。
std::function: reference/zh/cpp/utility/functional/function.html。
*/
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
// 在此处补充你的代码

template <typename T>
class MemberFactory {
 private:
  std::vector<std::function<void(T&)>> initFuncs;

 public:
  MemberFactory() = default;

  // 当时完全没有学会这一步
  template <typename MemberType, typename Func>
  void set(MemberType T::* p, Func f) {
    auto ff = [p, f](T& obj) { obj.*p = f(); };
    initFuncs.push_back(ff);
  }

  T create() {
    T obj;
    for (auto initFunction : initFuncs) {
      initFunction(obj);
    }

    return obj;
  }
};

//

struct Xyz {
  int x, y;
  double z;
};

struct Student {
  int age;

  std::string name;
};

int main() {
  int x{1}, y{2}, z{4};
  std::string s;

  MemberFactory<Xyz> f1;
  f1.set(&Xyz::x, [&]() { return x * 2; });
  f1.set(&Xyz::y, [&]() { return y * 3; });
  f1.set(&Xyz::z, [&]() { return std::sqrt(z); });

  auto a = f1.create();
  std::cout << std::fixed << a.x << ' ' << a.y << ' ' << a.z << '\n';

  std::cin >> x >> y >> z >> s;
  auto b = f1.create();
  std::cout << std::fixed << b.x << ' ' << b.y << ' ' << b.z << '\n';

  MemberFactory<Student> f2;
  f2.set(&Student::age, [=]() { return 24ull; });
  f2.set(&Student::name, [=]() { return s; });

  auto student = f2.create();
  std::cout << student.age << ' ' << student.name << '\n';
}
