#pragma once
#include <memory>
#include <mutex>


using namespace std;
template <typename T>
class Singleton {
public:
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;
    Singleton& operator=(const Singleton<T>& st) = delete;

    static std::shared_ptr<T> _instance;
    static std::once_flag s_flag;
public:
    static std::shared_ptr<T> GetInstance() {
        std::call_once(s_flag, []() {
            _instance = make_shared<T>();
            });

        return _instance;
    }
    ~Singleton() {

    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;
template <typename T>
std::once_flag Singleton<T>::s_flag ;
