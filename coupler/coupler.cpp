#include <iostream>

// 双向耦合
class B;
class A
{
public:
    void doSomeThingWithB(B &b);
};
class B
{
public:
    void doSomeThingWithA(A &a);
};


