#ifndef BUTTON_FUNCTION_INCLUDE
#define BUTTON_FUNCTION_INCLUDE

#include <functional>

class ButtonFunction
{
public:
    virtual void call() = 0;
};


template<typename T>
class ClassFunc : public ButtonFunction
{
public: 
    ClassFunc(std::function<void(T*)> t_func, T* t_caller) :
        m_func(t_func),
        m_caller(t_caller)
        {
        }

    virtual void call()override
    {
        if (m_caller != nullptr && m_func != nullptr)
        {
            m_func(m_caller);
        }
    }
private:
    std::function<void(T*)> m_func;
    T* m_caller;
};

#endif