class Widget {
 public:
    Widget(Widget&& param) : str(std::move(param.str)), p(std::move(param.p))
    {}

 private:
    std::string str;
    std::shared_ptr<SomeOthreStruct> p;
};

class Widget {
 public:
    template <typename T>
    explicit Widget(T&& param) {
        str = std::forward<T>(param.str);
    }

 private:
    std::string str;
    std::shared_ptr<SomeOtherStruct> p;
};

#include <iostream>

class Widget {
 public:
    template <typename T>
    explicit Widget(T&& newName) {
        name = std::move(newName);
    }

    template <typename T>
    void setName(T&& newName) {
        name = std::move(newName);  // 错误的使用，应该使用std::forward<T>
    }

    std::string getName() { return name; }

 private:
    std::string name;
};

std::string returnName() { return std::string("name"); }

Widget test() {
    auto name = returnName();
    Widget w{"test"};
    w.setName(name);
    w.setName("123");
    std::cout << w.getName() << std::endl;
    std::cout << name << std::endl;
    return w;
}

int main(int argc, char** argv) {

    test();
    return 0;
}

#include <iostream>

class Widget {
 public:
    Widget() { std::cout << "moren" << std::endl; }

    explicit Widget(const std::string& newName) {
        name = newName;
        std::cout << "cosnt con" << std::endl;
    }

    explicit Widget(std::string&& newName) {
        name = std::move(newName);
        std::cout << "move con" << std::endl;
    }
    virtual ~Widget() { std::cout << "des" << std::endl; }

    void setName(const std::string& newName) { name = newName; }
    void setName(std::string&& newName) { name = std::move(newName); }

 private:
    std::string name;
};

int main(int argc, char** argv) {
    Widget w{"name"};
    std::string str = "123";
    w.setName(str);

    return 0;
}
