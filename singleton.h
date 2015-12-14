#ifndef SINGLETON_H_
#define SINGLETON_H_

template <class T>
class Singleton {
public:
    static inline T& getInstance() {
        if(!g_pInstance){
            g_pInstance = new T;
        }
        return *g_pInstance;
    }
    static inline T& destroyInstance() {
        if(g_pInstance)
            delete g_pInstance;
        g_pInstance = nullptr;
    }
protected:
    static T* g_pInstance;
    Singleton() {};
};

template<class T> T* Singleton<T>::g_pInstance = nullptr;
#endif // SINGLETON_H_
