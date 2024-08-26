#include <iostream>
class LazyLoad
{
public:
    LazyLoad() : data(0), isLoaded(false) {}
    // const成员函数，但由于data是mutable，我们可以在这里修改它
    int getData() const
    {
        if (!isLoaded)
        {
            data = loadData();
            isLoaded = true;
        }
        return data;
    }

private:
    mutable int data;
    mutable bool isLoaded;
    int loadData() const
    {
        return 42;
    }
};

int main()
{
    const LazyLoad ll;
    std::cout << "Data:" << ll.getData() << std::endl;
    return 0;
}