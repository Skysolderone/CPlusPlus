#include <iostream>
class IA
{
public:
    virtual void doSomething() = 0;
};
class IB
{
public:
    virtual void doSomething() = 0;
};

class A : public IA
{
public:
    void doSomething() override {}
    void doSomethingWithB(IB &b)
    {
        b.doSomething();
    };
};
class B : public IB
{
public:
    void doSomething() override {}
    void doSomethingWithB(IA &a)
    {
        a.doSomething();
    };
};