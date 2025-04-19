/*

顺序容器
元素并非排序的，元素的插入位置同元素的值无关，元素的顺序可以被控制
vector
deque
list

.front
.back
.push_back
.pop_back

*/

#include <iostream>
#include <vector>
using std::vector, std::cout, std::endl;
/// 用std::vector实现二维数组
void funcName()
{
    vector<vector<int>> v(3);
    // v有3个元素，每个元素都是vector<int>容器
    for (int i = 0; i < v.size(); ++i)
        for (int j = 0; j < 4; ++j)
            v[i].push_back(j);
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

/// std::deque与std::vector很像，也是一个长度可变的数组
/// 比std::vector多提供了两个成员函数push_front 和pop_front，即从头部插入或删除元素
/// std::deque 的元素访问（即 operator[]）稍慢于 std::vector
#include <deque>
void funcName2()
{
    std::deque<int> a{1, 2, 3};
    a.push_back(4);  // 现在 a 是 {1, 2, 3, 4}
    a.pop_front();   // 现在 a 是 {2, 3, 4}
    a.pop_back();    // 现在 a 是 {2, 3}
    a.push_front(5); // 现在 a 是 {5, 2, 3}
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " "; // 遍历
    }
}

/*
双向链表
➢在任何位置插入删除都是常数时间
➢不支持随机存取（即不能使用[ ]运算符）
➢除了具有所有顺序容器都有的成员函数以外，还支持8个
成员函数
• push_front: 在头部插入
• pop_front: 删除头部的元素
• sort: 排序（list不支持STL的算法sort）
• remove: 删除和指定值相等的所有元素
• unique: 删除所有和前一个元素相同的元素
• merge: 合并两个链表, 并清空被合并的那个
• reverse: 颠倒链表
• splice: 在指定位置前面插入另一链表中的一个或多个元素，并在
另一链表中删除被插入的元素
*/
#include <list>
std::ostream &operator<<(std::ostream &ostr, const std::list<int> &list)
{
    for (auto &i : list)
        ostr << ' ' << i;

    return ostr;
}
/// @brief splice
void funcName3()
{
    std::list<int> list1{1, 2, 3, 4, 5};
    std::list<int> list2{10, 20, 30, 40, 50};

    auto it = list1.begin();
    std::advance(it, 2);

    list1.splice(it, list2);

    std::cout << "list1:" << list1 << '\n';
    std::cout << "list2:" << list2 << '\n';

    list2.splice(list2.begin(), list1, it, list1.end());

    std::cout << "list1:" << list1 << '\n';
    std::cout << "list2:" << list2 << '\n';
}

////////////////////////////////////////////

/*
迭代器的种类
均++p, p++

1. 输入迭代器：Input iterators 提供对数据的只读访问
*p读取
1. 输出迭代器：Output iterators 提供对数据的只写访问
*p修改

2. 前向迭代器：Forward iterators 提供读写操作，并能一次一个地向前推进迭代器
p == q, p != q

3. 双向迭代器：Bidirectional iterators 提供读写操作，并能一次一个地向前和向后移动
p--, --p

4. 随机访问迭代器：Random access iterators 提供读写操作，并能在数据中随机移动
+= i, -= i;
p > q, p <= q;
p[i]: p后第i个

5. 连续迭代器：Contiguous iterator提供读写操作，并能在数据中随机移动，相邻的容器元素在内存中物理相邻
p - q 为指向元素的地址差
*/

/*
不同容器所支持的迭代器种类
数组             连续
vector          连续
deque           随机访问
list            双向
set/multiset    双向
map/multimap    双向
forward_list    前向
stack           不支持
queue           不支持
priority_queue  不支持
*/

/// @brief std::vector的迭代器
void funcName4()
{
    vector<int> v(100); // 包含100个元素的vector
    int i;
    for (i = 0; i < v.size(); i++)
        cout << v[i]; // 根据下标随机访问
    vector<int>::const_iterator ii;
    for (ii = v.begin(); ii != v.end(); ++ii)
        cout << *ii;
    for (ii = v.begin(); ii < v.end(); ++ii)
        cout << *ii;
    // 间隔一个输出
    ii = v.begin();
    while (ii < v.end())
    {
        cout << *ii;
        ii = ii + 2;
    }
}

/// @brief std::list的迭代器
void funcName5()
{
    std::list<int> v;
    std::list<int>::const_iterator ii;
    for (ii = v.begin(); ii != v.end(); ++ii)
        cout << *ii;
    /// 双向迭代器不支持<
    /// list 不支持[]
}

/// iterator insert(const_iterator pos, const T& value);
/// 如果pos指向了第n个元素，那么调用insert成员函数之后，就会将value这个值插入在第n个元素之前

/// iterator erase(const_iterator pos);
/// 参数 pos 是指向要被删除的元素的迭代器

/// 不要在基于范围的for循环中增删元素，因为其中用到的迭代器是循环之前得到的
void funcName6()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    for (auto it = vec.begin(); it != vec.end();)
    {
        if (*it % 2 == 0)
        {                       // 如果是偶数就删除
            it = vec.erase(it); // erase 返回下一个有效的迭代器
        }
        else
        {
            ++it;
        }
    }

    for (int v : vec)
    {
        std::cout << v << " ";
    }

    /// 如果需要删除多个元素
    /// 建议使用std::remove或std::remove_if与erase的组合
    /// 这样代码更简洁且效率更高。
}

/////////////////////////////////////////////////////

/// 大多数定义在<algorithm>和<numeric>头文件中
/// **掌握查阅CppReference使用STL算法的能力**

/// std::copy()
/// std::back_inserter: r函数可以用于向顺序容器的尾部插入元素
#include <iterator> // std::back_inserter 定义于此
void funcName8()
{
    vector a{1, 3, 5, 7, 9};
    vector<int> b{2, 4};
    copy(a.begin(), a.end(), back_inserter(b)); // 复制时向 b 插入元素
    // 1 3 5 7 9
    for (int i : b)
    {
        cout << i << ' ';
    }
}

/// std::sort
#include <algorithm>
void funcName9()
{
    vector a{4, 1, 6, 2};
    sort(a.begin(), a.end(), std::greater<int>());
    /// greater是一个重载了( )运算符的类模板
    for (auto i : a)
    {
        cout << i << ' ';
    }
    cout << '\n';

    sort(a.begin(), a.end(), [](const int a, const int b)
         { return (a % 2 == 0); });
    for (auto i : a)
    {
        cout << i << ' ';
    }
}
/*
sort 基于元素的交换排序，
如果pr(a, b)为true
则将 a 排到 b 前面。
当不停地交换到任意两个元素a和b都符合pr(a,b)为true时，
整个序列就排好了
*/

/// STL 的<functional> 里提供了常用的函数对象类模板
/*
算数类型
- plus<T> //加法
- minus<T> //减法
- multiplies<T> //乘法
- divides<T> //除法
- modulus<T> //取模
- negate<T> //取反
关系类型
- equal_to<T> //等于
- not_equal_to<T> //不等于
- greater<T> //大于
- greater_equal<T> //大于等于
- less<T> //小于
- less_equal<T> //小于等于
逻辑类型
- logical_and<T> //逻辑与
- logical_or<T> //逻辑或
- logical_not<T> //逻辑非
*/

/// std::copy_if
void funcName10()
{
    vector<int> a{4, 1, 6, 2, 9, 5};
    vector<int> b;
    copy_if(a.begin(), a.end(), back_inserter(b), [](int x)
            { return x < 5; });
    for (auto i : b)
    {
        cout << i << ' ';
    }
}
#include <ranges>
void funcName10_2()
{
    auto even = [](int i)
    { return 0 == i % 2; };
    auto square = [](int i)
    { return i * i; };

    for (int i : std::views::iota(0, 6) | std::views::filter(even) | std::views::transform(square))
        std::cout << i << ' ';
    std::cout << '\n';
}

/// std::transform
#include <cmath>
void funcName11()
{
    // 输入
    vector<int> a;
    int x;
    while (std::cin >> x)
    {
        a.push_back(x);
    }
    // 筛选出正数
    vector<int> b;
    copy_if(a.begin(), a.end(), back_inserter(b), [](int x)
            { return x > 0; });
    // 取前 5 个
    if (b.size() > 5)
    {
        b.resize(5);
    }
    // 取平方根
    vector<double> c;
    /// 对[first,last) 中的每个迭代器i , 执行uop(*i) ; 并将结果依次放入从x开始的地方 **HERE**
    transform(b.begin(), b.end(), back_inserter(c), [](int x)
              { return sqrt(x); });
    // 输出
    for (const auto& i : c)
    {
        cout << i << ' ';
    }
}
void funcName11_2() {
    // 输入
    std::vector<int> a;
    int x;
    while (std::cin >> x) {
        a.push_back(x);
    }

    // 筛选出正数并取前5个
    auto positive_view = a | std::views::filter([](int x) { return x > 0; }) | std::views::take(5);

    // 取平方根
    std::vector<double> c;
    std::ranges::transform(positive_view, std::back_inserter(c), [](int x) { return std::sqrt(x); });

    // 输出
    for (const auto& i : c) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

/// std::accumulate
#include <numeric> // accmulmate不定义在<algorithm>

void funcName12() {
    vector a{1, 2, 3, 4, 5, 6};

    /// 初始值是 0，二元函数是 (a, b) -> a + b
    /// 对 [first,last) 中的每个迭代器 i , 执行 val = pr(val, *i) , 返回最终的 val
    auto sum = accumulate(a.begin(), a.end(), 0, std::plus<int>());
    cout << sum << endl;
}


/*
STL的算法大致可以划分为七类
➢不变序列算法：此类算法不会修改算法所作用的容器或对象，适用于所有容器，它们的时间复杂度都是O(n)
➢变值算法：此类算法会修改源区间或目标区间元素的值。值被修改的那个区间，不可以是属于关联容器的
➢删除算法：删除一个容器里的某些元素
➢变序算法：改变容器中元素的顺序，但是不改变元素的值。不适用于关联容器。此类算法复杂度都是O(n)
➢排序算法：算法复杂度一般是O(n×log(n))。需要随机访问迭代器的支持，因而不适用于关联容器和list
➢有序区间算法：要求所操作的区间是已经从小到大排好序的，而且需要随机访问迭代器的支持
➢数值算法：进行各类数值运算
*/

int main()
{

    funcName11();
    // std::cout << __cplusplus << std::endl;
    return 0;
}
