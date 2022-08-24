// Copyright [2022] <Copyright StayAl>
#include <iostream>

template <typename T>
class Singleton {
 public:
    template <typename... Args>
    static T* InitInstance(Args&&... args) {
        if (m_pInstance == nullptr) {
            m_pInstance = new T(std::forward<Args>(args)...);
        }
        return m_pInstance;
    }

    static T* GetInstance() {
        if (m_pInstance == nullptr) {
            throw std::logic_error("GetInstance error!!!");
            // std::cout << "GetInstance error!!!" << std::endl;
        }
        return m_pInstance;
    }

    static void DestorySingleton() {
        delete m_pInstance;
        m_pInstance = nullptr;
    }

 private:
    Singleton(void);
    virtual ~Singleton(void);
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

 private:
    static T* m_pInstance;
};

class A {
 public:
    explicit A(int a) { this->a = a; }
    void print() { std::cout << "a = " << a << std::endl; }

 private:
    int a;
};

class B {
 public:
    explicit B(const std::string& str) { this->str = str; }
    void print() { std::cout << str << std::endl; }

 private:
    std::string str;
};

class C {
 public:
    explicit C(int a, int b) {
        this->a = a;
        this->b = b;
    }
    void print(

    ) {
        std::cout << "a = " << a << " b = " << b << std::endl;
    }

 private:
    int a;
    int b;
};

template <class T>
T* Singleton<T>::m_pInstance = nullptr;

int main(int argc, char** argv) {
    std::cout << "hello singleton!" << std::endl;

    // Singleton<A>::GetInstance()->print();
    Singleton<A>::InitInstance(3);
    Singleton<A>::GetInstance()->print();
    Singleton<A>::DestorySingleton();

    Singleton<B>::InitInstance("string test");
    Singleton<B>::GetInstance()->print();
    Singleton<B>::DestorySingleton();

    Singleton<C>::InitInstance(2, 4);
    Singleton<C>::GetInstance()->print();
    Singleton<C>::DestorySingleton();

    return 0;
}
