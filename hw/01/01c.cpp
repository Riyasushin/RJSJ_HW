#include <iostream>
using std::cin, std::cout, std::endl;
int n;
int m;
const int x1 = 1;
const int x2 = 2;
const int& r{n};
const int* v1 = &x1;
int* const v2 = &m;
int main(){
    cin >> n >> m;
    n = 2 * n;
    v1 = &x2;
    *v2 = m + 1;
//
    cout << r << " " << (*v1) << " " << (*v2) << endl;
}

/*
const int* v1; 指针指向对象可变，不能用指针修改这对象

int* const v2; 可以通过该变量修改指向的内容，但指针变量本身是只读的(不能指向别人)
*/