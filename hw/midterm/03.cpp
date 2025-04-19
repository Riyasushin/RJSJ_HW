
#include <iostream>
using std::cin, std::cout, std::endl;

// 我的实现和LLM相同，考察的是函数指针，还好不是参数类型会变化的
using Func = int&(int&);

int& g(int& a) {
  a += 1;
  return a;
}

int& func(int& a) {
  a = a * 2 + 1;
  return a;
}
void double_operate(int& a, Func* f = g) { f(f(a)); }

int main() {
  int a;
  cin >> a;
  double_operate(a, func);
  cout << a << endl;

  double_operate(a);
  cout << a << endl;
}
