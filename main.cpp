#include <iostream>
#include "Buffer/Buffer.h"

int main(int, char **)
{
    std::cout << "Hello, world!\n";

    Buffer *mBuffer = new Buffer();

    int x = (mBuffer)->getMaxSizeInBytes();

    std::cout << std::endl
              << std::to_string(x) << std::endl;
}
