
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using std::cin, std::cout, std::endl;
// 在此处补充你的代码

template <typename Iterator>
Iterator remove_repeating(Iterator begin, Iterator end) {
  // 当时忘记这个怎么写了
  using ValueType = typename std::iterator_traits<Iterator>::value_type;
  // 使用降序排序的set自动去重并排序
  std::sort(begin, end, std::greater<ValueType>());
  return std::unique(begin, end);
}

//
int main() {
  double arr1[]{3.2, 5.3, 11.2, 5.3, 11.2, 3.2, 4.4};
  auto pend1 = remove_repeating(std::begin(arr1), std::end(arr1));
  for (auto i = std::begin(arr1); i != pend1; ++i) {
    cout << *i << endl;
  }

  std::deque<std::string> arr2{"hello", "world",   "hi",
                               "world", "goodbye", "world"};
  auto pend2 = remove_repeating(std::begin(arr2), std::end(arr2));
  for (auto i = std::begin(arr2); i != pend2; ++i) {
    cout << *i << endl;
  }

  int n, tmp;
  std::vector<int> input;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    input.push_back(tmp);
  }

  auto pend_input = remove_repeating(input.begin(), input.end());
  for (auto i = input.begin(); i != pend_input; ++i) {
    cout << *i << endl;
  }
}
