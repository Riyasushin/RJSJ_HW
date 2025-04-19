#include <iostream>

bool error = false;

class Person {
  int age_;

 public:
  Person(int age) : age_{age} {}
  Person(const Person& another) : age_{another.age_} {}
  Person& operator=(const Person& another) {
    // 复制代价低，省略自赋值判断。
    age_ = another.age_;
    return *this;
  }
  virtual Person& Clone(const Person& another) { return operator=(another); }
  int GetAge() const { return age_; }
  virtual ~Person() = default;
};

class Student : public Person {
  int studentID_;

 public:
  Student(int age, int studentID) : Person{age}, studentID_{studentID} {}

  int GetID() const { return studentID_; }
  ///
  Student(const Student& another)
      : Person{another}, studentID_{another.studentID_} {}
  Student& operator=(const Student& another) {
    Person::operator=(another);  /// ！！！！
    studentID_ = another.studentID_;
    return *this;
  }
  virtual Person& Clone(const Person& another) override {
    if (dynamic_cast<const Student*>(&another) == nullptr) {
      error = true;
      return *this;
    } else {
      return operator=(dynamic_cast<const Student&>(another));
    }
  }
  ///
};

int main() {
  const Person person{35};
  Student student{15, 10086};

  {  // 测试Student之间的复制
    Student student2{student};
    std::cout << student2.GetAge() << " " << student2.GetID() << "\n";
    Student student3{13, 10085};
    student2 = student3;
    std::cout << student2.GetAge() << " " << student2.GetID() << "\n";
  }

  {  // 测试Student向Person的复制和Clone
    Student student3{13, 10085};

    Person& studentRef = student;
    studentRef = student3;

    std::cout << student.GetAge() << " " << student.GetID() << "\n";
    studentRef.Clone(student3);
    std::cout << student.GetAge() << " " << student.GetID() << "\n";
  }

  {  // 测试错误复制
    std::cout << error << "\n";
    student.Clone(person);
    std::cout << student.GetAge() << " " << student.GetID() << "\n";
    std::cout << error << "\n";
  }

  return 0;
}

/*
如果一个基类引用实际上引用的是一个子类对象，对这个基类引用使用另一个子类对象进行赋值，
则不会发生完整的子类到子类的赋值，而是只会发生基类间的赋值。
由于发生了不完整的成员复制，仿佛是从完整的类中切下一片，因此被称为切片问题（Slicing
problem）。 完成 Student 类的复制构造函数、复制赋值运算符重载和 Clone
成员函数，使程序获得符合预期的输出。当子类尝试 Clone
的对象并不是真正的子类对象时，将全局变量 error 置为 true。


typeid不能体现继承链 C is a B
*/
