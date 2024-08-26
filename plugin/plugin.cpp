#include <iostream>

extern "C" void hello()
{
    std::cout << "hello,shared library" << std::endl;
}

// complier :g++ -fPIC -shared -o libexample.so example.cpp
//`-fPIC`：生成位置无关代码（Position Independent Code），这对于共享库是必需的。
//`-shared`：指示编译器生成共享库。
//`-o libexample.so`：指定输出文件名。