#include "my_vector.h"
#include <iostream>
int main()
{
    MyVector<int> v2;
    v2.reserve(1000000);
    for (int i = 0; i < 1000000; ++i)
        v2.push_back(i);
    return 0;
}