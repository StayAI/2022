void f(Widget&& param);

Widget&& w = Widget();

template <typename T>
void Widget(std::vector<T>&& param) {}

template <typename T>
void Widget(const T&& param);

// 万能引用，都涉及到了型别推导
auto&& val1 = val2;

template <typename T>
void Widget(T&& param) {}

Widget w;
Widget(w);
Widget(std::move(w));

template <typename T>
void f(std::vector<T>&& param) {}

std::vector<int> vec;
f(vec);  // error

template <class T, class Allocator = allocator<T>>
class vector {
 public:
    void push_back(T&& param) {}

    template <typename... Args>
    void emplace_bakc(Args&&... args) {}
};

template <class Widget, class Allocator = allocator<Widget>>
class vector {
 public:
    void push_back(Widget&& param) {}

    template <typename... Args>
    void emplace_back(Args&&... args) {}
};

auto timeFuncInvocation = [](auto&& func, auto&&... param) {
    // start
    std::forward<decltype(func)>(func)(std::forward<param>(param)...);
    // end
}