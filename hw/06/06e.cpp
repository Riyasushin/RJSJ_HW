#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
// 在此处补充你的代码
template <typename Container, typename T>
bool includes(Container cont, T val) {
  return std::find(cont.begin(), cont.end(), val) != cont.end();
}

template <typename Key, typename Value>
bool includes(const std::unordered_map<Key, Value>& cont, const Key& val) {
  return cont.find(val) != cont.end();
}

//

int main() {
  std::string k;
  int v;
  std::unordered_map<std::string, int> map;
  for (int i{0}; i < 3; i++) {
    std::cin >> k >> v;
    map.insert({k, v});
  }

  std::vector<int> vec;
  for (int i{0}; i < 5; i++) {
    std::cin >> v;
    vec.push_back(v);
  }

  std::array<int, 5> arr;
  for (int i{0}; i < 5; i++) {
    std::cin >> v;
    arr[i] = v;
  }

  std::cin >> k;
  if (includes(map, k)) {
    std::cout << map[k] << std::endl;
  } else {
    std::cout << "None" << std::endl;
  }
  std::cin >> v;
  std::cout << std::boolalpha << includes(vec, v) << std::endl;
  std::cin >> v;
  std::cout << std::boolalpha << includes(arr, v) << std::endl;
}