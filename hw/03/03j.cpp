#include <cassert>
#include <iostream>

struct A {
    A() = default;
    A(const A& other) {
        std::cout << "Copy A\n";
    }
};

struct B {
    A* a;
    B() : a{new A{}} {}
    B(const B& other) : a{new A(*other.a)} {}
//
    B(B&& other) : a{other.a} {
        other.a = nullptr;
    }
//
    ~B() {
        delete a;
    }
};

struct C {
    B b;
};

int newCount;

int main() {
    newCount = 0;
    {
        B b;
        B b_copied(b);
        assert(b_copied.a != nullptr);
    }
    std::cout << "---\n";
    assert(newCount == 0);

    {
        B b_moved(C{}.b);
        assert(b_moved.a != nullptr);
    }
    std::cout << "---\n";
    assert(newCount == 0);
}

// 以下是内存分配计数实现，不用管
void* operator new(std::size_t size) {
    if (void* ptr = std::malloc(size)) {
        newCount++;
        return ptr;
    }
    throw std::bad_alloc{};
}
void operator delete(void* ptr, std::size_t) noexcept {
    if (ptr) {
        std::free(ptr);
        newCount--;
    }
}

/*
移动语义
*/
