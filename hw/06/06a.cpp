#include <deque>
#include <forward_list>
#include <iostream>
// 在此处补充你的代码
template <typename It, typename F>
void forEach(It begin, It end, F f) {
  for (It iter = begin; iter != end; ++iter) {
    f(*iter);
  }
}
//

int main() {
  std::forward_list<int> fl = {1, 2, 3, 4, 5, 6};
  std::deque<int> d;
  auto printInt = [](int i) { std::cout << i << " "; };

  forEach(fl.begin(), fl.end(), [&](int i) { d.push_back(i); });
  forEach(d.begin(), d.end(), printInt);
  std::cout << std::endl;

  int odds[]{1, 3, 5};
  forEach(odds, odds + 3, [&](int i) { d[i] *= 2; });
  forEach(d.begin(), d.end(), printInt);
}