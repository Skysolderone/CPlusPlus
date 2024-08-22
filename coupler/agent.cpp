class Mediator
{
public:
    virtual void communicateAtoB() = 0;
    virtual void communicateBtoA() = 0;
};
class ConcrateMediator : public Mediator
{
private:
    A *a;
    B *b;

public:
    ConcrateMediator(A *a, B *b) : a(a), b(b) {}
    void communicateAtoB() override
    {
        b->doSomethingElse();
    }
    void communicateBtoA() override
    {
        a->doSomethingElse();
    }
};

class A
{
private:
    Mediator *mediator;

public:
    A(Mediator *mediator) : mediator(mediator) {}
    void doSomethingElse() {}
    void doSomethingWithB()
    {
        mediator->communicateAtoB();
    }
};
class B
{
private:
    Mediator *mediator;

public:
    B(Mediator *mediator) : mediator(mediator) {}
    void doSomethingElse() {}
    void doSomethingWithA()
    {
        mediator->communicateBtoA();
    }
};