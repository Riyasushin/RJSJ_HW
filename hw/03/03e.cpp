#include <cstring>
#include <cstdio>
#include <iostream>
#include <utility>
using std::cin, std::cout, std::endl;

int add(const char *a, const char *b, char *dest);
int itoa(int a, char *dest);

class BigInt
{
    char *data{};

public:
    BigInt(int n = 0)
    {
        int size = itoa(n, nullptr);
        data = new char[size];
        itoa(n, data);
    }
    BigInt(const char *n)
    {
        int size = std::strlen(n) + 1;
        data = new char[size];
        std::strcpy(data, n);
    }
    BigInt(const BigInt &other) : BigInt(other.data) {}

    BigInt &operator=(BigInt rhs)
    {
        std::swap(this->data, rhs.data);
        return *this;
    }

    BigInt &operator+=(const BigInt &rhs)
    {
        return *this = *this + rhs;
    }

    BigInt &operator++()
    {
        return *this += 1;
    }
    BigInt operator++(int)
    {
        BigInt result = *this;
        ++*this;
        return result;
    }

    friend BigInt operator+(const BigInt &lhs, const BigInt &rhs)
    {
        int size = add(lhs.data, rhs.data, nullptr);
        char *data = new char[size];
        add(lhs.data, rhs.data, data);
        BigInt result(data);
        delete[] data;
        return result;
    }
    //
    ~BigInt()
    {
        delete[] data;
    }

    friend std::istream &operator>>(std::istream &in, BigInt &c);
    friend std::ostream &operator<<(std::ostream &out, const BigInt &c);
};

int main()
{
    BigInt a(0), b("0");
    int n;

    cin >> a >> n;
    a = ("0" + a);
    b = n;

    cout << a + b << endl;
    cout << n + a << endl;
    cout << a + n << endl;

    cout << ((b += n) += "10") << endl;
    cout << ++ ++b << endl;
    cout << b++ << endl;
    cout << b << endl;
}

// 以下是工具函数的实现，不用关心。

#include <algorithm>
#include <iterator>
#include <memory>
#include <string>

int add(const char *a, const char *b, char *d)
{
    int
        i = std::strlen(a),
        j = std::strlen(b), k{}, c{};
    auto
        r = std::make_unique<char[]>(std::max(i, j) + 1);
    auto f = [&](auto... a)
    {int s=(...+a);r[k++]=s%10+48,c=s/10; };
    while (i && j)
        f(a[--i] - 48, b[--j] - 48, c);
    while (i)
        f(a[--i] - 48, c);
    while (j)
        f(b[--j] - 48, c);
    if (c)
        r[k++] = c + 48;
    if (d)
        std::copy(&r[0], &r[k], std::reverse_iterator{d + k}), d[k] = 0;
    return k + 1;
}
int itoa(int a, char *dest) { return (dest ? sprintf(dest, "%d", a) : snprintf(nullptr, 0, "%d", a)) + 1; }
std::istream &operator>>(std::
                             istream &i,
                         BigInt &c)
{
    std::string s;
    i >> s;
    c = BigInt(s.c_str());
    return i;
}
std::ostream &operator<<(std::ostream &o, const BigInt &c) { return o << c.data; }


/*
operator没啥意思

给的工具函数的实现贼有意思

*/
