#include <vector>
#include <algorithm>

class Observer
{
public:
    virtual void update() = 0;
};
class Subject
{
private:
    std::vector<Observer *> observers;

public:
    void attach(Observer *observer)
    {
        observers.push_back(observer);
    }
    void notify()
    {
        std::for_each(observers.begin(), observers.end(), [](Observer *observer)
                      { observer->update(); });
    }
};

class ConctateObserverA : public Observer
{
public:
    void update() override {}
};
class ConctateObserverB : public Observer
{
public:
    void update() override {}
};