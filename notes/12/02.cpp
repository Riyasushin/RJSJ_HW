
/*
文件读写
*/

#include <fstream>

void function01()
{
  std::ofstream fout;
  fout.open("work.dat", std::ios::out);

  //
  std::ofstream outFile("clients.dat", std::ios::out); // 打开文件
}

void function02()
{

  std::ofstream fout("a1.out", std::ios::ate);
  long location = fout.tellp(); // 取得写指针的位置
  location = 10L;
  fout.seekp(location);                // 将写指针移动到第10个字节处
  fout.seekp(location, std::ios::beg); // 从头数location
  fout.seekp(location, std::ios::cur); // 从当前位置数location
  fout.seekp(location, std::ios::end); // 从尾部数location
  // location 可以为负值
  // istream类对象的读指针函数seekg()用法也类似
}

/*
- 流对象提供close成员函数用于关闭文件
- 几乎任何情形都不需要手动调用流对象的close成员函数
- 尽管部分教材可能会要求这样做，但这是完全没有必要的，因为文件的关闭操作会在std::*fstream 的析构函数中自动完成，无需任何手动处理
*/

// char 读写
#include <iostream>
#include <algorithm>
#include <vector>
void function03()
{
  std::vector<int> v;
  std::ifstream srcFile("in.txt", std::ios::in);
  std::ofstream destFile("out.txt", std::ios::out);
  int x;
  while (srcFile >> x)
    v.push_back(x);
  std::sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++)
    destFile << v[i] << " ";
}

// 二进制直接写
struct Student
{
  char name[20];
  int score;
};
void function04()
{
  Student s;
  std::ofstream outFile("students.dat", std::ios::out | std::ios::binary);
  while (std::cin >> s.name >> s.score)
    outFile.write((char *)&s, sizeof(s)); // 直接把二进制的字节当作字符写进去了
}

// 读+写
#include <cstring>
void function05()
{
  Student s;
  std::fstream iofile("students.dat", std::ios::in | std::ios::out | std::ios::binary);
  if (!iofile)
  {
    std::cout << "error";
    return;
  }
  iofile.seekp(1 * sizeof(s), std::ios::beg); // 定位写指针到第3个记录
  iofile.write("Mike", strlen("Mike"));
  iofile.seekg(0, std::ios::beg); // 定位读指针到开头
  while (iofile.read((char *)&s, sizeof(s)))
    std::cout << s.name << " " << s.score << std::endl;
}

int main()
{
  function04();
  function05();
  return 0;
}