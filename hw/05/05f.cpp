#include <iostream>
#include <iomanip>
#include <cmath>

constexpr double DX = 1e-6;
// 在此处补充你的代码
// auto d = [](auto f) {
//     return [f](double x) {
//         return (f(x + DX) - f(x)) / DX;
//     };
// };
template <typename Func>
auto d(Func f) {
    return [f](double x) {
        return (f(x + DX) - f(x)) / DX;
    };
}

int main() {
    auto f = [&] (double x) { return x * x; };
    auto g = [=] (double x) { return std::sin(x); };

    double x;
    std::cout << std::fixed << std::setprecision(2);
    while (std::cin >> x) {
        std::cout << d(f)(x) << ' ';
        std::cout << d(g)(x) << std::endl;
    }
}

/*
### 错误分析

你提供的模板函数定义如下：

```cpp
template <typename Func, typename Ret>
Ret d(Func f) {
    return [f](double x) {
        return (f(x + DX) - f(x)) / DX;
    };
}
```

这段代码会报错，主要原因如下：

1. **返回类型不匹配**：
   - 函数的返回类型声明为 `Ret`，但实际返回的是一个 **lambda 表达式**（闭包类型），而 `Ret` 并未指定为 lambda 的类型。
   - Lambda 表达式的类型是编译器生成的唯一闭包类型，无法直接用 `Ret` 表示。

2. **`Ret` 未正确推导**：
   - `Ret` 是模板参数，但调用 `d(f)` 时，编译器无法推导 `Ret` 应该是什么类型，因为 lambda 的类型是匿名的。

3. **lambda 不能隐式转换为 `Ret`**：
   - 除非 `Ret` 是 `std::function` 或兼容的可调用对象类型，否则无法直接将 lambda 赋值给 `Ret`。

---

### 正确的模板实现方式

#### 方法 1：使用 `auto` 返回类型（C++14 起支持）
最直接的方法是让编译器自动推导返回类型：

```cpp
template <typename Func>
auto d(Func f) {
    return [f](double x) {
        return (f(x + DX) - f(x)) / DX;
    };
}
```
**优点**：
- 简单直接，无需手动指定返回类型。
- 适用于任何可调用对象（lambda、函数指针、函数对象等）。

---

#### 方法 2：使用 `std::function` 显式指定返回类型
如果希望显式指定返回类型（例如为了接口清晰），可以使用 `std::function`：

```cpp
#include <functional>

template <typename Func>
std::function<double(double)> d(Func f) {
    return [f](double x) {
        return (f(x + DX) - f(x)) / DX;
    };
}
```
**优点**：
- 明确表明 `d(f)` 返回一个 `double(double)` 类型的函数。
- 兼容性更好（C++11 起支持）。

**缺点**：
- `std::function` 可能有轻微的性能开销（类型擦除）。

---

#### 方法 3：使用 C++20 的 `auto` 模板参数（更通用）
如果你用 C++20，可以进一步泛化输入和返回类型：

```cpp
template <typename Func>
auto d(Func f) {
    return [f](auto x) {  // C++14 泛型 lambda
        return (f(x + DX) - f(x)) / DX;
    };
}
```
**优点**：
- 支持任意 `x` 类型（不限于 `double`）。
- 更通用，但可能增加编译时间。

---

### 为什么你的代码会报错？
- **错误示例**：
  ```cpp
  template <typename Func, typename Ret>
  Ret d(Func f) {
      return [f](double x) { return (f(x + DX) - f(x)) / DX; };
  }
  ```
- **问题**：
  1. `Ret` 未指定，编译器无法推导。
  2. 即使显式调用 `d<Func, SomeType>(f)`，`SomeType` 也必须能匹配 lambda 的类型（但 lambda 的类型是唯一的，无法直接指定）。
  3. Lambda 不能隐式转换为任意 `Ret`（除非 `Ret` 是兼容的可调用对象，如 `std::function`）。

---

### 修复后的代码（推荐方法 1）
```cpp
#include <iostream>
#include <iomanip>
#include <cmath>

constexpr double DX = 1e-6;

template <typename Func>
auto d(Func f) {
    return [f](double x) {
        return (f(x + DX) - f(x)) / DX;
    };
}

int main() {
    auto f = [](double x) { return x * x; };
    auto g = [](double x) { return std::sin(x); };

    double x;
    std::cout << std::fixed << std::setprecision(2);
    while (std::cin >> x) {
        std::cout << d(f)(x) << ' ';
        std::cout << d(g)(x) << std::endl;
    }
}
```

### 关键点总结
1. **Lambda 表达式是匿名类型**，不能直接用模板参数 `Ret` 表示。
2. **`auto` 返回值** 是解决此问题的最简单方法（C++14 起支持）。
3. 如果必须显式指定类型，可以用 `std::function`，但会引入额外开销。
4. 你的原始代码试图用 `Ret` 指定返回类型，但未提供匹配 lambda 的类型，导致编译失败。

希望这个解释能帮到你！
*/
