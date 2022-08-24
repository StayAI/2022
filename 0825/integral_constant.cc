#include <iostream>

struct getConstSize {
    static const int value1 = 1;
};

// template<typename T>
struct getConstSize2 : std::integral_constant<int, 2> {};

struct getConstSize3 : std::integral_constant<int, 3> {};

template <typename T, T v>
struct integral_constant {
    static const T value = v;
    typedef T value_type;
    typedef integral_constant<T, v> type;
    operator value_type() { return value; }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

struct getConstSize4 : integral_constant<int, 4> {
 public:
    int get(int i) {
        if (i >= value) {
            throw std::logic_error("error");
        }
        std::cout << value << std::endl;
        return a[i];
    }

 private:
    int a[value]{1, 2, 3, 4};
};

int main(int argc, char** argv) {

    std::cout << "-----------------" << std::endl;
    std::cout << "helloworld" << std::endl;
    std::cout << getConstSize::value1 << std::endl;
    std::cout << getConstSize2::value << std::endl;
    std::cout << getConstSize3::value << std::endl;
    std::cout << getConstSize4::value << std::endl;

    getConstSize4 test;

    std::cout << test.get(2) << std::endl;
    std::cout << test.value << std::endl;
    // std::cout << test.get(4) << std::endl;

    std::cout << true_type::value << std::endl;

    true_type::type test2;
    // test2.value = false;
    std::cout << test2.value << std::endl;


    return 0;
}
