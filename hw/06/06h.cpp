#include <iostream>
// 在此处补充你的代码

class RangeIterator {
    private:
        int index;
        const int step;
        
    public:
        inline bool operator==(const RangeIterator& oth) const {
            return index == oth.index;
        }
        inline bool operator!=(const RangeIterator& oth) const {
            return !(*this == oth);
        }
        inline bool operator<(const RangeIterator& oth) const {
            if (step > 0) {
                return index < oth.index;
            } else {
                return index > oth.index;
            }
            /// TODO
        }
    
        inline int& operator*() {
            return index;
        }
    
        inline RangeIterator& operator++() {
            index += step;
            return *this;
        }
    
        RangeIterator(int _step, int _index) : step(_step), index(_index) {}
    
    };
    

class RangeLocation {
private:
    int st;
    int ed;
    int step;


public:
    RangeIterator begin() const {
        return RangeIterator(step, st);
    }

    RangeIterator end() const {
        return RangeIterator(step, ed);
    }

    RangeLocation(int st, int ed, int sp) : st(st), ed(ed), step(sp) {}

    
};

inline RangeLocation range(const int st, int ed, int step = 1) {
    // if (st > ed && step == 1) {
    //     step = -1;
    // }
    if (step > 0) {
        if (st >= ed) {
            ed = st;
        } else {
            int gap = ed - st;
            if (gap % step != 0)
                ed -= gap % step - step;
            
        }
    } else if (step < 0) {
        if (st <= ed) {
            ed = st;
        } else {
            int gap = st - ed;
            if (gap % (0 - step) != 0)
                ed += (gap % (0 - step)) + step;
        }
    }
    return RangeLocation(st, ed, step);
}

int main() {
    for (int i : range(0, 10)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i : range(1, 20, 2)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i : range(10, 0, -3)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i : range(10, 0)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// 请不要使用任何标准库容器。
#if defined(_GLIBCXX_VECTOR) || defined(_GLIBCXX_DEQUE) || defined(_GLIBCXX_FORWARD_LIST) || \
    defined(_GLIBCXX_LIST)
#error Do not use standard library containers.
#endif