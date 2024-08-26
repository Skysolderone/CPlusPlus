#include <iostream>
#include <dlfcn.h>
int main()
{
    void *handle = dlopen("./libexample.so", RTLD_LAZY);
    if (!handle)
    {
        std::cout << "open so failed" << std::endl;
        return 1;
    }
    dlerror();
    // load
    typedef void (*hello_func)();
    hello_func hello = (hello_func)dlsym(handle, "hello");
    const char *dlsym_error = dlerror();
    if (dlsym_error)
    {
        std::cerr << "cannot load symbol 'hello' :" << dlsym_error << '\n';
        dlclose(handle);
        return 1;
    }
    // use
    hello();
    dlclose(handle);
    return 0;
}
// g++ -o main main.cpp -ldl