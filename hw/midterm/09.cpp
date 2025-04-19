
#include <algorithm>
#include <cctype>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

using std::cin, std::cout, std::endl;

// check_valid()
// 输入:
//  input: string
// 输出:
//  true, 如果input中所有的{和}只以"{}"的形式出现
//  false, 其他情况
bool check_valid(const std::string& input);
// 在此处补充你的代码

// 考场上的实现，很丑陋的版本，极度臃肿的代码，CV恶心至极

class FormatOStreamMy {
 private:
  std::ostream& os;
  std::string format;
  std::string forout{};
  int pointer{0};
  bool ok{true};

 public:
  FormatOStreamMy(const std::string& formater, std::ostream& oo)
      : format(formater), os(oo) {
    if (!check_valid(formater)) {
      ok = false;
    }
  }
  FormatOStreamMy& operator<<(const std::string& str) {
    /// ...
    /// cout << endl << str << endl << endl;
    if (!ok) {
      return *this;
    }

    if (pointer < format.length()) {
      const int st = pointer;
      for (; pointer < format.length(); ++pointer) {
        if (format[pointer] == '{') {
          break;
        }
      }
      std::string out = format.substr(st, pointer - st);
      forout += out;
      if (format[pointer] == '{') {
        ///
        forout += str;

        pointer += 2;
      }
      std::string remain = format.substr(pointer);

      int i = 0;
      for (; i < remain.length(); ++i) {
        if (remain[i] == '{') {
          break;
        }
      }
      if (i == remain.length()) {
        forout += remain;
        pointer = format.length() + 2;
        os << forout;
      }
    }

    return *this;
  }

  FormatOStreamMy& operator<<(const char* str) {
    /// ...
    /// cout << endl << str << endl << endl;
    if (!ok) {
      return *this;
    }

    if (pointer < format.length()) {
      const int st = pointer;
      for (; pointer < format.length(); ++pointer) {
        if (format[pointer] == '{') {
          break;
        }
      }
      std::string out = format.substr(st, pointer - st);
      forout += out;
      if (format[pointer] == '{') {
        ///
        forout += str;

        pointer += 2;
      }
      std::string remain = format.substr(pointer);

      int i = 0;
      for (; i < remain.length(); ++i) {
        if (remain[i] == '{') {
          break;
        }
      }
      if (i == remain.length()) {
        forout += remain;
        pointer = format.length() + 2;
        os << forout;
      }
    }

    return *this;
  }

  template <typename T>
  FormatOStreamMy& operator<<(const T& val) {
    /// ...
    if (!ok) {
      return *this;
    }
    if (pointer < format.length()) {
      const int st = pointer;
      for (; pointer < format.length(); ++pointer) {
        if (format[pointer] == '{') {
          break;
        }
      }
      std::string out = format.substr(st, pointer - st);
      forout += out;
      if (format[pointer] == '{') {
        ///

        std::stringstream ss;
        ss << val;
        std::string typeToString{};
        ss >> typeToString;
        forout += typeToString;

        pointer += 2;
      }
      std::string remain = format.substr(pointer);

      int i = 0;
      for (; i < remain.length(); ++i) {
        if (remain[i] == '{') {
          break;
        }
      }
      if (i == remain.length()) {
        forout += remain;
        pointer = format.length() + 2;
        os << forout;
      }
    }

    return *this;
  }
};

//// Powered by GPT

// 对于STL的使用更美
// 不足之处，一样得特判模版函数为string, char*的情况！！！

class FormatOStream {
 private:
  std::ostream& os_;
  std::string fmt_;
  bool valid_;
  size_t required_args_;
  std::vector<std::string> args_;
  bool done_;

  void output() {
    std::vector<std::string> parts;
    size_t start = 0;
    size_t pos = 0;

    while (true) {
      pos = fmt_.find("{}", start);
      if (pos == std::string::npos) {
        parts.push_back(fmt_.substr(start));
        break;
      }
      parts.push_back(fmt_.substr(start, pos - start));
      start = pos + 2;
    }

    std::string result;
    for (size_t i = 0; i < args_.size(); ++i) {
      result += parts[i];
      result += args_[i];
    }
    if (!parts.empty()) {
      result += parts.back();
    }
    os_ << result;
  }

 public:
  FormatOStream(const std::string& fmt, std::ostream& os)
      : os_(os), fmt_(fmt), valid_(true), done_(false) {
    if (!check_valid(fmt_)) {
      valid_ = false;
      done_ = true;
      return;
    }

    required_args_ = 0;
    size_t pos = 0;
    while ((pos = fmt_.find("{}", pos)) != std::string::npos) {
      required_args_++;
      pos += 2;
    }

    if (required_args_ == 0) {
      os_ << fmt_;
      done_ = true;
    }
  }

  template <typename T>
  FormatOStream& operator<<(const T& value) {
    if (!valid_ || done_) {
      return *this;
    }

    std::stringstream os;
    os << value;
    args_.push_back(os.str());

    if (args_.size() == required_args_) {
      output();
      done_ = true;
    }

    return *this;
  }
};

//
int main() {
  cout << "Basic Test:" << endl;
  {
    auto f1 = FormatOStream("Hello, {}!\n", cout);
    f1 << "World";

    auto f2 = FormatOStream("Hello, {} and {}!\n", cout);
    f2 << "C++" << "STL";

    auto f3 = FormatOStream("Hello, {}, {} and {}!\n", cout);
    f3 << 42 << 'w' << 3.14;

    std::string buf;
    int x0;
    double x1;
    std::string x2;
    std::complex<double> x3;
    std::getline(cin, buf);
    buf.push_back('\n');
    cin >> x0 >> x1 >> x2 >> x3;
    cin.get();
    auto f4 = FormatOStream(buf, cout);
    f4 << x0 << x1 << x2 << x3;
  }
  cout << endl;

  cout << "Argument Number Test:" << endl;
  {
    auto f1 =
        FormatOStream("This message shouldn't appear at stdout {} {} {}", cout);
    f1 << "1st arg" << "2nd arg";

    auto f2 = FormatOStream("I am from {}!\n", cout);
    f2 << "PKU" << "THU";  // 2nd argument should be ignored

    auto f3 = FormatOStream("May the Force be with you.\n", cout);
    f3 << "Luke Skywalker" << "Darth Vader";  // All arguments should be ignored

    std::string buf;
    std::getline(cin, buf);
    buf.push_back('\n');
    auto f4 = FormatOStream(buf, cout);
    // 使用 Ctrl+Z 来输入一个 EOF, 进而使 cin 流失效，退出此循环。
    // while (cin >> buf) f4 << buf;
  }
  cout << endl;

  cout << "Generic Ostream Test:" << endl;
  {
    auto oss = std::ostringstream();
    auto f1 = FormatOStream("Name: {}\nSignature: {}\n", oss);
    f1 << "Alice" << "Crazy Thursday vivo 50";
    cout << oss.str();

    auto ss = std::stringstream();
    auto f3 = FormatOStream("{}, {}\n", ss);
    f3 << "FACE THE FEAR";
    ss << "Lobotomy Corporation: ";
    f3 << "BUILD THE FUTURE";
    cout << ss.str();
  }
  cout << endl;

  cout << "Robust Test:" << endl;
  {
    // 下面的代码用于创建一个随机数数组，你不用关心具体实现
    srand(std::time(0));
    auto random_numbers = std::vector<int>();
    random_numbers.resize(4);
    for (auto i = 0; i < 4; ++i) random_numbers[i] = rand();

    std::vector<const char*> bad_texts = {
        "{} Incomplete brace is not allowed {",
        "{} Incomplete brace is not allowed }",
        "{{}} Nothing could appear inside brace",
        "{>_<} Nothing could appear inside brace",
    };

    for (auto i = 0; i < 4; ++i) {
      cout << "Testing " << i << "..." << endl;
      auto f = FormatOStream(bad_texts[i], cout);
      f << random_numbers[i];
    }
  }
}

// 下面的代码是辅助函数的具体实现，你并不需要了解其中的细节
enum class ParserStatus {
  NORMAL,
  LEFTBRACE,
};

bool check_valid(const std::string& input) {
  auto status = ParserStatus::NORMAL;
  for (auto c : input) {
    if (status == ParserStatus::NORMAL) {
      if (c == '{')
        status = ParserStatus::LEFTBRACE;
      else if (c == '}')
        return false;
    } else if (status == ParserStatus::LEFTBRACE) {
      if (c == '}')
        status = ParserStatus::NORMAL;
      else
        return false;
    }
  }
  return status == ParserStatus::NORMAL;
}
