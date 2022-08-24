#include <iostream>

template <typename T>
class Singleton {
 public:
    template <typename... Args>
    static T* InitSingleton(Args&&... args) {
        if (m_pSingleton == nullptr) {
            m_pSingleton = new T(std::forward<Args>(args)...);
        }
        return m_pSingleton;
    }

    static T* GetInstance() {
        if (m_pSingleton == nullptr) {
            throw std::logic_error("error");
        }
        return m_pSingleton;
    }

    static void DestoryInstance() {
        delete m_pSingleton;
        m_pSingleton = nullptr;
    }

 private:
    Singleton(void);
    virtual ~Singleton();
    explicit Singleton(const Singleton&);
    T* operator=(const Singleton&);

 private:
    static T* m_pSingleton;
};

class A {
 public:
    explicit A(int a) { this->a = a; }
    void print() { std::cout << this->a << std::endl; }

 private:
    int a;
};

class B {
 public:
    explicit B(const std::string& a) { this->a = a; }
    void print() { std::cout << this->a << std::endl; }

 private:
    std::string a;
};

class C {
 public:
    C(const std::string& a, int b) {
        this->a = a;
        this->b = b;
    }
    void print() { std::cout << this->a << "  " << this->b << std::endl; }

 private:
    std::string a;
    int b;
};

template <class T>
T* Singleton<T>::m_pSingleton = nullptr;

int main(int argc, char** argv) {
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "hello singleton" << std::endl;

    // Singleton<A>::GetInstance()->print();
    Singleton<A>::InitSingleton(2);
    Singleton<A>::GetInstance()->print();
    Singleton<A>::DestoryInstance();

    Singleton<B>::InitSingleton("sssssss");
    Singleton<B>::GetInstance()->print();
    Singleton<B>::DestoryInstance();

    Singleton<C>::InitSingleton("aaaaaaa", 2);
    Singleton<C>::GetInstance()->print();
    Singleton<C>::DestoryInstance();

    return 0;
}
