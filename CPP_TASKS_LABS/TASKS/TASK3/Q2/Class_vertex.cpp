#include <iostream>
#include <cstdlib>
#include "class_vertex.hpp"
int main()
{
    Vertex Obj[5];
    for (int i = 0; i < 5; i++)
    {
        Obj[i].fill_rand();
    }
    auto element = Obj[0].get_x();
    for (int i = 0; i < 5; i++)
    {
        auto element_x = Obj[i].get_x();
        auto element_y = Obj[i].get_y();
        std::cout << "X OF POINT " << i << " : ->" << element_x << std::endl;
        std::cout << "Y OF POINT " << i << " : ->" << element_y << std::endl;
    }
    return 0;
}
