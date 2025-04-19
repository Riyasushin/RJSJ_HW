#include <iostream>
// 在此处补充你的代码

class Callable {

public:
    virtual void call() = 0;

    virtual ~Callable() = default;
};

template<typename F>
class FuncWrapper : public Callable {
private:
    F f;
public:
    FuncWrapper(F funcname) : f(funcname) {
        
    }
    void call() override {
        f();
    }

    ~FuncWrapper() override = default;
};

class Function {

private:
    Callable* c;
public:
    template<typename Func>
    Function(Func f) {
        c = new FuncWrapper<Func>(f);
    }

    void operator() () const {
        c->call();
    }

    ~Function() {
        delete c;
    }

};



void f1() {
    std::cout << "f1" << std::endl;
}
struct F2 {
    void operator()() {
        std::cout << "f2" << std::endl;
    }
};
F2 f2;
int main() {
    int v = 3;
    auto f3 = [&]() {
        std::cout << "f" << v << std::endl;
    };
    
    Function funcs[]{f1, f2, f3};

    for (int i = 0; i < 3; i++) {
        funcs[i]();
    }
}