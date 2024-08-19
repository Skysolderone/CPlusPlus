#include <iostream>

void memcopy(void *dest, const void *src, size_t size)
{
    char *destPtr = static_cast<char *>(dest);
    const char *srcPtr = static_cast<const char *>(src);
    for (size_t i = 0; i < size; ++i)
    {
        destPtr[i] = srcPtr[i];
    }
}
int main()
{
    int sourc[] = {1, 2, 3, 4, 5};
    int destinstance[5];
    memcopy(destinstance, sourc, sizeof(sourc));
    for (const auto &element : destinstance)
    {
        std::cout << element << " ";
    }
    return 0;
}