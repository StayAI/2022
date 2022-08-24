#include <iostream>

class A {
 public:
    static int get() { return 0; }
};

class B {
 public:
    static const char* get() { return "a"; }
};

template <class T>
void Func() {
    auto a = T::get();
    std::cout << a << std::endl;
}

int main(int argc, char** argv) {

    std::cout << "----------------------" << std::endl;
    Func<A>();
    Func<B>();
    std::cout << "hello world" << std::endl;

    return 0;
}
