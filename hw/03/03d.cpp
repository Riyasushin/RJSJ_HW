#include <iostream>
#include <cstring>

class String {
    char* _data;
    int _size;

public:
    int size() const;
    String();
    String(const char* str);
    // 本题不涉及拷贝和赋值
    String(const String& str) = delete;
    String& operator=(const String& str) = delete;
    ~String() {
        delete[] _data;
    }

    friend bool operator==(const String& lhs, const String& rhs);
};

int String::size() const {
    return _size;
}
String::String() : _data{new char[1]{}}, _size{} {}
String::String(const char* str) : _size{strlen(str)} {
    _data = new char[_size + 1];
    std::strcpy(_data, str);
}

bool operator==(const String& lhs, const String& rhs) {
    return std::strcmp(lhs._data, rhs._data) == 0;
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

int main() {
    char origin[200], copy[200], other[200];
    std::cin >> origin >> other;
    std::strcpy(copy, origin);

    String s1(origin), s3(other);
    const String s2(copy), empty, fixed("string");

    std::cout << std::boolalpha;
    std::cout << (s1 == s2) << " " << (s1.size() == s2.size()) << std::endl;
    std::cout << (s1 == s3) << " " << (s1.size() == s3.size()) << std::endl;
    std::cout << (s1 != empty) << " " << (s1.size() != 0) << std::endl;
    std::cout << (s1 == fixed) << std::endl;
    std::cout << (empty == "") << " " << (empty.size() == 0) << std::endl;
    std::cout << (fixed == "string") << " " << (fixed.size() == 6) << std::endl;
    std::cout << ("" != empty) << " " << ("" == fixed) << std::endl;
}

/*
利用已重载的 == 运算符重载 != 运算符，增强可扩展性。
*/
