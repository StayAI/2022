#include <iostream>

class A {
 public:
    static int get() { return 0; }
};

class B {
 private:
    /* data */
 public:
    B(/* args */);
    ~B();
    static const char* get() { return "a"; }
};

template <class T>
void Func() {
    auto a = T::get();
    std::cout << a << std::endl;
}

B::B(/* args */) {}

B::~B() {}

int main(int argc, char** argv) {

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "hello simple auto" << std::endl;
    Func<A>();
    Func<B>();

    return 0;
}
