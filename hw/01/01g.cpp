#include <iostream>
using std::cin, std::cout, std::endl;
int main(){
    int n, x, y, z;
    cin >> n;
    cin >> x >> y >> z;
    int* a = new int[n];
    int* b = new int[n];
    int* c = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    auto f = [=](int &i, int &j, int &k) -> int {
        auto judge = [](int& x) { x = x < 60 ? 0 : x;};
        judge(i);
        judge(j);
        judge(k);
        return (double)(i*x + j*y + k*z) / (x + y + z) + 0.5;
    }
    ;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << b[i] << " " << c[i] << " ";
        int tot = f(a[i], b[i], c[i]);
        cout << a[i] << " " << b[i] << " " << c[i] << " " << tot << endl;
    }
    delete[] a;
    delete[] b;
    delete[] c;
}

/*
lambda 的写法，捕获列表，参数，返回值
*/