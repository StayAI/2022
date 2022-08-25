void f(Widget&& w);

template <typename T>
typename std::remove_reference<T>::type&& move(T&& param) {
    using ReturnType = typename std::remove_reference<T>::type&&;
    return static_cast<ReturnType>(param);
}

template <typename T>
decltype(auto) move(T&& param) {
    using ReturnType = remove_reference_t<T>&&;
    return static_cast<ReturnType>(param);
}

class Annotation {
 public:
    explicit Annotation(const std::string text) : value(text) {}

 private:
    std::string value;
};

class Annotation {
 public:
    explicit Annotation(const std::string text) : value(std::move(text)) {}

 private:
    std::string value;
};

class string {
 public:
    string(const string& str) {}
    string(string&& str) {}
}

template <typename T>
decltype(auto) move(T&& param) {
    using ReturnType = remove_reference_t<T>&&;
    return static_cast<ReturnType>(param);
}

void process(const Widget& lvalArg) {}
void process(Widget&& rvalArg) {}

template <typename T>
void logAndProcess(T&& args) {
    auto now = std::chrono::system_clock::now();
    process(std::forward<T>(args));
}

Widget w;
logAndProcess(w);
logAndProcess(std::move(w));

template <typename T>
void logAndProcess(T&& param) {
    auto now = std::chrono::system_clock::now();
    process(std::forward<T>(param));
}

Widget w;
process(const Widget& w);
process(Widget&& w);

Widget w;
logAndProcess(w);
logAndProcess(std::move(w));

class Widget {
 public:
    Widegt(Widget&& rhs) : value(std::move(rhs.s)) { ++number; }

 private:
    std::string value;
    static std::size_t number;
};

class Widget {
 public:
    Widget(Widget&& rhs) : s(std::forward<std::string>(rhs.s)) { ++number; }

 private:
    std::string s;
    std::size_t number;
};
