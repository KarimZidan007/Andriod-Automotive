#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
unsigned int size;
unsigned int size_c;

namespace DynamicAlloc
{

    void Create_2D(int ***arr)
    {

        std::cout << "Enter Number of Rows" << std::endl;
        std::cin >> size;
        std::cout << "Enter Number of Columns" << std::endl;
        std::cin >> size_c;

        *arr = new int *[size];

        for (int i = 0; i < size; i++)
        {

            (*arr)[i] = new int[size_c];
        }
        // fill array

        for (int i = 0; i < size; i++)
        {
            for (int x = 0; x < size_c; x++)
            {
                unsigned char random = rand() % 10000000;
                (*arr)[i][x] = random;
            }
        }
    }
    void Delete_2D(int ***arr)
    {
        for (int i = 0; i < size_c; i++)
        {
            delete[] (*arr)[i];
        }

        delete[] *arr;
    }

}
namespace NEW = DynamicAlloc;

int main()
{
    int **arr = nullptr;

    NEW::Create_2D(&arr);

    std::cout << arr[1][3] << std::endl;
    std::cout << arr[2][1] << std::endl;
    std::cout << arr[1][2] << std::endl;
    NEW::Delete_2D(&arr);

    return 0;
}
